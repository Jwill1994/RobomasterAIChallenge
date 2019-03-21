#include "ros/ros.h"
#include "std_msgs/UInt8.h"
#include "std_msgs/Header.h"
#include "roborts_msgs/RobotDamage.h"
#include "gazebo_msgs/ContactsState.h"

#define FORWARD      0
#define BACKWARD     1
#define LEFT         2
#define RIGHT        3

std_msgs::UInt8 damage_type;
std_msgs::UInt8 damage_source;

std::string frame;
std::string delimeter = "/";

void bumperCallback(const gazebo_msgs::ContactsStatePtr& msg) {
    ROS_WARN("Contact Frame ID : %s", msg->header.frame_id.c_str());
    frame = msg->header.frame_id;

    if (msg->states.size() != 0) {
        damage_type.data = 0;

        if (frame.find("front") != std::string::npos) {
            ROS_INFO("Front!");
            damage_source.data = FORWARD;
        } else if (frame.find("back") != std::string::npos) {
            damage_source.data = BACKWARD;
        } else if (frame.find("left") != std::string::npos) {
            damage_source.data = LEFT;
        } else if (frame.find("right") != std::string::npos) {
            damage_source.data = RIGHT;
        }
    } 
    
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "contact_to_damage");
    ros::NodeHandle nh;

    ros::Subscriber sub_front = nh.subscribe("front_armor_contact", 30, bumperCallback);
    ros::Subscriber sub_left = nh.subscribe("left_armor_contact", 30, bumperCallback);
    ros::Subscriber sub_right = nh.subscribe("right_armor_contact", 30, bumperCallback);
    ros::Subscriber sub_back = nh.subscribe("back_armor_contact", 30, bumperCallback);

    ros::Publisher pub = nh.advertise<roborts_msgs::RobotDamage>("robot_damage", 30);
    roborts_msgs::RobotDamage robot_damage;

    ros::Rate loop_rate(10);

    while(ros::ok()){

        robot_damage.damage_type = damage_type.data;
        robot_damage.damage_source = damage_source.data;

        pub.publish(robot_damage);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}
