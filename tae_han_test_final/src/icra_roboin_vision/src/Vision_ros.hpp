//v4.0
#pragma once
#ifndef VISIONLOSS
#define VISIONLOSS

#include "pch.hpp"
#include "Data_control.hpp"
#include "icra_roboin_msgs/YoloDetectionInfo.h"
#include "ros/ros.h"
#include <cstdio>

class vision_ros {
private:
	ros::Publisher enemy_info_pub;
public:
	vision_ros(ros::NodeHandle &nh) {enemy_info_pub = nh.advertise<icra_roboin_msgs::YoloDetectionInfo>("enemy_info", 1);}
	void pubEnemyInfo(data_control& CT_data);
};
// engage_id=1, enemy_id=2, dead_id=3
void vision_ros::pubEnemyInfo(data_control& CT_data) {
	icra_roboin_msgs::YoloDetectionInfo ros_msg;
		for (int i = 0; i < CT_data.dataset.number_of_robot; i++) {
			if (CT_data.dataset.robot_id[i] == engage_enemy_id) {ros_msg.enemy_detected[i] = engage_id;}
			else if (CT_data.dataset.robot_id[i] == enemy_id) {ros_msg.enemy_detected[i] = enemy_id;}
			else if (CT_data.dataset.robot_id[i] == dead_id) {ros_msg.enemy_detected[i] = dead_id;}
			ros_msg.angle_hori[i] = CT_data.dataset.angle_hori[i];
			ros_msg.distance[i] = CT_data.dataset.distance[i];
			double d = CT_data.dataset.distance[i];
			double x = (CT_data.dataset.Center_X[i] - 320)*d*0.00146;
			double f = sqrt(pow(d,2.0)-pow(x,2.0));
			double angle = atan2(x,f);
			std::cout<<"robot x :	"<<x<<std::endl;
			std::cout<<"robot d :	"<<d<<std::endl;
			std::cout<<"robot f :	"<<f<<std::endl;
			std::cout<<"robot a :	"<<angle*180/PI<<std::endl;
			
		}
	this->enemy_info_pub.publish(ros_msg);
}
#endif


