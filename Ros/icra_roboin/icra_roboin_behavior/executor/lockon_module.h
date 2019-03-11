#ifndef ICRA_ROBOIN_BEHAVIOR_LOCKON_MODULE_H
#define ICRA_ROBOIN_BEHAVIOR_LOCKON_MODULE_H

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "../tools.h"

namespace icra_roboin_behavior {

class LockonModule {
    public:
        LockonModule(double dt = 0.1): dt_(dt){
            ros::NodeHandle nh;
            sub_ = nh.subscribe("nav_cmd_vel",1,&LockonModule::CB,this);
            pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
        }
        ~LockonModule() = default;
        void SetTargetAngularVelocity(double target) {
            target_angular_velocity_ = target;
        }
        void SetTargetAngle(double target){
            target_angle_ = target;
            ROS_INFO("target angle: %f",target);
            if(target > 0.1 | target < -0.1){
                SetTargetAngularVelocity( icra_roboin_behavior::tools::Clip(3*target_angle_,-3.0,3.0) );
            } else {
                SetTargetAngularVelocity(0);
            }
            ///need PID control
        }
    private:
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
        double target_angle_;
        double target_angular_velocity_; //rad/sec
        double dt_;
};
        



}

#endif