//v4.0
#pragma once
#ifndef REMOTE_HPP
#define REMOTE_HPP
#include "Data_control.hpp"
#include "pch.hpp"
#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

class ImageConverter {
    ros::NodeHandle nh_;
    image_transport::ImageTransport it_;
    image_transport::Subscriber color_sub_;
    image_transport::Subscriber depth_sub_;
    data_control* CT_ptr;
    int num_img = 1;
public:
    ImageConverter(data_control* CT_data) : it_(nh_) {
        color_sub_ = it_.subscribe("/camera/color/image_raw", 1, &ImageConverter::imageColor, this);
        depth_sub_ = it_.subscribe("/camera/depth/image_rect_raw", 1, &ImageConverter::imageDepth, this);
        CT_ptr = CT_data;
    }

    void imageColor(const sensor_msgs::ImageConstPtr& msg) {
        cv_bridge::CvImagePtr cv_ptr_color;
        try {
            cv_ptr_color = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            CT_ptr->dataset.detectimg = cv_ptr_color->image;
        }
        catch (cv_bridge::Exception& e) {ROS_ERROR("cv_bridge exception: %s", e.what()); return;}
    }
    void imageDepth(const sensor_msgs::ImageConstPtr& msg) {
        cv_bridge::CvImagePtr cv_ptr_depth;
        try {// 16UC1 - short // 64FC1 - double
            cv_ptr_depth = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_64FC1);
            cv::Mat dm = cv_ptr_depth->image;
            /*640X480*/
            dm =dm(cv::Rect(100,100,404,303));
            cv::resize(dm,dm,cv::Size(imgWidth,imgHeight));
            CT_ptr->dataset.depth_img = dm;
            get_data = true;
        }
        catch (cv_bridge::Exception& e) {ROS_ERROR("cv_bridge exception: %s", e.what()); return;}
    }
};
#endif
