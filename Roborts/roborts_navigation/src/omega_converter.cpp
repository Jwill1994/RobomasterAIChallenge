#include <ros/ros.h>

#include <geometry_msgs/Twist.h>
#include <roborts_msgs/SubBehavior.h>
#include <roborts_msgs/NavStatus.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Pose.h>
#include <move_base_msgs/MoveBaseActionResult.h>

#include <math.h>
#include <tf/tf.h>
#include "pid.h"

#define FREQUENCY 20
#define MAX_OMEGA 2.5
#define PI 3.141592

geometry_msgs::Twist cmd_vel_;
roborts_msgs::NavStatus nav_status_;
double target_omega_;
geometry_msgs::Pose my_pose;
bool is_vel_received = false;
bool is_omega_received = false;
bool arrived = false;
double k, alpha, beta;

MiniPID mini_pid_ = MiniPID(3.0,0.0,0.2);
int last_mode;
float dt;

double trans_vel;

void converterCallback(const geometry_msgs::TwistConstPtr& msg) {
    is_vel_received = true;

    double original_omega = msg->angular.z;

    // If not received target omega or angular velocity is similar each other
    if(!is_omega_received || fabs(original_omega - target_omega_) < 0.04) {
        ROS_INFO("Case 1 : %d", is_omega_received);
        k = 1.0; alpha = 1.0; beta = 0.0;
    } else if (fabs(original_omega) > 0.02 && fabs(target_omega_) < 0.02) {    // target omega is almost zero.
        ROS_INFO("Case 2");
        k = FREQUENCY / original_omega;
        alpha = sin(original_omega / FREQUENCY);
        beta = cos(original_omega / FREQUENCY) - 1;
    } else if (fabs(original_omega) < 0.02 && fabs(target_omega_) > 0.02) {    // current omega is almost zero.
        ROS_INFO("Case 3");
        k = target_omega_ / (2 * FREQUENCY * (1 - cos(target_omega_ / FREQUENCY)));
        alpha = sin(target_omega_ / FREQUENCY);
        beta = 1 - cos(target_omega_ / FREQUENCY);
    } else {        // neither above
        ROS_INFO("Case 4");
        k = target_omega_ / (original_omega * 2 * (1 - cos(target_omega_ / FREQUENCY)));
        alpha = 1 + cos((target_omega_ - original_omega) / FREQUENCY) - cos(target_omega_ / FREQUENCY) - cos(original_omega / FREQUENCY);
        beta = sin((target_omega_ - original_omega) / FREQUENCY) - sin(target_omega_ / FREQUENCY) + sin(original_omega / FREQUENCY);
    }

    ROS_INFO(" K : %f, ALPHA : %f, BETA : %f", k, alpha, beta);
    ROS_INFO("Target Omega: %f", target_omega_);
    // Conversion Matrix
    // |x'| = k * |alpha beta | |x|
    // |y'| =     |-beta alpha| |y|
    cmd_vel_.linear.x = k * (alpha * msg->linear.x + beta * msg->linear.y);
    cmd_vel_.linear.y = k * (-beta * msg->linear.x + alpha * msg->linear.y);
    cmd_vel_.angular.z = is_omega_received ? target_omega_ : original_omega;

    trans_vel = sqrt(pow(cmd_vel_.linear.x, 2) + pow(cmd_vel_.linear.y, 2));
    nav_status_.trans_vel = trans_vel;
}

double GetAngle(const geometry_msgs::Pose &pose1,
                  const geometry_msgs::Pose &pose2) {
    const geometry_msgs::Quaternion quaternion1 = pose1.orientation;
    const geometry_msgs::Quaternion quaternion2 = pose2.orientation;
    tf::Quaternion rot1, rot2;
    tf::quaternionMsgToTF(quaternion1, rot1);
    // tf::quaternionMsgToTF(quaternion2, rot2);
    double r,p,y;
    tf::Matrix3x3 mat1(rot1);
    // tf::Matrix3x3 mat2(rot2); 
    mat1.getEulerYPR(y,p,r);

    // ROS_INFO("Yaw Of My Robot : %f", yaw);


    double x_diff = pose2.position.x - pose1.position.x;
    double y_diff = pose2.position.y - pose1.position.y;
    double toward_angle = atan2(y_diff, x_diff);

    // ROS_INFO("X Diff : %f", x_diff);
    // ROS_INFO("Y Diff : %f", y_diff);
    // ROS_INFO("Toward Angle : %f", toward_angle);

    double angle_diff = toward_angle - y;

    if (angle_diff > PI) angle_diff = - ( 2 * PI - angle_diff);
    else if(angle_diff < - PI) angle_diff = 2 * PI + angle_diff;
    
    // ROS_INFO("Angle Difference : %f", angle_diff);


    // mat2.getEulerYPR(y,p,r);
    // yaw -= y;

    nav_status_.angle_diff = -angle_diff;

    return -angle_diff;
}

void omegaCallback(const roborts_msgs::SubBehaviorConstPtr& msg) {
    is_omega_received = true;

    int mode = msg->mode;
    geometry_msgs::Pose target_lockon = msg->target;

    if (last_mode != mode ) { 
        ROS_INFO("Mode Changed!");
        mini_pid_.reset(); 
        dt = 0.0;    
    }

    switch(mode) {
        case 0 :        // LockOn
            target_omega_ = mini_pid_.getOutput(GetAngle(my_pose, target_lockon), 0.0);
            ROS_INFO("Mode 0 , Angle Difference : %f", GetAngle(my_pose, target_lockon));
            break;
        case 1 :        // LockOn + Shake
            target_omega_ = mini_pid_.getOutput(GetAngle(my_pose, target_lockon), 0.0);
            target_omega_ += MAX_OMEGA * cos(dt * 3.14);  // Shaking Frequecny : 0.5Hz
            dt += 1.0 / FREQUENCY;
            ROS_INFO("Target Omega : %f, dt : %f Cos Term : %f", target_omega_, dt, MAX_OMEGA * cos(dt * 3.14));
            break;
        case 2 :        // Continuos
            target_omega_ = msg->omega;
            break;
        default :
            is_omega_received = false;
            
    }
    last_mode = mode;
}

void poseCallback(const geometry_msgs::PoseWithCovarianceStampedConstPtr& msg) {
    my_pose = msg->pose.pose;
}

void resultCallback(const move_base_msgs::MoveBaseActionResultConstPtr& msg) {
    arrived = true;
}

int main(int argc, char**argv) {
    ros::init(argc, argv, "omega_converter");
    ros::NodeHandle nh;

    ros::Subscriber omni_vel_sub_ = nh.subscribe("omni_cmd_vel", FREQUENCY, converterCallback);
    ros::Subscriber omega_sub_ = nh.subscribe("sub_behavior", FREQUENCY, omegaCallback);
    ros::Subscriber pose_sub_ = nh.subscribe("amcl_pose", FREQUENCY, poseCallback);
    ros::Subscriber result_sub_ = nh.subscribe("move_base/result", FREQUENCY, resultCallback);

    ros::Publisher cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel", FREQUENCY);
    ros::Publisher nav_status_pub_ = nh.advertise<roborts_msgs::NavStatus>("nav_status", FREQUENCY);

    ros::Rate loop_rate(FREQUENCY);

    // Limit Angular Velocity and Acceleration
    mini_pid_.setOutputLimits(MAX_OMEGA);
    mini_pid_.setOutputRampRate(2.5 / FREQUENCY);
    // mini_pid_.setDirection(true);



    while(ros::ok()) {
        ros::spinOnce();

        if (arrived) {
            cmd_vel_.linear.x = 0.0;
            cmd_vel_.linear.y = 0.0;
            cmd_vel_.angular.z = 0.0;
            cmd_vel_pub_.publish(cmd_vel_);
        } else if(is_vel_received) {
            cmd_vel_pub_.publish(cmd_vel_);
        }
        nav_status_pub_.publish(nav_status_);

        loop_rate.sleep();

        is_vel_received = false;
        arrived = false;
    }
} // End of main
