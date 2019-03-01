#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Header.h"
#include "roborts_msgs/GimbalRate.h"

std_msgs::Float64 pitch_vel;
std_msgs::Float64 yaw_vel;

void velocityCallback(const roborts_msgs::GimbalRateConstPtr& msg) {
    ROS_INFO("Pitch Rate : %f", msg->pitch_rate);
    ROS_INFO("Yaw Rate : %f", msg->yaw_rate);
    pitch_vel.data = msg->pitch_rate;
    yaw_vel.data = msg->yaw_rate;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "vel_to_command");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("cmd_gimbal_rate", 1, velocityCallback);
    ros::Publisher pub1 = nh.advertise<std_msgs::Float64>("robomaster_ai/pitch_velocity_controller/command", 1);
    ros::Publisher pub2 = nh.advertise<std_msgs::Float64>("robomaster_ai/yaw_velocity_controller/command", 1);
    ros::Rate loop_rate(10);

    while(ros::ok()){
        pub1.publish(pitch_vel);
        pub2.publish(yaw_vel);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
