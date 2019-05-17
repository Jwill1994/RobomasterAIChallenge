#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/Int8.h"

ros::Subscriber command_sub_;
ros::Subscriber lidar_sub_;
ros::Publisher vel_pub_;

double vel_give = 0.2;
double side_incline = 0;
double current_angle = 0;
double reload_wanted_left = 0.5;
double reload_wanted_back = 0.6 + 0.3; // 바구니_벽 거리 + 바구니_라이다 거리
double min_incline_diff = 0.052; // 3도
double min_xy_diff = 0.05; // 5cm

int num_angle = 20;
int behave = 0;


#endif//CONTROL_H
