#ifndef ICRA_ROBOIN_BEHAVIOR_LOCKON_MODULE_H
#define ICRA_ROBOIN_BEHAVIOR_LOCKON_MODULE_H

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "../tools.h"

namespace icra_roboin_behavior {



class LockonModule {
    public:
        LockonModule(Blackboard*& blackboard,
                    double dt = 0.1,double sentinel_angle=0.7854): 
                                                            dt_(dt),blackboard_(blackboard),sentinel_angle_(sentinel_angle)
        {
            ros::NodeHandle nh;
            sub_ = nh.subscribe("omni_cmd_vel",1,&LockonModule::CB,this);
            pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
        }
        ~LockonModule() = default;

        void LockonInterface(const LockonMode mode, const double target){
            switch(mode){
                case LockonMode::ANGULAR_VEL:
                  SetTargetAngularVelocity(target);
                  lockon_mode_ = mode;
                  break;
                case LockonMode::RELATIVE_ANGLE:
                  SetTargetAngle(target);
                  lockon_mode_ = mode;
                  break;
                case LockonMode::RELATIVE_ANGLE_SENTINEL:
                  SetTargetAngleSentinelMode(target);
                  lockon_mode_ = mode;
                  break;              
                case LockonMode::GLOBAL_YAW:
                  SetTargetGlobalYaw(target);
                  lockon_mode_ = mode;
                  break;
                case LockonMode::GLOBAL_YAW_SENTINEL:
                  SetTargetGlobalYawSentinelMode(target);
                  lockon_mode_ = mode;
                  break;
                default:
                    throw std::invalid_argument( "wrong lockon mode" );
                    ROS_ERROR("LockonModule error: wrong lockon mode");
                                  
            } 
        }

        void LockonInterface(const LockonMode mode, const PlayerType who){
            SetTargetEnemy(who);
        }

        LockonMode GetLockonMode() const {
            return lockon_mode_;
        }


    private:
        void SetTargetAngularVelocity(double target) {
            target_angular_velocity_ = target;
        }
        void SetTargetAngle(double target){
            target_angle_ = target;
            ROS_INFO("target angle: %f",target);
            if(target > 0.1 | target < -0.1){
                SetTargetAngularVelocity( tools::Clip(2*target_angle_,-3.0,3.0) );
            } else {
                SetTargetAngularVelocity(0);
            }
            ///need PID control
        }

        void SetTargetAngleSentinelMode(double target){
            target_angle_ = target;
            ROS_INFO("sentinel target angle: %f",target);

            if(target_angle_ < sentinel_angle_ && target_angle_ > -1* sentinel_angle_){
                if(target/sentinel_angle_ > 0.9  )
                {
                    sentinel_flag_ = -1;
                } else if ( target/sentinel_angle_ < -0.9 ) {
                    sentinel_flag_ = 1;
                }
                ROS_INFO("%f, %f, %f, %f,%f,%d",sentinel_flag_ * cos( 1.570796 * (target/sentinel_angle_) ),target/sentinel_angle_, target,sentinel_angle_,target_angle_,sentinel_flag_ );
                SetTargetAngularVelocity(sentinel_flag_ * cos( 1.570796 * (target/sentinel_angle_) ));
            } else {
                SetTargetAngularVelocity( tools::Clip(2*target_angle_,-3.0,3.0) );
            }
            
        }

        void SetTargetGlobalYaw(double yaw) {
            SetTargetAngle( yaw - (tools::GetYaw(blackboard_->GetMyPose())) );
        }

        void SetTargetGlobalYawSentinelMode(double yaw) {
            SetTargetAngleSentinelMode( yaw - (tools::GetYaw(blackboard_->GetMyPose())) );
        }

        void SetTargetEnemy(PlayerType who){
            if(who == PlayerType::ENEMY_ONE | who == PlayerType::ENEMY_TWO){
                auto enemy_pose = blackboard_->GetEnemyPose(who);
                auto my_pose = blackboard_->GetMyPose();
                SetTargetGlobalYaw( atan2((enemy_pose.pose.position.y - my_pose.pose.position.y), 
                                (enemy_pose.pose.position.x - my_pose.pose.position.x)) );
            } else {
                throw std::invalid_argument( "wrong enemy type" );
                ROS_ERROR("lockon module SetTargetEnemy error: wrong enemy type");
            }
        }






    private:
        Blackboard* const blackboard_;
        ros::Subscriber sub_;
        ros::Publisher pub_;
        void CB(const geometry_msgs::Twist::ConstPtr& msg) {
            double xo = msg->linear.x;
            double yo = msg->linear.y;
            double wo = msg->angular.z;
            double w = target_angular_velocity_;
            double dx,dy,vx,vy;

            if (wo < 0.01 && wo > -0.01){
                dx = dt_*xo;
                dy = dt_*yo;
            } else {
                dx = dt_*xo +( ( std::sin((wo)*dt_) / wo) - dt_);
                dy = dt_*yo + ( (1/(wo)) * (std::cos(dt_*(wo))-1));
            }

            if (w < 0.01 && w > -0.01){
                vx = dx / dt_;
                vy = dy / dt_;
            } else {
                vx=( dx+ dt_ - ( std::sin(dt_*w) / w ) )/dt_;
                vy=( dy - ( ( std::cos(dt_*w)-1 ) / w ) )/dt_;    
            }

            


            geometry_msgs::Twist cmd;
            cmd.linear.x = vx;
            cmd.linear.y = vy;
            cmd.angular.z = w;
            pub_.publish(cmd);
        }
        LockonMode lockon_mode_;
        double target_angle_;
        double target_angular_velocity_; //rad/sec
        const double dt_;
        const double sentinel_angle_;
        int sentinel_flag_ = 1;
};
        



}

#endif