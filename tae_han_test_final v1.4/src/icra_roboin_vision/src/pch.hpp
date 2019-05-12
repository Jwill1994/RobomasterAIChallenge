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


/*
*
* /home/nvidia/weights/420_224_model_with_420_224_image/yolov3-tiny_420_224.backupcc
*
*
*/
/*Original Network*/
//const std::string  names_file = "/home/nvidia/CLionProjects/vision_dev/yolo/config_backup/yolo3.names";
//const std::string  cfg_file = "/home/nvidia/CLionProjects/vision_dev/yolo/config_backup/yolov3.cfg";
//const std::string  weights_file = "/home/nvidia/CLionProjects/vision_dev/yolo/config_backup/yolov3-tiny.backup";
	
/*Yolo v3-tiny 7classes*/
//const std::string  names_file = "/home/nvidia/weights/420_224_model_with_420_224_image/yolo3.names";
//const std::string  cfg_file = "/home/nvidia/weights/420_224_model_with_420_224_image/yolov3.cfg";
//const std::string  weights_file = "/home/nvidia/weights/420_224_model_with_420_224_image/yolov3-tiny_420_224.backup";

/*Yolo v3-tiny 3classes*/
const std::string  names_file = "/home/nvidia/weights/yolov3-tiny_3c/obj.names";
const std::string  cfg_file = "/home/nvidia/weights/yolov3-tiny_3c/yolov3-tiny_420_224.cfg";
const std::string  weights_file = "/home/nvidia/weights/yolov3-tiny_3c/yolov3-tiny_420_224.backup";

/*Yolo v2 3classes*/
//const std::string names_file = "/home/nvidia/weights/yolov2/obj.names";
//const std::string cfg_file="/home/nvidia/weights/yolov2/yolov2_test.cfg";
//const std::string weights_file= "/home/nvidia/weights/yolov2/yolov2.backup";


bool get_data = false;      // Used to make loop go only when image is received
const int imgWidth = 640;   // Width of network's input image
const int imgHeight = 480;  // Height of network's input image
const float PI = 3.141592;
//const float confThreshold = 0.3; // Confidence threshold
const float confThreshold = 0.1; // Confidence threshold
const float nmsThreshold = 0.4;  // Non-maximum suppression threshold

//creat datatype red_bluesum (to return redsum, bluesum)
typedef struct{
    float redsum;
    float bluesum;
}red_bluesum;

/* static value managemnet*/
const int max_num_armour=4;
const int max_num_robot=3;

// CV
// 아군=1, 적군=2, 죽음=3. 1번=4, 2번=5, 1번적군=6, 2번적군=7
const unsigned int alliance_id = 1;
const unsigned int enemy_id = 2;
const unsigned int dead_id = 3;
const unsigned int num1_id = 4;
const unsigned int num2_id = 5;
const unsigned int num1_enemy_id = 6;
const unsigned int num2_enemy_id = 7;

const std::string blue_str = "blue";
const std::string red_str = "red";
const std::string dead_str = "dead";
const std::string blue_num1_str = "#1_blue";
const std::string blue_num2_str = "#2_blue";
const std::string red_num1_str = "#1_red";
const std::string red_num2_str = "#2_red";
const std::string dead_num1_str = "#1_dead";
const std::string dead_num2_str = "#2_dead";
#endif