#pragma once
#ifndef DETECTOR_H
#define DETECTOR_H
#include <iostream>
#include <time.h>
#include <vector>
#include <ros/ros.h>
#include "geometry_msgs/PoseWithCovarianceStamped.h"
#include "geometry_msgs/PoseArray.h"
#include "nav_msgs/OccupancyGrid.h"
#include "icra_roboin_msgs/Obstacles.h"
#include "icra_roboin_msgs/CircleObstacle.h"

float pi = 3.141459265358979;

/*[m/cell]*/
const double resolution = 0.05;
/*라이다 위치*/
float pose[3] = {1.0,1.0,pi};
/*최저 확률*/
int prob_threshold = 60;
/*프레임 이름*/
std::string frame = "map";
/*받은 점들의 위치*/
std::vector<std::vector<double>> measurement;
/*publish 할 점들*/
std::vector<std::vector<double>> pub_point;
/*MapInfo*/
nav_msgs::OccupancyGrid map_info;

ros::Subscriber obstacles_sub_;
ros::Subscriber pose_sub_;
ros::Subscriber map_sub_;
ros::Publisher dynamic_pub_;

bool measure_ok = false;
bool map_ok = false;


#endif//DETECTOR_H