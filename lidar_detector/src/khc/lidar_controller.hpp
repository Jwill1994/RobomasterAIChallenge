#pragma once
#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <time.h>
#include <vector>

#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/Int8.h"

ros::Subscriber command_sub_;
ros::Subscriber lidar_sub_;
ros::Publisher vel_pub_;

sensor_msgs::LaserScan scan;

double side_start = -75 * 3.14159265358979 / 180;
double side_end = -45 * 3.14159265358979 / 180;
double reload_wanted_left = 0.5;
double reload_wanted_back = 0.6 + 0.3;
double min_incline_diff = 0.052; // 3degree
double min_xy_diff = 0.05; // 5cm
double angular_sensitivity = 0.1;
double linear_sensitivity = 0.1;


short left = 0;
short counter = 0;
short angle_counter = 0;
double past_point[2] = {0,0};
double current_point[2] = {0,0};
double side_incline = 0;
double current_angle = 0;
bool lidar_ok = false;

#endif//CONTROL_H