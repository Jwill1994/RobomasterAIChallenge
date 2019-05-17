//v4.0
#pragma once 
#ifndef PCH_HPP
#define PCH_HPP
#define US_BLUE // rosparam으로 어케 해야할지 모르겠음... define이 안되어 있으면 우리는 RED인걸로
#define OPENCV // using for yolo_class.hpp
//cpp basic header file
//#include <filesystem>  //for c++17
//#include <experimental/filesystem>  //for c++14
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <cmath>
#include <thread>
#include <atomic>
#include <mutex>
#include <algorithm>
#include <cstring>     // using for KCF tracker
#include <exception>
#include <math.h> // for calculate detection anlge control
#include <condition_variable>
#include "yolo_class.hpp" //need to include it 


//deeplearning and opencv basic header file (opencv version 3.4.5)
#include <opencv2/opencv.hpp>
#include <opencv2/core/version.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#ifdef MAKEING_IMG
#include <opencv2/videoio/videoio.hpp>
#endif //!MAKEING_IMG
#ifndef VIRTUAL
#include <opencv2/tracking.hpp>  //need to install opencv_contrib 
#include <opencv2/core/ocl.hpp>
#endif
//realsense header file
#include <librealsense2/rs.hpp>
#include <librealsense2/rsutil.h>

/*Yolo v3-tiny 3classes*/
const std::string  names_file = "/home/nvidia/weights/yolov3-tiny_3c_with640480/obj.names";
const std::string  cfg_file = "/home/nvidia/weights/yolov3-tiny_3c_with640480/yolov3-tiny_224_224.cfg";
const std::string  weights_file = "/home/nvidia/weights/yolov3-tiny_3c_with640480/yolov3-tiny_224_224.backup";

bool get_data = false;      // Used to make loop go only when image is received
const int imgWidth = 640;   // Width of network's input image
const int imgHeight = 480;  // Height of network's input image
const float PI = 3.14159265358979323846;
//const float confThreshold = 0.3; // Confidence threshold
const float confThreshold = 0.1; // Confidence threshold
const float nmsThreshold = 0.4;  // Non-maximum suppression threshold

//creat datatype red_bluesum (to return redsum, bluesum)
typedef struct{
    float redsum;
    float bluesum;
}red_bluesum;

/* static value managemnet*/
const int max_num_armour=6; // dead armour needs to be seen
const int max_num_robot=3;

// 아군=1, 적군=2, 죽음=3, 공격할_적군=4, 아머1=5, 아머2=6, dead_armour=7, robot_id=8
const unsigned int alliance_id = 1;
const unsigned int enemy_id = 2;
const unsigned int dead_id = 3;
const unsigned int engage_enemy_id = 4;
const unsigned int num1_id = 5;
const unsigned int num2_id = 6;
const unsigned int dead_armour_id = 7;
const unsigned int robot_id = 8;

const std::string robot_str = "robot";
const std::string blue_num1_str = "#1_blue";
const std::string blue_num2_str = "#2_blue";
const std::string red_num1_str = "#1_red";
const std::string red_num2_str = "#2_red";
const std::string dead_num1_str = "#1_dead";
const std::string dead_num2_str = "#2_dead";

#endif
