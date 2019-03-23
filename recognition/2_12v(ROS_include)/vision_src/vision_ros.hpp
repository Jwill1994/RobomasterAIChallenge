

#ifdef ROS
#include "icra_roboin_msgs/PitchGain.h"
#include "icra_roboin_msgs/YawGain.h"
#include "roborts_msgs/GimbalAngle.h"
#include "roborts_msgs/ShootCmd.h"
#include "ros/ros.h"
#include "SendData_Control.hpp"

float YAW_P_GAIN = 0.0002;
float YAW_I_GAIN = 0.001;
float YAW_D_GAIN = 0.001;

float PITCH_P_GAIN = 0.001;
float PITCH_I_GAIN = 0.001;
float PITCH_D_GAIN = 0.001;

#define X_CENTER_PIXEL 320
#define Y_CENTER_PIXEL 240




float yaw_prev_error = 0;
float pitch_prev_error = 0;
float yaw_i_error = 0;
float pitch_i_error = 0;
roborts_msgs::GimbalAngle gimbal_angle;




bool SetYawGainCallback(icra_roboin_msgs::YawGain::Request &req,
                        icra_roboin_msgs::YawGain::Response &resp ) {
    if(req.p != 0.0) YAW_P_GAIN = req.p;
    if(req.i != 0.0) YAW_I_GAIN = req.i;
    if(req.d != 0.0) YAW_D_GAIN = req.d;

    resp.received = true;
    return true;
}

bool SetPitchGainCallback(icra_roboin_msgs::PitchGain::Request &req,
                          icra_roboin_msgs::PitchGain::Response &resp) {

    if(req.p != 0.0) PITCH_P_GAIN = req.p;
    if(req.i != 0.0) PITCH_I_GAIN = req.i;
    if(req.d != 0.0) PITCH_D_GAIN = req.d;

    resp.received = true;
    return true;
}


void rosPixelControl(int number_of_detection, Sendinfo& gimbal, ros::Publisher cmd_gimbal_angle_pub_) {
    if(number_of_detection > 0) {

        Sendinfo target = gimbal;

        short pixel_error_x = target.Pixel_X - X_CENTER_PIXEL;
        short pixel_error_y = target.Pixel_Y - Y_CENTER_PIXEL;

        yaw_i_error += pixel_error_x;
        pitch_i_error += pixel_error_y;

        // pid
//		gimbal_angle.yaw_angle = pixel_error_x * YAW_P_GAIN + yaw_i_error * YAW_I_GAIN + (yaw_prev_error - pixel_error_x) * YAW_D_GAIN;
//		gimbal_angle.pitch_angle = pixel_error_y * PITCH_P_GAIN + pitch_i_error * PITCH_I_GAIN + (pitch_prev_error- pixel_error_y) * PITCH_D_GAIN;

        gimbal_angle.yaw_angle = -pixel_error_x * YAW_P_GAIN;
        gimbal_angle.pitch_angle = pixel_error_y * PITCH_P_GAIN;

        gimbal_angle.yaw_mode = true;
        gimbal_angle.pitch_mode = true;

        cmd_gimbal_angle_pub_.publish(gimbal_angle);

        yaw_prev_error = pixel_error_x;
        pitch_prev_error = pixel_error_y;


    } else {
        yaw_i_error = 0;
        pitch_i_error = 0;

        yaw_prev_error = 0;
        pitch_prev_error = 0;
    }
}

#endif