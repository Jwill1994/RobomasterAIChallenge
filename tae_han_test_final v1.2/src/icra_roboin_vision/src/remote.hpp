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

public:
    ImageConverter(data_control* CT_data) : it_(nh_) {
        color_sub_ = it_.subscribe("/camera/color/image_raw", 1, &ImageConverter::imageColor, this);
        depth_sub_ = it_.subscribe("/camera/aligned_depth_to_color/image_raw", 1, &ImageConverter::imageDepth, this);
        CT_ptr = CT_data;
    }

    void imageColor(const sensor_msgs::ImageConstPtr& msg) {
        cv_bridge::CvImagePtr cv_ptr_color;
        try {
            cv_ptr_color = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            CT_ptr->dataset.detectimg = cv_ptr_color->image;
#ifdef DISPLAY
            CT_ptr->dataset.display = CT_ptr->dataset.detectimg.clone();	
#endif
        }
        catch (cv_bridge::Exception& e) {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }
    }

    void imageDepth(const sensor_msgs::ImageConstPtr& msg) {
        cv_bridge::CvImagePtr cv_ptr_depth;
        try {
            cv_ptr_depth = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_64FC1);
            cv::Mat dm = cv_ptr_depth->image;
            CT_ptr->dataset.depth_img = dm;
		// 16UC1 - short
		// 64FC1 - double

            get_data = true;
        }
            catch (cv_bridge::Exception& e) {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }
    }
};

#endif
