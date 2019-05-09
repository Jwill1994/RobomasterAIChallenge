#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Float64.h>
#include <math.h>

#define FREQUENCY FREQUENCY

geometry_msgs::Twist cmd_vel_;
std_msgs::Float64 target_omega_;
bool is_vel_received = false
bool is_omega_received = false;
double k, alpha, beta;

void converterCallback(const geometry_msgs::TwistConstPtr& msg) {
    is_vel_received = true;
    ROS_INFO("Is Omega Received : %b", is_omega_received);

    // If not received target omega or angular velocity is similar each other
    if(!is_omega_received || fabs(msg->angular.z - target_omega_) < 0.1) {
        ROS_INFO("Case 1");
        k = 1.0; alpha = 1.0; beta = 0.0;
    } else if (fabs(msg->angular.z) > 0.05 && fabs(target_omega_) < 0.05) {    // target omega is almost zero.
        ROS_INFO("Case 2");
        k = FREQUENCY / msg->angular.z;
        alpha = sin(msg->angular.z / FREQUENCY);
        beta = cos(msg->angular.z / FREQUENCY) - 1;
    } else if (fabs(msg->angular.z) < 0.05 && fabs(target_omega_) > 0.05) {    // current omega is almost zero.
        ROS_INFO("Case 3");
        k = target_omega_ / (2 * FREQUENCY * (1 - cos(target_omega_ / FREQUENCY));
        alpha = sin(target_omega_ / FREQUENCY);
        beta = 1 - cos(target_omega_ / FREQUENCY);
    } else {
        ROS_INFO("Case 4");
        k = target_omega_ / (msg->angular.z * 2 * (1 - cos(target_omega_ / FREQUENCY)));
        alpha = 1 + cos((target_omega_ - msg->angular.z) / FREQUENCY) - cos(target_omega_ / FREQUENCY) - cos(msg->angular.z / FREQUENCY);
        beta = sin((target_omega_ - msg->angular.z) / FREQUENCY) - sin(target_omega_ / FREQUENCY) + sin(msg->angular.z / FREQUENCY);
    }

    // Conversion Matrix
    // |x'| = k * |alpha beta | |x|
    // |y'| =     |-beta alpha| |y|
    cmd_vel_.linear.x = k * (alpha * msg->linear.x + beta * msg->linear.y);
    cmd_vel_.linear.y = k * (-beta * msg->linear.x + alpha * msg->linear.y);
    cmd_vel_.angular.z = is_omega_received ? target_omega_ : msg->angular.z;
}

void omegaCallback(const std_msgs::Float64ConstPtr& msg) {
    is_omega_received = true;
    target_omega_ = msg->data;
}

int main(int argc, char**argv) {
    ros::init(argc, argv, "omega_converter");
    ros::NodeHandle nh;

    ros::Subscriber omni_vel_sub_ = nh.subscribe("omni_cmd_vel", FREQUENCY, converterCallback);
    ros::Subscriber omega_sub_ = nh.subscribe("target_omega", FREQUENCY, omegaCallback);

    ros::Publisher cmd_vel_pub_ = nh.advertise<geometry_msgs::Twist>("cmd_vel", FREQUENCY);

    

    ros::Rate loop_rate(FREQUENCY);

    whiel(ros::ok()) {
        ros::spinOnce();

        if(is_vel_received)
            cmd_vel_pub_.publish(cmd_vel_);

        loop_rate.sleep();

        is_vel_received = false;
        is_omega_received = false;
    }
}