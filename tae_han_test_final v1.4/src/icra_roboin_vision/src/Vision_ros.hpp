//v4.0
#pragma once
#ifndef VISIONLOSS
#define VISIONLOSS

#include "pch.hpp"
#include "Data_control.hpp"


#include "icra_roboin_msgs/PitchGain.h"
#include "icra_roboin_msgs/YawGain.h"
#include "icra_roboin_msgs/YoloDetectionInfo.h"
#include "roborts_msgs/GimbalAngle.h"
#include "roborts_msgs/ShootCmd.h"
#include "roborts_msgs/FricWhl.h"
#include "ros/ros.h"
#include <cstdio>
#ifdef BASIC_FUNCTION
class vision_ros {

private:
	ros::Publisher enemy_info_pub;

public:
	vision_ros(ros::NodeHandle &nh) {
		enemy_info_pub = nh.advertise<icra_roboin_msgs::YoloDetectionInfo>("enemy_info", 1);
	}
	void pubEnemyInfo(sendDataset& robots_info);

};


void vision_ros::pubEnemyInfo(sendDataset& robots_info) {
/*
	icra_roboin_msgs::YoloDetectionInfo ros_msg;
		ros_msg.stamp = ros::Time();

		for (int i = 0; i < robots_info.number_of_detection; i++) {
			ros_msg.type_of_robot[i] = robots_info.send_robot_info[i].robot_id;
			ros_msg.angle_hori[i] = robots_info.send_robot_info[i].angle_hori;
			ros_msg.angle_verti[i] = robots_info.send_robot_info[i].angle_verti;
			ros_msg.Pixel_X[i] = robots_info.send_robot_info[i].Pixel_X;
			ros_msg.Pixel_Y[i] = robots_info.send_robot_info[i].Pixel_Y;
			ros_msg.Pixel_width[i] = robots_info.send_robot_info[i].Pixel_width;
			ros_msg.Pixel_height[i] = robots_info.send_robot_info[i].Pixel_height;
			ros_msg.distance[i] = robots_info.send_robot_info[i].distance;
			ros_msg.prob_of_robot[i] = robots_info.send_robot_info[i].prob;
			ros_msg.assigned_number[i] = robots_info.send_robot_info[i].assigned_number;

			ros_msg.numbers_of_armour[i] = robots_info.send_robot_info[i].numbers_of_armour;

			for (int j = 0; j < robots_info.send_robot_info[i].numbers_of_armour; j++) {
				ros_msg.armour[i].assinged_armour_number[j] = robots_info.send_robot_info[i].assinged_armour_number[j];
				ros_msg.armour[i].prob_of_armour[j] = robots_info.send_robot_info[i].prob_of_armour[j];
			}
		}
	this->enemy_info_pub.publish(ros_msg);
*/

}
/*
icra_roboin_msgs::YoloDetectionInfo  must be this format

struct armour{
	short assinged_armour_number[6];
	double prob_of_armour[6];
}

struct YoloDetectionInfo{

	// robot
	short type_of_robot[6];  //  0 > no data, 1 > allay , 2 > enemy , 3> dead
	short angle_hori[6];   // based on center line left is minus, righet is pluse
	short angle_verti [6];   // based on center line upper is plus lower is minus
	short Pixel_X[6];  //center_X
	short Pixel_Y [6];  //center_Y
	short Pixel_width[6];     //pixel coordinate`s width
	short Pixel_height[6];    //pixel coordinate`s height
	float distance [6];  //it is based on meter
	float prob_of_robot[6];  //probability of robot
	short assigned_number[6] = 0;  //dominent number of armour
	/ robot`s armour data
	short numbers_of_armour[6] = 0; // total detected number of armour
	armour armour[6];
};


*/





#endif
#endif

