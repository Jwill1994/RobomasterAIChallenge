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
	int num = 0;
	bool detect = false;
	for (int i = 0; i < CT_data.dataset.number_of_robot; i++) {
		if (CT_data.dataset.robot_id[i] == engage_enemy_id) {
			ros_msg.enemy_detected[1] = 1;
			ros_msg.angle_hori[1] = CT_data.dataset.angle_hori[i];
			ros_msg.distance[1] = CT_data.dataset.distance[i]*1000;
			num++;
		}
		else if (CT_data.dataset.robot_id[i] == alliance_id) {
			ros_msg.enemy_detected[0] = 1;
			ros_msg.angle_hori[0] = CT_data.dataset.angle_hori[i];
			ros_msg.distance[0] = CT_data.dataset.distance[i]*1000;
		}
		else if (CT_data.dataset.robot_id[i] == enemy_id) {
			ros_msg.enemy_detected[2] = 1;
			ros_msg.angle_hori[2] = CT_data.dataset.angle_hori[i];
			ros_msg.distance[2] = CT_data.dataset.distance[i]*1000;
			if (detect == false) {num++; detect = true;}
		}
	}
	ros_msg.number_of_detection = num;
	this->enemy_info_pub.publish(ros_msg);
}
#endif


