// lib integrated header File

#ifndef PCH_HPP
#define PCH_HPP


/* header management */


//darknet.h heder file
#include "/home/nvidia/robomaster_extra/darknet/include/yolo_v2_class.hpp"


//cpp basic header file
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <atomic>
#include <mutex>
#include <algorithm>
#include <cstring>     // using for KCF tracker
#include <exception>
#include <math.h> // for calculate detection anlge control


//deeplearning and opencv basic header file (opencv version 3.4.5)
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>

//KCFtraking header file
#include <opencv2/opencv.hpp>
#include <opencv2/tracking.hpp>  //need to install opencv_contrib 
#include <opencv2/core/ocl.hpp>


//realsense header file
#include <librealsense2/rs.hpp>
#include <librealsense2/rsutil.h>

/* structure management*/
//the most used struct for this program (it contain w,h and center data, img, distance)
struct VisionDataset {

	bool Detection;

	cv::Mat detectimg;  //opencv color img 
	cv::Mat afterimg;
	cv::Mat display;

	short number_of_detection = 0;  
	short how_old = 0;
	short Center_X[3] = { 0,0,0 };  // this dataset can store maximun 3 robot
	short Center_Y[3] = { 0,0,0 };

	double height[3] = { 0,0,0 };
	double width[3] = { 0,0,0 };

	double KCF_X[3] = { 0,0,0 };
	double KCF_Y[3] = { 0,0,0 };

	double distance[3] = { 0,0,0 };

	double KCF_X_old[3] = { 0,0,0 };  
	double KCF_Y_old[3] = { 0,0,0 };

	short trakcer_data[3] = {4,4,4};


};

/*robot info*/
struct Sendinfo {

	bool infochecker = false;
	short angle_hori = 0;   // based on center line left is minus, righet is pluse
	short angle_verti = 0;   // based on center line upper is plus lower is minus  
	short Pixel_X = 0;
	short Pixel_Y = 0;
	short Pixel_width = 0;     //pixel coordinate`s width 
	short Pixel_height = 0;    //pixel coordinate`s width 
	short real_width = 0;  // real width
	short real_height = 0; // real height
	float distance = 0;  //it is based on mter 
	short assinged_number = 0;

};


/*dataset for send to ROS*/
struct sendDataset {

	short number_of_detection = 0;
	Sendinfo sendinfo[3];


};

/* static value managemnet*/
const float PI = 3.141592;
const float confThreshold = 0.5; // Confidence threshold
const float nmsThreshold = 0.4;  // Non-maximum suppression threshold
const int inpWidth = 416;  // Width of network's input image
const int inpHeight = 416; // Height of network's input image
const unsigned int enemy_id = 0;   //enemy ID
#endif