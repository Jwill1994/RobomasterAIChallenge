//v4.0
#pragma once
#ifndef DATA_CONTROL_HPP
#define DATA_CONTROL_HPP
#include "pch.hpp"

/*적의 모든 아머들의 정보 구조*/
struct armour_data {
	short number_of_armour = 0;
	short armour_id[max_num_armour] = {0,0,0,0};
	double prob[max_num_armour] = {0,0,0,0};
	short Center_x[max_num_armour] = {0,0,0,0};
	short Center_y[max_num_armour] = {0,0,0,0};
	short width[max_num_armour] = {0,0,0,0};
	short height[max_num_armour] = {0,0,0,0};
	float distance[max_num_armour] = {0,0,0,0};
};

struct VisionDataset {
	cv::Mat detectimg;
	cv::Mat depth_img;
	short number_of_robot = 0;
	short robot_id[max_num_robot] = {0,0,0};
	double prob[max_num_robot] = {0,0,0};
	short Center_X[max_num_robot] = {0,0,0};
	short Center_Y[max_num_robot] = {0,0,0};
	double width[max_num_robot] = {0,0,0};
	double height[max_num_robot] = {0,0,0};
	float distance[max_num_robot] = {0,0,0};
	int angle_hori[max_num_robot] = {0,0,0};
	armour_data armour;
};

/*짐벌에 보내주는 구조*/
struct send_target_info {
	short infochecker = 0 ;  // 발견못함=0, 적아머+적로봇=1, 적로봇=2, 적아며=3
	short Pixel_X = 0;
	short Pixel_Y = 0;
	float distance = 0;
	short robot_center_x = 0;
	short robot_center_y = 0;
	short robot_box_width = 0;
	float robot_distance = 0;
};

/*데이타 처리*/
class data_control {
public:
	VisionDataset dataset;
private:
	void VisionDataset_initialize(VisionDataset& dataset);
    /*아머정보 부여*/
    void assign_armour(short num, bbox_t info);
    /*로봇정보 부여*/
    void assign_robot(short num, bbox_t info);
    /*로봇과 아머거리 구하기*/
    float assign_distance(short x, short y);
public:
	data_control(){this->VisionDataset_initialize(this->dataset);}
	~data_control() = default;
	/*clear the data set before detecting*/
	void runing_initialize();
    /*로봇&아머 정보 부여*/
    void assign_data(std::string obj, bbox_t info);
	/*아머 정보를 토대로 로봇구분*/
	void after_assign();
};

/*정리된 정보를 보내는 클래스*/
class send_control {
public:
	send_target_info to_gimbal;
private:
	void to_gimbal_clear();
	void send_gimbal_maker(data_control& CT_data);
public:
	send_control() {this->to_gimbal_clear();}
	~send_control() = default;
	/*짐벌과 블랙보드에 보내는 정보 부여*/
	void send_data_maker(data_control& CT_data);
};

void data_control::VisionDataset_initialize(VisionDataset& dataset) {
    dataset.number_of_robot = 0;
    for (int index = 0; index < max_num_robot; index++) {
        dataset.Center_X[index] = 0; dataset.Center_Y[index] = 0;dataset.height[index] = 0; dataset.width[index] = 0;
        dataset.prob[index] = 0; dataset.robot_id[index] = 0;dataset.distance[index] = 0; dataset.angle_hori[index] = 0;}
	dataset.armour.number_of_armour = 0;
    for (int index = 0; index < max_num_armour; index++) {
        dataset.armour.armour_id[index] = 0; dataset.armour.prob[index] = 0;dataset.armour.Center_x[index] = 0; dataset.armour.Center_y[index] = 0;
        dataset.armour.width[index] = 0; dataset.armour.height[index] = 0;dataset.armour.distance[index] = 0;}
}

void data_control::after_assign() { // robot_id -> enemy_id or dead_id
	for (short i=0; i<this->dataset.armour.number_of_armour; i++) {
        if (this->dataset.armour.armour_id[i] == num1_id || this->dataset.armour.armour_id[i] == num2_id) {
			for (short j=0; j<this->dataset.number_of_robot; j++) {
				if (abs(this->dataset.Center_X[j]-this->dataset.armour.Center_x[i])<this->dataset.width[j]
				&& abs(this->dataset.Center_Y[j]-this->dataset.armour.Center_y[i])<this->dataset.height[j]
				&& this->dataset.robot_id[j] == robot_id) {
					this->dataset.robot_id[j] = enemy_id;}}}
		else if (this->dataset.armour.armour_id[i] == dead_armour_id) {
			for (short j=0; j<this->dataset.number_of_robot; j++) {
				if (abs(this->dataset.Center_X[j]-this->dataset.armour.Center_x[i])<this->dataset.width[j]
				&& abs(this->dataset.Center_Y[j]-this->dataset.armour.Center_y[i])<this->dataset.height[j]
				&& this->dataset.robot_id[j] == robot_id) {
					this->dataset.robot_id[j] = dead_id;}}}}}

void data_control::runing_initialize() {this->VisionDataset_initialize(this->dataset);}

float data_control::assign_distance(short x, short y) {
	float distance = 0;
	if(this->dataset.depth_img.at<double>(y,x)>0) {distance = this->dataset.depth_img.at<double>(y,x);}
	return distance / 1000;}

void data_control::assign_armour(short num, bbox_t info) {	// 적의 아머정보 부여
    short index = this->dataset.armour.number_of_armour;
    this->dataset.armour.armour_id[index] = num;
    this->dataset.armour.prob[index] = info.prob;
    this->dataset.armour.Center_x[index] = info.x + info.w * 0.5;
    this->dataset.armour.Center_y[index] = info.y + info.h * 0.5;
    this->dataset.armour.width[index] = info.w;
    this->dataset.armour.height[index] = info.h;
    this->dataset.armour.distance[index] = assign_distance(this->dataset.armour.Center_x[index], this->dataset.armour.Center_y[index]);
    this->dataset.armour.number_of_armour += 1;}

void data_control::assign_robot(short num, bbox_t info) {
    short index = this->dataset.number_of_robot;
    this->dataset.robot_id[index] = num;
    this->dataset.prob[index] = info.prob;
    this->dataset.Center_X[index] = info.x + info.w * 0.5;
    this->dataset.Center_Y[index] = info.y + info.h * 0.5;
    this->dataset.width[index] = info.w;
    this->dataset.height[index] = info.h;
    this->dataset.distance[index] = assign_distance(this->dataset.Center_X[index], this->dataset.Center_Y[index]);
    this->dataset.number_of_robot += 1;
        //double x = (this->dataset.Center_X[index] - 320)*this->dataset.distance[index]*0.00156;
        //double f = sqrt(pow(this->dataset.distance[index],2.0)-pow(x,2.0));
        //this->dataset.angle_hori[index] = atan2(x,f);}
        this->dataset.angle_hori[index] = 100*180 / 3.141592 * atan2(this->dataset.Center_X[index] - 320, 320/tan(3.141592/180*0.5*69.4)   );
    }

void data_control::assign_data(std::string obj, bbox_t info) {
    if(obj == robot_str) {assign_robot(robot_id, info);}
    else if(obj == dead_num1_str) {assign_armour(dead_armour_id, info);}
    else if(obj == dead_num2_str) {assign_armour(dead_armour_id, info);}
#ifdef US_BLUE
    else if(obj == red_num1_str) {assign_armour(num1_id, info);}
    else if(obj == red_num2_str) {assign_armour(num2_id, info);}
#else // US_RED
    else if(obj == blue_num1_str) {assign_armour(num1_id, info);}
    else if(obj == blue_num2_str) {assign_armour(num2_id, info);}
#endif
}

void send_control::to_gimbal_clear() {
	this->to_gimbal.infochecker = 0; this->to_gimbal.Pixel_X = 0;
	this->to_gimbal.Pixel_Y = 0; this->to_gimbal.distance = 0; }

void send_control::send_gimbal_maker(data_control& CT_data) {
	send_target_info best_target;
	int infochecker = 0;	// nothing=0, robot+armour=1, robot=2, armour=3
	int target = 0;
	double target_area = 0;
	int robot_check = 0;
	if(CT_data.dataset.armour.number_of_armour>0) {
		for(int i=0; i<CT_data.dataset.armour.number_of_armour; i++) {
			if(CT_data.dataset.armour.armour_id[i] != dead_armour_id) {
				infochecker = 3; // armour
				if (target_area < CT_data.dataset.armour.width[i] * CT_data.dataset.armour.height[i]) {
					target = i;
					target_area = CT_data.dataset.armour.width[i] * CT_data.dataset.armour.height[i];}}}
		if (infochecker == 3) {
			best_target.Pixel_X = CT_data.dataset.armour.Center_x[target];
			best_target.Pixel_Y = CT_data.dataset.armour.Center_y[target];
			best_target.distance = CT_data.dataset.armour.distance[target];}
		for(short i=0; i<CT_data.dataset.number_of_robot;i++) {
			if (abs(CT_data.dataset.armour.Center_x[target]-CT_data.dataset.Center_X[i])<CT_data.dataset.width[i]
			&& abs(CT_data.dataset.armour.Center_y[target]-CT_data.dataset.Center_Y[i])<CT_data.dataset.height[i]
			&& infochecker == 3) {
				best_target.robot_center_x = CT_data.dataset.Center_X[i];
                best_target.robot_center_y = CT_data.dataset.Center_Y[i];
                best_target.robot_distance = CT_data.dataset.distance[i];
				best_target.robot_box_width = CT_data.dataset.width[i];
				CT_data.dataset.robot_id[i] = engage_enemy_id; // for blackboard
				infochecker = 1; // armour+robot
				break;}}}
	if(infochecker == 0) {
		for(int i=0; i<CT_data.dataset.number_of_robot; i++) {
			if(CT_data.dataset.robot_id[i] == enemy_id) {
				infochecker = 2;
				if(target_area < CT_data.dataset.width[i] * CT_data.dataset.height[i]) {
					target = i;
					target_area = CT_data.dataset.width[i] * CT_data.dataset.height[i];}
				best_target.Pixel_X = CT_data.dataset.Center_X[target];
				best_target.Pixel_Y = CT_data.dataset.Center_Y[target];
				best_target.distance = CT_data.dataset.distance[target];}}}
	best_target.infochecker = infochecker;
	this->to_gimbal = best_target;}

void send_control::send_data_maker(data_control& CT_data) {
	this->to_gimbal_clear(); this->send_gimbal_maker(CT_data);}
#endif // !DATA_CONTROL_HPP
