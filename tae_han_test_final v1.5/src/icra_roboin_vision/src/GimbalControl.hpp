
//#ifdef ROS
#define SETTING
#include <time.h>
#include "icra_roboin_msgs/PitchGain.h"
#include "icra_roboin_msgs/YawGain.h"
#include "icra_roboin_msgs/XYOffset.h"
#include "icra_roboin_msgs/YoloDetectionInfo.h"
#include "roborts_msgs/GimbalAngle.h"
#include "roborts_msgs/ShootCmd.h"
#include "roborts_msgs/FricWhl.h"
// #include "obstacle_detector/Obstacles.h" // TODO check again
#include "ros/ros.h"
//#include "SendData_Control.hpp"
#include "pch.hpp"
#include <cstdio>
#include <math.h>
#include "Data_control.hpp"

#include <fstream>  // https://ra2kstar.tistory.com/147, https://goscala.tistory.com/7
#include <random>  // http://www.cplusplus.com/reference/random/normal_distribution/

#define X_CENTER_PIXEL 320
#define Y_CENTER_PIXEL 240

//#define X_CENTER_PIXEL 212
//#define Y_CENTER_PIXEL 120

#define SEARCH_COUNT 20
#define ONE_EXP_LOOP 200


using namespace std;

class GimbalControl {

private:
    ros::Publisher cmd_gimbal_angle_pub;
    ros::ServiceClient cmd_shoot_client;

    ros::ServiceServer yaw_server;
    ros::ServiceServer pitch_server;
    ros::ServiceServer offset_server;
    unsigned int start_time;
    unsigned ziggletime;
    float prev_pitch_cmd = -1;
    int cntt = 0;
    float YAW_P_GAIN;
    float YAW_I_GAIN;
    float YAW_D_GAIN;
    float PITCH_P_GAIN;
    float PITCH_I_GAIN;
    float PITCH_D_GAIN;

    //float yaw_gains[2][3] = {{0.00045, 0.000006, 0.000203}, {0.0005, 0.0000003, 0.00103}};
    float yaw_gains[2][3] = {{0.00038, 0.00001, 0.00001}, {0.000036, 0.00000001, 0.00000005}};  // 기본값 0.0038 0.00001 0.00001

    float SEARCH_VEL = 0.08;  // SEARCH_VEL * SEARCH_COUNT = total angle (1.5~1.7)
    bool setCenter = false;
    int search_count = 0;
    short search_dir = 1;
    short lost_count = 0;
    short lidar_detect = 0;
    float out_sight_enemy_angle = 0;

    short yaw_prev_error = 0;
    short pitch_prev_error = 0;
    float yaw_i_error = 0;
    float pitch_i_error = 0;
    roborts_msgs::GimbalAngle gimbal_angle;
    float current_angle = 0.0;  //for sentry

    int x_offset = -5;  //plus -> aim right
    int y_offset = 5;  //minus -> aim up
    void cmdShoot(int shoot);
    void sentry();
    void calc_offset(float dist);
    unsigned int current_time = 0;
    unsigned int prev_time = 0;


    //기동 판단
//    bool evasion_move = false;
    short movement_type = 0;  // 0: linear motion  1: rotational motion  2: stop??
    short evasion_count = 0;
    short evasion_reset_count = 0;
    short diff = 0;
    short prev_diff = 0;
    void check_movement(send_target_info& target);
    short calculate_diff(short robot_center_x, short robot_box_width, short armor_center_x);
#define evasion_judge 3
#define move_thres 0.10
#define evasion_reset_judge 5


#ifdef SETTING
/*
    int loop_count = 0;
    float min_p = 0;
    float min_i = 0;
    float min_d = 0;
    unsigned int min_cost = 1000000000;
    unsigned int cost = 0;

    float v_p = 0.00005;
    float v_i = 0.00005;
    float v_d = 0.00005;

    default_random_engine generator;
    float generate_random(float gain, float v);
    std::normal_distribution<float> random_yaw_p(float yaw_p_gain, float v);
    std::normal_distribution<float> random_yaw_i(this->YAW_I_GAIN, 0.0001);
    std::normal_distribution<float> random_yaw_d(this->YAW_D_GAIN, 0.0001);
*/
    bool SetOffsetCallback(icra_roboin_msgs::XYOffset::Request &req, icra_roboin_msgs::XYOffset::Response &resp);
    bool SetYawGainCallback(icra_roboin_msgs::YawGain::Request &req, icra_roboin_msgs::YawGain::Response &resp);
    bool SetPitchGainCallback(icra_roboin_msgs::PitchGain::Request &req, icra_roboin_msgs::PitchGain::Response &resp);

#endif


public:
    GimbalControl(ros::NodeHandle &nh) {
        cmd_gimbal_angle_pub = nh.advertise<roborts_msgs::GimbalAngle>("cmd_gimbal_angle", 1);
        cmd_shoot_client =  nh.serviceClient<roborts_msgs::ShootCmd>("cmd_shoot");

        // 0.0009 0.0004 0.002 -> good on 0428 morning
        YAW_P_GAIN = yaw_gains[0][0];
        YAW_I_GAIN = yaw_gains[0][1];
        YAW_D_GAIN = yaw_gains[0][2];
        //float yaw_gains[2][3] = {{0.00035, 0.000004, 0.000203}, {0.00025, 0.00000015, 0.0005}};
        PITCH_P_GAIN = 0.00058;
        PITCH_I_GAIN = 0.000001;
        PITCH_D_GAIN = 0.000001;
        start_time = clock();
#ifdef SETTING
        yaw_server = nh.advertiseService("yaw_gain", &GimbalControl::SetYawGainCallback, this);
        pitch_server = nh.advertiseService("pitch_gain", &GimbalControl::SetPitchGainCallback, this);
        offset_server = nh.advertiseService("xy_offset", &GimbalControl::SetOffsetCallback, this);

#endif
    
    }

    void run(send_target_info& target);

};

/*
        short infochecker = 0 ;  // 발견못함=0, 아머=1, 적로봇=2
        short Pixel_X = 0;
        short Pixel_Y = 0;
        float distance = 0;
        short robot_center_x = 0;
        short robot_box_width = 0;
*/

void GimbalControl::calc_offset(float dist) {
    if(dist!=dist) dist = 1.5; // 값 정하기
    x_offset = -5;
    y_offset = (int) (30 - 12.18*dist + 0.602*dist*dist);
    if(dist < 0.9) y_offset = 30;
    //printf("y offset: %d\n", y_offset);
}


void GimbalControl::sentry() {
    if(!setCenter)  {
        //printf("set Center\n");
        YAW_P_GAIN = yaw_gains[1][0];
        YAW_I_GAIN = yaw_gains[1][1];
        YAW_D_GAIN = yaw_gains[1][2];

        gimbal_angle.pitch_mode = false;
        gimbal_angle.pitch_angle = 0;
        gimbal_angle.yaw_mode = false;
        gimbal_angle.yaw_angle = 0;
        current_angle = 0;
        this->cmd_gimbal_angle_pub.publish(gimbal_angle);
        setCenter = true;
    } else {
        //printf("sentry mode\n");
        gimbal_angle.pitch_mode = false;
        gimbal_angle.pitch_angle = 0;
        gimbal_angle.yaw_mode = false;
        current_angle += SEARCH_VEL * search_dir;
        gimbal_angle.yaw_angle = current_angle;
        this->cmd_gimbal_angle_pub.publish(gimbal_angle);
    }

    if (current_angle >= SEARCH_VEL * SEARCH_COUNT || current_angle <= -SEARCH_VEL * SEARCH_COUNT) {
        search_dir *= -1;
        search_count = 0;
        //printf("--------------direction change----------\n");
    }
    search_count++;
}



void GimbalControl::check_movement(send_target_info& target) {
    //printf("%f %f %f\n", this->YAW_P_GAIN, this->YAW_I_GAIN, this->YAW_D_GAIN);
    diff = this->calculate_diff(target.robot_center_x, target.robot_box_width, target.Pixel_X);
    //printf("box width: %d\n", target.robot_box_width);

    if(prev_diff*diff==-1) {
        evasion_count++;
        prev_diff = diff;
        evasion_reset_count = 0;
        //printf("evasion move?: %d\n", evasion_count);
        if(evasion_count >= evasion_judge) {
            movement_type = 1;
            printf("!!!!evasion move detected!!!! \n");
            this->YAW_P_GAIN = this->yaw_gains[movement_type][0];
            this->YAW_I_GAIN = this->yaw_gains[movement_type][1];
            this->YAW_D_GAIN = this->yaw_gains[movement_type][2];

        }

    } else {
        evasion_reset_count++;
        if(evasion_reset_count >= evasion_reset_judge) {
            movement_type = 0;
            evasion_count = 0;
            // printf("reset evasion count\n");
            this->YAW_P_GAIN = this->yaw_gains[movement_type][0];
            this->YAW_I_GAIN = this->yaw_gains[movement_type][1];
            this->YAW_D_GAIN = this->yaw_gains[movement_type][2];
        }
    }
    prev_diff = diff;
}

short GimbalControl::calculate_diff(short robot_center_x, short robot_box_width, short armor_center_x) {

    short diff_dir;
    if(armor_center_x - robot_center_x > (robot_box_width/2) * move_thres) diff_dir = 1;
    else if(armor_center_x - robot_center_x < -(robot_box_width/2) * move_thres) diff_dir = -1;
    else diff_dir = 0;

    return diff_dir;
}


void GimbalControl::cmdShoot(int shoot) { // 1: shoot, 0: stop
    roborts_msgs::ShootCmd shoot_cmd;
    shoot_cmd.request.mode = shoot;
    shoot_cmd.request.number = shoot;

    if (cmd_shoot_client.call(shoot_cmd)) {
        ROS_INFO("shoot Call Success");
        if(shoot_cmd.response.received == true){
            ROS_INFO("shoot call Received");
        } else {
            ROS_WARN("shoot call Not Received");
        }
    } else {
        ROS_ERROR("shoot Call Fail");
    }
}



#ifdef SETTING


bool GimbalControl::SetOffsetCallback(icra_roboin_msgs::XYOffset::Request &req,
        icra_roboin_msgs::XYOffset::Response &resp) {

    if (req.x_offset != 0.0) this->x_offset = req.x_offset;
    if (req.y_offset != 0.0) this->y_offset = req.y_offset;

    //printf("x y offset: %d %d\n", this->x_offset, this->y_offset);

    resp.received = true;
    return true;
}


bool GimbalControl::SetYawGainCallback(icra_roboin_msgs::YawGain::Request &req,
                        icra_roboin_msgs::YawGain::Response &resp) {

    /*
    if (req.p != 0.0) this->YAW_P_GAIN = req.p;
    if (req.i != 0.0) this->YAW_I_GAIN = req.i;
    if (req.d != 0.0) this->YAW_D_GAIN = req.d;
    */

    if (req.p != 0.0) this->yaw_gains[0][0] = req.p;
    if (req.i != 0.0) this->yaw_gains[0][1] = req.i;
    if (req.d != 0.0) this->yaw_gains[0][2] = req.d;

    this->YAW_P_GAIN = this->yaw_gains[0][0];
    this->YAW_I_GAIN = this->yaw_gains[0][1];
    this->YAW_D_GAIN = this->yaw_gains[0][2];
    //("yaw pid: %f %f %f\n", this->YAW_P_GAIN, this->YAW_I_GAIN, this->YAW_D_GAIN);
    ROS_ERROR("new yaw pid: %f %f %f\n", this->YAW_P_GAIN, this->YAW_I_GAIN, this->YAW_D_GAIN);
    this->yaw_prev_error = 0;
    this->pitch_prev_error = 0;
    this->yaw_i_error = 0;
    this->pitch_i_error = 0;

    resp.received = true;
    return true;
}

bool GimbalControl::SetPitchGainCallback(icra_roboin_msgs::PitchGain::Request &req,
	icra_roboin_msgs::PitchGain::Response &resp) {

        if (req.p != 0.0) this->PITCH_P_GAIN = req.p;
	if (req.i != 0.0) this->PITCH_I_GAIN = req.i;
	if (req.d != 0.0) this->PITCH_D_GAIN = req.d;
	printf("pitch pid: %f %f %f\n", this->PITCH_P_GAIN, this->PITCH_I_GAIN, this->PITCH_D_GAIN);
	yaw_prev_error = 0;
	pitch_prev_error = 0;
	yaw_i_error = 0;
	pitch_i_error = 0;

        resp.received = true;
	return true;
}


#endif

void GimbalControl::run(send_target_info& target) {

//    printf("pixel control ready\n");

    if (target.infochecker > 0) {

        this->check_movement(target);
        //printf("pixel control start\n");
//		Sendinfo target = gimbal;



        short pixel_error_x = target.Pixel_X - X_CENTER_PIXEL + x_offset;     //plus -> aim right
        short pixel_error_y = target.Pixel_Y - Y_CENTER_PIXEL + y_offset;     //minus -> aim up

        ofstream outputStream;
        outputStream.open("/home/nvidia/roboinTX2/src/icra_roboin_vision/output.csv", fstream::out | fstream::app);
        outputStream << clock() - start_time << "," << target.robot_center_x << "," << target.robot_center_y << "," << target.robot_distance << "," << target.Pixel_X << "," << target.Pixel_Y << "," << target.distance << endl;
        cout << cntt << " " << clock() - start_time << ", " << target.robot_center_x << ", " << target.robot_center_y << ", " << target.robot_distance << "," << target.Pixel_X << "," << target.Pixel_Y << "," << target.distance << endl;
        outputStream.close();
        cntt++;

        //printf("distance: %f\n", target.distance);
        //printf("x error: %d\n", pixel_error_x);
        //printf("y error: %d\n", pixel_error_y);
        //printf("PIXEL_Y: %d, Y_CENTER_PIXEL: %d, y_offset: %d\n", target.Pixel_Y, Y_CENTER_PIXEL, y_offset);

//        this->calc_offset(target.distance);

        if(pixel_error_x < target.robot_box_width*0.3 && pixel_error_x > -target.robot_box_width*0.3) {
//            printf("shoot!!!!\n");
            //cmdShoot(1);
        } else {
            //cmdShoot(0);
            //printf("no shoot!!!!\n");
        }

        // std::cout <<"target: " <<target.assinged_number<<std::endl;

        this->current_time = clock() % 10000000000;
//        printf("current: %d\n", this->current_time);
	if(this->prev_time == 0) {
		this->prev_time = this->current_time;
		return;
	}
        float dt = (this->current_time - this->prev_time) / 10000;
        //printf("dt: %d\n", dt);
        if(pixel_error_x < X_CENTER_PIXEL * 0.5 && pixel_error_x > -X_CENTER_PIXEL * 0.5) this->yaw_i_error += pixel_error_x * dt;
        if(pixel_error_y < Y_CENTER_PIXEL * 0.5 && pixel_error_y > -Y_CENTER_PIXEL * 0.5) this->pitch_i_error += pixel_error_y * dt;

        // pid
        float angle_cmd = -pixel_error_x * this->YAW_P_GAIN - this->yaw_i_error * this->YAW_I_GAIN + (this->yaw_prev_error - pixel_error_x) * this->YAW_D_GAIN / dt;

		//printf("error: %d d_error: %d cmd_angle: %f\n", pixel_error_x, this->yaw_prev_error - pixel_error_x, angle_cmd);
                //gimbal_angle.pitch_angle = pixel_error_y * PITCH_P_GAIN + pitch_i_error * PITCH_I_GAIN + (pitch_prev_error- pixel_error_y) * PITCH_D_GAIN;
        if (angle_cmd > 0.1) angle_cmd = 0.1;
        else if (angle_cmd < -0.1) angle_cmd = -0.1;
        this->gimbal_angle.yaw_angle = angle_cmd;


		//    gimbal_angle.yaw_angle = -pixel_error_x * YAW_P_GAIN;
        float pitch_cmd = pixel_error_y * this->PITCH_P_GAIN + this->pitch_i_error * this->PITCH_I_GAIN + (this->pitch_prev_error- pixel_error_y) * this->PITCH_D_GAIN / dt;
        if(pitch_cmd > 0.1) pitch_cmd = 0.1;
        else if(pitch_cmd < -0.1) pitch_cmd = -0.1;
        this->gimbal_angle.pitch_angle = pitch_cmd;

        if(this->prev_pitch_cmd < 0 && angle_cmd > 0) {
            unsigned int titi = clock() - ziggletime;
            printf("ziggletime: %d\n", titi);
            ziggletime = clock();
        }
        this->prev_pitch_cmd = angle_cmd;



        this->gimbal_angle.yaw_mode = true;
        this->gimbal_angle.pitch_mode = true;

        this->cmd_gimbal_angle_pub.publish(this->gimbal_angle);

        this->yaw_prev_error = pixel_error_x;
        this->pitch_prev_error = pixel_error_y;

        this->prev_time = this->current_time;
        lost_count = 0;
        setCenter = false;
    } else {

        cmdShoot(0);

        this->lost_count++;
        if(this->lost_count > 10) {
            this->lost_count = 11;
            cmdShoot(0);

            this->yaw_i_error = 0;
            this->pitch_i_error = 0;
            this->yaw_prev_error = 0;
            this->pitch_prev_error = 0;
            /*
            if(this->lidar_detect > 0) {
                this->gimbal_angle.pitch_mode = true; // not needed
                this->gimbal_angle.yaw_mode = false;

                this->gimbal_angle.yaw_angle = out_sight_enemy_angle;
                this->cmd_gimbal_angle_pub.publish(gimbal_angle);
            }
            */

            //this->sentry();

        }

    }
}


//#endif

