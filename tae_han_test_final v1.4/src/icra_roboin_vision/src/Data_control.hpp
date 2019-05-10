//v4.0
#pragma once
#ifndef DATA_CONTROL_HPP
#define DATA_CONTROL_HPP
#include "pch.hpp"
//#include "camera.hpp"

/*적의 모든 아머들의 정보 구조*/
struct armour_data {
	short number_of_armour = 0;
	short armour_id[max_num_armour] = {0,0,0,0};
	double prob[max_num_armour] = {0,0,0,0};
	short Center_x[max_num_armour] = {0,0,0,0};
	short Center_y[max_num_armour] = {0,0,0,0};
	short width[max_num_armour] = {0,0,0,0};
	short height[max_num_armour] = {0,0,0,0};
	double distance[max_num_armour] = {0,0,0,0};
};

/*이걸 만든 동환이는 리얼루 천재인듯...*/
struct VisionDataset {
	cv::Mat detectimg;
	cv::Mat depth_img;
#ifdef DISPLAY
	cv::Mat display;
#endif
	short number_of_robot = 0;
	short robot_id[max_num_robot] = {0,0,0};
	double prob[max_num_robot] = {0,0,0};
	short Center_X[max_num_robot] = {0,0,0};
	short Center_Y[max_num_robot] = {0,0,0};
	double width[max_num_robot] = {0,0,0};
	double height[max_num_robot] = {0,0,0};
	double distance[max_num_robot] = {0,0,0};
	armour_data armour;
};

/*로봇 정보 구조*/
struct send_robot_info {
	short robot_id = 0 ; 		// 아군=1, 적군=2, 죽음=3. 1번=4, 2번=5, 1번적군=6, 2번적군=7
	short angle_hori = 0;   	// based on center line left is minus, righet is pluse
	short angle_verti = 0;   	// based on center line upper is plus lower is minus  
	short Pixel_X = 0;
	short Pixel_Y = 0;
	short Pixel_width = 0;
	short Pixel_height = 0;
	float distance = 0;
	float prob;
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

/*블랙보드에 보내주는 구조*/
struct sendDataset {
	send_robot_info robot_info[max_num_robot];
};

/*this class for vision data control (all data is in it)*/
class data_control {
public:
	VisionDataset dataset;
private:
	void armour_initialize(armour_data& armour);
	void VisionDataset_initialize(VisionDataset& dataset);
    /*아머정보 부여*/
    void assign_armour(int num, bbox_t info);
    /*로봇정보 부여*/
    void assign_robot(int num, bbox_t info);
    /*로봇과 아머거리 구하기*/
    double assign_distance(int x, int y);


public:
	data_control(){
		this->VisionDataset_initialize(this->dataset);
#ifdef DEBUG
		std::cout << "data_control initialized" << std::endl;
#endif //!DEBUG
	}
	~data_control() = default;
	/*clear the data set before detecting*/
	void runing_initialize();
	/*use CV Mat for get depth data*/
    float linear_align(short RGB_X, short RGB_Y, data_control& CT_data);
    /*assign data*/
    void assign_data(std::string obj, bbox_t info);
	/*적로봇 1번 2번 구분*/
	void after_assign();
};

/*정리된 정보를 보내는 클래스*/
class send_control {
public:
	sendDataset to_black_board;
	send_target_info to_gimbal;

private:
	void send_robot_info_clear(send_robot_info& robot);
	void to_gimbal_clear();
	void to_black_board_clear();
	void send_data_clear();
	/*for angle maker, it is for upload black board*/
	void angle_maker(short& hori, short& verti, data_control& CT_data, int i);
	void send_black_board_maker(data_control& CT_data);
	void send_gimbal_maker(data_control& CT_data);

public:
	send_control() {
		this->send_data_clear();
#ifdef DEBUG
		std::cout << " (send_control::) send_control is initialized " << std::endl;
#endif //!DEBUG
	}
	~send_control() = default;
	/*짐벌과 블랙보드에 보내는 정보 부여*/
	void send_data_maker(data_control& CT_data);
};

void data_control::armour_initialize(armour_data& armour) {
    armour.number_of_armour = 0;
    for (int index = 0; index < max_num_armour; index++) {
        armour.armour_id[index] = 0;
        armour.prob[index] = 0;
        armour.Center_x[index] = 0;
        armour.Center_y[index] = 0;
        armour.width[index] = 0;
        armour.height[index] = 0;
        armour.distance[index] = 0;
    }
}

void data_control::VisionDataset_initialize(VisionDataset& dataset) {
    dataset.number_of_robot = 0;
    for (int index = 0; index < max_num_robot; index++) {
        dataset.Center_X[index] = 0;
        dataset.Center_Y[index] = 0;
        dataset.height[index] = 0;
        dataset.width[index] = 0;
        dataset.prob[index] = 0;
        dataset.robot_id[index] = 0;
        dataset.distance[index] = 0;
	}
    this->armour_initialize(dataset.armour);
}

void data_control::after_assign() {					// 1번아머 2번아머중 무엇이 속해있냐에 따라 번호 부여
	for (int i=0; i<this->dataset.number_of_robot; i++) {
                if (this->dataset.robot_id[i] == enemy_id) {

			for (int j=0; j<this->dataset.armour.number_of_armour; j++) {
				if (abs(this->dataset.Center_X[i]-this->dataset.armour.Center_x[j]) < this->dataset.width[i]
					&& abs(this->dataset.Center_Y[i]-this->dataset.armour.Center_y[j]) < this->dataset.height[i]) {
						if(this->dataset.armour.armour_id[j] == num1_id) {this->dataset.robot_id[i] = num1_enemy_id;}
						else if(this->dataset.armour.armour_id[j] == num2_id) {this->dataset.robot_id[i] = num2_enemy_id;}
					}
			}
		}
        }
}

void data_control::runing_initialize() {this->VisionDataset_initialize(this->dataset);}

double data_control::assign_distance(int x, int y) {
#ifdef REMOTE
	int num = 0;
	double distance = 0;
	if(this->dataset.depth_img.at<double>(y,x)>0) {
#ifdef VISION_DATACHECK
            std::cout << "X : " << x << " Y : " << y << std::endl;
#endif //!VISION_DATACHECK
		distance+=this->dataset.depth_img.at<double>(y,x);
		num++;}
	return distance / num /1000;      // 센터,상,하,좌,우 (0이 아닌)값들을 하나씩 가져온 후 평균낸 값을 거리로 보기
#else
	//camera.VisionDataset_getDepth(CT_data);	// 식 camera 말고 다른곳에다가 만들기
#endif
}

void data_control::assign_armour(int num, bbox_t info) {	// 적의 아머정보 부여
    int index = this->dataset.armour.number_of_armour;
    this->dataset.armour.armour_id[index] = num;      		// 1번=4, 2번=5
    this->dataset.armour.prob[index] = info.prob;
    this->dataset.armour.Center_x[index] = info.x + info.w * 0.5;
    this->dataset.armour.Center_y[index] = info.y + info.h * 0.5;
    this->dataset.armour.width[index] = info.w;
    this->dataset.armour.height[index] = info.h;
    this->dataset.armour.distance[index] = assign_distance(this->dataset.armour.Center_x[index], this->dataset.armour.Center_y[index]);
    // std::cout<<this->dataset.armour.distance[index]<<std::endl;
    this->dataset.armour.number_of_armour += 1;
}

void data_control::assign_robot(int num, bbox_t info) {
    int index = this->dataset.number_of_robot;
    this->dataset.robot_id[index] = num;              		// 아군=1, 적군=2, 죽음=3
    this->dataset.prob[index] = info.prob;
    this->dataset.Center_X[index] = info.x + info.w * 0.5;
    this->dataset.Center_Y[index] = info.y + info.h * 0.5;
    this->dataset.width[index] = info.w;
    this->dataset.height[index] = info.h;
    this->dataset.distance[index] = assign_distance(this->dataset.Center_X[index], this->dataset.Center_Y[index]);
    this->dataset.number_of_robot += 1;
}

void data_control::assign_data(std::string obj, bbox_t info) {
#ifdef US_BLUE
    if(obj == blue_str) {assign_robot(alliance_id, info);}
    else if(obj == red_str) {assign_robot(enemy_id, info);}
    //else if(obj == dead_str) {assign_robot(dead_id, info);}
    else if(obj == dead_str) {assign_robot(enemy_id, info);}
    else if(obj == red_num1_str) {assign_armour(num1_id, info);}
    else if(obj == red_num2_str) {assign_armour(num2_id, info);}

#else // US_RED
    if(obj == blue_str) {assign_robot(enemy_id, info);}
    else if(obj == red_str) {assign_robot(alliance_id, info);}
    else if(obj == dead_str) {assign_robot(dead_id, info);}

    else if(obj == blue_num1_str) {assign_armour(num1_id, info);}
    else if(obj == blue_num2_str) {assign_armour(num2_id, info);}

#endif
}

float data_control::linear_align(short RGB_X, short RGB_Y, data_control& CT_data) {
    /*
    // based on 3m > 6 pixel moved and it is for 640*480
    short fake_depth_x = (RGB_X * 0.63125 + 112);

    short real_depth_y = (RGB_Y * 0.63125 + 88.5);
    float fake_distance = this->VisionDataset_avoid_zero(fake_depth_x, real_depth_y,CT_data);
    float distance = 0;


    if (fake_distance > 0) {
        short move_pixel = (17.72 / fake_distance);
        short real_depth_x = (RGB_X * 0.63125 + 118 - move_pixel);
        distance = this->VisionDataset_avoid_zero(real_depth_x, real_depth_y,CT_data);
    }
    */
    /*=================== FOR 424*240 =================*/
    float distance=0;
    float distance1_1; float distance1_2; float distance1_3;
    float distance2_1; float distance2_2; float distance2_3;
    float distance3_1; float distance3_2; float distance3_3;
    int start_x=50;
    int start_y=32;
    cv::Mat dept=CT_data.dataset.depth_img(cv::Rect(start_x,start_y,423-start_x-75,239-start_y-37));
    /*dept size : 298 * 170*/
    //cv::resize(dept,dept,cv::Size(424,240));
    short deptx=RGB_X*298/424;
    short depty=RGB_Y*170/240;
    std::cout << "RGB_XY: "+std::to_string(RGB_X) + " "+ std::to_string(RGB_Y)+" DEPTH_XY : "
                 +std::to_string(deptx)+" "+std::to_string(depty)+" / ";
    int count_valid=0;
    distance1_1=dept.at<double>(std::max(0,deptx-1),std::max(0,depty-1));
    if(distance1_1!=0) count_valid+=1; printf("%f\n",distance1_1);
    distance1_2=dept.at<double>(deptx,std::max(0,depty-1));
    if(distance1_2!=0) count_valid+=1;
    distance1_3=dept.at<double>(std::min(297,deptx+1),std::max(0,depty-1));
    if(distance1_3!=0) count_valid+=1;
    distance2_1=dept.at<double>(std::max(0,deptx-1),depty);
    if(distance2_1!=0) count_valid+=1;
    distance2_2=dept.at<double>(deptx,depty);
    if(distance2_2!=0) count_valid+=1;
    distance2_3=dept.at<double>(std::min(297,deptx+1),depty);
    if(distance2_3!=0) count_valid+=1;
    distance3_1=dept.at<double>(std::max(0,deptx-1),std::min(169,depty+1));
    if(distance3_1!=0) count_valid+=1;
    distance3_2=dept.at<double>(deptx,std::min(169,depty+1));
    if(distance3_2!=0) count_valid+=1;
    distance3_3=dept.at<double>(std::min(297,deptx+1),std::min(169,depty+1));
    if(distance3_3!=0) count_valid+=1;
    distance=(distance1_1+distance1_2+distance1_3+
              distance2_1+distance2_2+distance2_3+
              distance3_1+distance3_2+distance3_3)/count_valid;
    //distance=dept.at<double>(deptx,depty);
#ifdef DEBUG
    if (distance == 0) {
                        std::cout << "(linear_align)_fail to get distance / distance = 0" << std::endl;
                }
#endif //!DEBUG
    return distance;
}

void send_control::send_robot_info_clear(send_robot_info& robot) {
	robot.robot_id = 0; 
	robot.angle_hori = 0;   
	robot.angle_verti = 0;   
	robot.Pixel_X = 0; 
	robot.Pixel_Y = 0; 
	robot.Pixel_width = 0;    
	robot.Pixel_height = 0;   
	robot.distance = 0;  
	robot.prob = 0; }

void send_control::to_black_board_clear() { for (int i = 0; i < max_num_robot; i++)
{	this->send_robot_info_clear(this->to_black_board.robot_info[i]); } }

void send_control::to_gimbal_clear() {
	this->to_gimbal.infochecker = 0;  //if 0: no data, 1: target, 2: area of interest
	this->to_gimbal.Pixel_X = 0;
	this->to_gimbal.Pixel_Y = 0;
	this->to_gimbal.distance = 0; }

void send_control::send_data_clear() {
	this->to_black_board_clear();
	this->to_gimbal_clear(); }

void send_control::angle_maker(short& hori, short& verti, data_control& CT_data, int i) {	// 손봐야 함!!!!!!!!!
// realsense data (Dapth) hori angle 65.2 verti angle 58 diagonal 94 error +-3 >> during experiment, we find that angle of verti is 54.5
// RGB viewing angle horiangle 69.4 veri angle 42.5 diagonal 77 erroe +-3
// but we need only RGB angle 
// 60degree * pi/180 = radian. 
// 60degree = radian*180/pi
// minus is left and bottom 
// plus is right and top 
// if data type is short, 4301 means 43.01 degree
	if (CT_data.dataset.Center_X[i] == 0 || CT_data.dataset.Center_Y[i] == 0 || CT_data.dataset.width[i] == 0 || CT_data.dataset.height[i] == 0) {
		hori = 0;
		verti = 0;
		return;
	}
	short Width = imgWidth * 0.5;
	short Height = imgHeight * 0.5; //  input half of piexl data
		
	double a = 54.5*0.5 * 3.14159 / 180;
	double hehe;
	double x;

	if (CT_data.dataset.Center_X[i] < (Width)) {
		hehe = (Width - CT_data.dataset.Center_X[i])*tan(a) / Width;
		x = atan(hehe);
		hori = (-1 * (x * 100)) * 180 / 3.14159;  //minus is left
	}
	else if (CT_data.dataset.Center_X[i] == Width) {
		hori = 0;
	}
	else {
		hehe = (CT_data.dataset.Center_X[i] - Width)*tan(a) / Width;
		x = atan(hehe);
		hori = 1 * (x * 100) * 180 / 3.14159;  //pluse is right 
	}

	if (CT_data.dataset.Center_Y[i] < (Height)) {
		hehe = (Height - CT_data.dataset.Center_Y[i])*tan(a * 0.75) / Height;
		x = atan(hehe);
		verti = 1 * (x * 100) * 180 / 3.14159;
	}
	else if (CT_data.dataset.Center_Y[i] == (Height)) {
		verti = 0;
	}
	else {
		hehe = (CT_data.dataset.Center_Y[i] - Height)*tan(a * 0.75) / Height;
		x = atan(hehe);
		verti = -1 * (x * 100) * 180 / 3.14159;
	}
}
void send_control::send_black_board_maker(data_control& CT_data) {
	for (int i = 0; i < CT_data.dataset.number_of_robot; i++) {
		this->to_black_board.robot_info[i].robot_id = CT_data.dataset.robot_id[i];
		this->angle_maker(this->to_black_board.robot_info[i].angle_hori, this->to_black_board.robot_info[i].angle_verti, CT_data ,i);
		this->to_black_board.robot_info[i].Pixel_X = CT_data.dataset.Center_X[i];
		this->to_black_board.robot_info[i].Pixel_Y = CT_data.dataset.Center_Y[i];
		this->to_black_board.robot_info[i].Pixel_width = CT_data.dataset.width[i];
		this->to_black_board.robot_info[i].Pixel_height = CT_data.dataset.height[i];
		this->to_black_board.robot_info[i].prob = CT_data.dataset.prob[i];
		this->to_black_board.robot_info[i].distance = CT_data.dataset.distance[i];
	}
} 

void send_control::send_gimbal_maker(data_control& CT_data) {
	send_target_info best_target;
	int infochecker = 0;	// 아군=1, 적군=2, 죽음=3. 1번=4, 2번=5, 1번적군=6, 2번적군=7
	int target = 0;
	double target_area = 0;
	int robot_check = 0;
	if(CT_data.dataset.armour.number_of_armour>0) {	// 적아머
		infochecker = 3;
		target_area = CT_data.dataset.armour.width[target] * CT_data.dataset.armour.height[target];
		for(int i=0; i<CT_data.dataset.armour.number_of_armour; i++) {
			if (target_area < CT_data.dataset.armour.width[target] * CT_data.dataset.armour.height[target]) {
				target = i;
				target_area = CT_data.dataset.armour.width[target] * CT_data.dataset.armour.height[target];
			}
		}
		best_target.Pixel_X = CT_data.dataset.armour.Center_x[target];
		best_target.Pixel_Y = CT_data.dataset.armour.Center_y[target];
		best_target.distance = CT_data.dataset.armour.distance[target];
		if(CT_data.dataset.armour.armour_id[target] == num1_id) {robot_check = num1_enemy_id;}
		else if(CT_data.dataset.armour.armour_id[target] == num2_id) {robot_check = num2_enemy_id;}
		for(int i=0; i<CT_data.dataset.number_of_robot;i++) {
			if(CT_data.dataset.robot_id[i] == robot_check) {
				best_target.robot_center_x = CT_data.dataset.Center_X[i];
                                best_target.robot_center_y = CT_data.dataset.Center_Y[i];
                                best_target.robot_distance = CT_data.dataset.distance[i];
				best_target.robot_box_width = CT_data.dataset.width[i];
				infochecker = 1;
				break;
			}
		}
	}
	else if(CT_data.dataset.number_of_robot>0) {
		for(int i=0; i<CT_data.dataset.number_of_robot; i++) {
			if(CT_data.dataset.robot_id[i] == enemy_id || CT_data.dataset.robot_id[i] == num1_enemy_id || CT_data.dataset.robot_id[i] == num2_enemy_id) {
				infochecker = 2;
				if(target_area < CT_data.dataset.width[i] * CT_data.dataset.height[i]) {
					target = i;
					target_area = CT_data.dataset.width[i] * CT_data.dataset.height[i];
				}
				best_target.Pixel_X = CT_data.dataset.Center_X[target];
				best_target.Pixel_Y = CT_data.dataset.Center_Y[target];
				best_target.distance = CT_data.dataset.distance[target];
			}
		}
	}
	best_target.infochecker = infochecker;
	this->to_gimbal = best_target;
}

void send_control::send_data_maker(data_control& CT_data) {
	this->to_black_board_clear();
	this->to_gimbal_clear();
	this->send_black_board_maker(CT_data);
	this->send_gimbal_maker(CT_data);
}

#endif // !DATA_CONTROL_HPP
