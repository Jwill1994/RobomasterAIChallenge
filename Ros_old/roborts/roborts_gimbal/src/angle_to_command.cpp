#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Header.h"
#include "roborts_msgs/GimbalAngle.h"
#include "gazebo_msgs/GetLinkState.h"

std_msgs::Float64 pitch_angle_;
std_msgs::Float64 yaw_angle_;

void angleCallback(const roborts_msgs::GimbalAngleConstPtr& msg) {
    ROS_INFO("Pitch Angle : %f", msg->pitch_angle);
    ROS_INFO("Yaw Angle : %f", msg->yaw_angle);
    pitch_angle_.data = msg->pitch_angle;
    pitch_angle_.data = msg->yaw_angle;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "angle_to_command");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("cmd_gimbal_angle", 1, angleCallback);
    ros::Publisher pub1 = nh.advertise<std_msgs::Float64>("robomaster_ai/pitch_position_controller/command", 1);
    ros::Publisher pub2 = nh.advertise<std_msgs::Float64>("robomaster_ai/yaw_position_controller/command", 1);
    ros::Rate loop_rate(4);

    
    // ros::ServiceClient get_link_state_client = nh.serviceClient<gazebo_msgs::GetLinkState>("/gazebo/get_link_state");
    // gazebo_msgs::GetLinkState svc;
    // svc.request.link_name = "pitch_Link";
    // svc.request.reference_frame = "map";



    while(ros::ok()){
        pub1.publish(pitch_angle_);
        pub2.publish(yaw_angle_);

        

        // if(get_link_state_client.call(svc)){
        //     ROS_INFO("x:%f", svc.response.link_state.pose.position.x);
        //     ROS_INFO("y:%f", svc.response.link_state.pose.position.y);
        //     ROS_INFO("z:%f", svc.response.link_state.pose.position.z);
        // }
        ros::spinOnce();
        loop_rate.sleep();
        

    }

    return 0;
}
