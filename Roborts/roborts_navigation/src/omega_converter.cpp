#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <roborts_msgs/SubBehavior.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <geometry_msgs/Pose.h>
#include <math.h>
#include <tf/tf.h>
#include "pid.h"

#define FREQUENCY 20
#define MAX_OMEGA 2.5

geometry_msgs::Twist cmd_vel_;
double target_omega_;
geometry_msgs::Pose my_pose;
bool is_vel_received = false;
bool is_omega_received = false;
double k, alpha, beta;

MiniPID mini_pid_ = MiniPID(10.0,0.1,0.1);
int last_mode;
float dt;

int callback_order;

void converterCallback(const geometry_msgs::TwistConstPtr& msg) {
    is_vel_received = true;

    callback_order++;
    ROS_INFO("Order of Converter Callback : %d", callback_order);
    double original_omega = msg->angular.z;

    // If not received target omega or angular velocity is similar each other
    if(!is_omega_received || fabs(original_omega - target_omega_) < 0.1) {
        ROS_INFO("Case 1");
        k = 1.0; alpha = 1.0; beta = 0.0;
    } else if (fabs(original_omega) > 0.05 && fabs(target_omega_) < 0.05) {    // target omega is almost zero.
        ROS_INFO("Case 2");
        k = FREQUENCY / original_omega;
        alpha = sin(original_omega / FREQUENCY);
        beta = cos(original_omega / FREQUENCY) - 1;
    } else if (fabs(original_omega) < 0.05 && fabs(target_omega_) > 0.05) {    // current omega is almost zero.
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
    // Conversion Matrix
    // |x'| = k * |alpha beta | |x|
    // |y'| =     |-beta alpha| |y|
    cmd_vel_.linear.x = k * (alpha * msg->linear.x + beta * msg->linear.y);
    cmd_vel_.linear.y = k * (-beta * msg->linear.x + alpha * msg->linear.y);
    cmd_vel_.angular.z = is_omega_received ? target_omega_ : original_omega;
}

double GetAngle(const geometry_msgs::Pose &pose1,
                  const geometry_msgs::Pose &pose2) {
    const geometry_msgs::Quaternion quaternion1 = pose1.orientation;
    const geometry_msgs::Quaternion quaternion2 = pose2.orientation;
    tf::Quaternion rot1, rot2;
    tf::quaternionMsgToTF(quaternion1, rot1);
    tf::quaternionMsgToTF(quaternion2, rot2);
    double r,p,y;
    double yaw;
    tf::Matrix3x3 mat1(rot1);
    tf::Matrix3x3 mat2(rot2);
    mat1.getEulerYPR(y,p,r);
    yaw = y;
    mat2.getEulerYPR(y,p,r);
    yaw -= y;
    return yaw;
}

void omegaCallback(const roborts_msgs::SubBehaviorConstPtr& msg) {
    is_omega_received = true;

    callback_order++;
    ROS_INFO("Order of Omega Callback : %d", callback_order);
    int mode = msg->mode;
    geometry_msgs::Pose target_lockon = msg->target;

    if (last_mode != mode ) { 
        mini_pid_.reset(); 
        dt = 0.0;    
    }

    switch(mode) {
        case 0 :        // LockOn
            target_omega_ = mini_pid_.getOutput(GetAngle(my_pose, target_lockon), 0.0);
            break;
        case 1 :        // LockOn + Shake
            target_omega_ = mini_pid_.getOutput(GetAngle(my_pose, target_lockon), 0.0);
            target_omega_ += MAX_OMEGA * cos(dt * 3.14);  // Shaking Frequecny : 0.5Hz
            dt += 1 / FREQUENCY;
            break;
        case 2 :        // Continuos
        default :
            target_omega_ = msg->omega;
    }
    last_mode = mode;
}

void poseCallback(const geometry_msgs::PoseWithCovarianceStampedConstPtr& msg) {
    callback_order++;
    ROS_INFO("Order of Pose Callback : %d", callback_order);
    my_pose = msg->pose.pose;
}

int main(int argc, char**argv) {
    ros::init(argc, argv, "omega_converter");
    ros::NodeHandle nh;

    ros::Subscriber omni_vel_sub_ = nh.subscribe("omni_cmd_vel", FREQUENCY, converterCallback);
    ros::Subscriber omega_sub_ = nh.subscribe("sub_behavior", FREQUENCY, omegaCallback);
    ros::Subscriber pose_sub_ = nh.subscribe("amcl_pose", FREQUENCY, poseCallback);

    ros::Publisher cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel", FREQUENCY);

    

    ros::Rate loop_rate(FREQUENCY);

    // Limit Angular Velocity and Acceleration
    mini_pid_.setOutputLimits(MAX_OMEGA);
    mini_pid_.setOutputRampRate(2.5 / FREQUENCY);

    while(ros::ok()) {
        ros::spinOnce();

        if(is_vel_received)
            cmd_vel_pub_.publish(cmd_vel_);

        loop_rate.sleep();

        is_vel_received = false;
        is_omega_received = false;

        callback_order = 0;
    }
} // End of main