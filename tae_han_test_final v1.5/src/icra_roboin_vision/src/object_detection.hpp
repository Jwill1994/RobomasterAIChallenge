//v4.0
#pragma once
#ifndef OBJECT_DETECTION_HPP
#define OBJECT_DETECTION_HPP
#include "pch.hpp"
#include "yolo_class.hpp"
#include "Data_control.hpp"

using namespace darknet;

class vision_detector {
public:
    std::vector<bbox_t> detect_Data;
    std::vector<std::string> obj_names;
private:
	/*filename maker*/
	std::vector<std::string> objects_names_from_file(std::string const filename);
    /*red blue sum calculation*/
    red_bluesum redbluesum(cv::Mat input_img, int x, int y, int w, int h);
	/*drawing box*/
    cv::Mat draw_boxes(data_control& CT_data, cv::Mat mat_img, cv::Mat dept_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,int current_det_fps, int current_cap_fps);

public:
	/*detector initialize*/
	vision_detector(Detector& detector) {
        detector.nms = nmsThreshold;
		this->obj_names = this->objects_names_from_file(names_file);
#ifdef DEBUG
		std::cout << "vision_detector initialized" << std::endl;
#endif
	}
	~vision_detector() = default;
	void vision_detector_run(data_control& CT_data, Detector& detector);
};

std::vector<std::string> vision_detector::objects_names_from_file(std::string const filename) {
    std::ifstream file(filename);
    std::vector<std::string> file_lines;
    if (!file.is_open()) return file_lines;
    for (std::string line; getline(file, line);) file_lines.push_back(line);
    return file_lines;
}

red_bluesum vision_detector::redbluesum(cv::Mat input_img, int x, int y, int w, int h){
    red_bluesum result;
    cv::Rect region_of_interest = cv::Rect(x,y,w,h);
#ifdef VISION_DATACHECK
    std::cout << region_of_interest << std::endl;
#endif //!VISION_DATACHECK
    cv::Mat image_roi = input_img(region_of_interest);
    cv::Mat hsv;
    cvtColor(image_roi, hsv, CV_BGR2HSV);
    cv::Mat blue;
    cv::Mat red1;
    cv::Mat red2;
    cv::Mat red;
    /*===extract red pixel===*/
    cv::inRange(hsv, cv::Scalar(0, 100, 100,0), cv::Scalar(10, 255, 255,0), red1);
    cv::inRange(hsv, cv::Scalar(160, 100, 100,0), cv::Scalar(179, 255, 255,0), red2);
    red=red1 | red2;
    /*===extract blue pixel===*/
    cv::inRange(hsv, cv::Scalar(110,150,150,0),cv::Scalar(130,255,255,0),blue);

    result.bluesum=cv::sum(blue)[0];
    result.redsum=cv::sum(red)[0];

    return result;
}

cv::Mat vision_detector::draw_boxes(data_control& CT_data, cv::Mat mat_img, cv::Mat dept_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,int current_det_fps = -1, int current_cap_fps = -1)
{
    int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };
    cv::Mat boxed_img;
    boxed_img= mat_img.clone();
    for (auto &i : result_vec) {
        cv::Scalar color = darknet:: obj_id_to_color(i.obj_id);
#ifdef DISPLAY
        cv::rectangle(boxed_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
        cv::rectangle(dept_img, cv::Rect(i.x,i.y,i.w,i.h),0,2);
#endif //!DISPLAY
        if (obj_names.size() > i.obj_id) {
            std::string obj_name = obj_names[i.obj_id];
            if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
            cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
            int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
            if(obj_name=="robot") {
                red_bluesum result=this->redbluesum(mat_img,i.x,(int)(i.y+i.h/2),//i.w,(int)i.h/2);
                                                    std::min(i.w,mat_img.cols-i.x-1),
                                                    (int)(std::min(i.h/2,mat_img.cols-i.y-i.h/2-1)));
                float sumblue=result.bluesum;
                float sumred=result.redsum;
#ifdef VISION_DATACHECK
                std::cout<<"ROBOT sumblue/sumred: " << (sumblue+1)/(sumred+1) <<
                            " sumblue: "<<sumblue<<
                           " sumred: " <<sumred<<
                           std::endl;
#endif //!VISION_DATACHECK
                if(((sumblue+10000)/(sumred+10000)<2 && (sumblue+10000)/(sumred+10000)>0.5)||sumred==sumblue){
                    obj_name = dead_str;
                }
                else if (sumblue > sumred) {
                    obj_name = blue_str;
                }
                else if (sumblue < sumred) {
                    obj_name = red_str;
                }
            }
            if(obj_name=="number1" or obj_name=="number2"){
                red_bluesum result=this->redbluesum(mat_img,i.x,i.y,//i.w,i.h);
                                                    std::min(i.w,mat_img.cols-i.x-1),
                                                    std::min(i.h,mat_img.cols-i.y-i.h-1));
                float sumblue=result.bluesum;
                float sumred=result.redsum;
#ifdef VISION_DATACHECK
                std::cout<<"ARMOUR sumblue/sumred: " << (sumblue+1)/(sumred+1) <<
                            " sumblue: "<<sumblue<<
                           " sumred: " <<sumred<<
                           std::endl;
#endif //!VISION_DATACHECK
                if(obj_name=="number1"){
                    if(((sumblue+1000)/(sumred+1000)<2 && (sumblue+1000)/(sumred+1000)>0.5)||sumred==sumblue){
                        obj_name= dead_num1_str;
                    }
                    else if (sumblue > sumred) {
                        obj_name = blue_num1_str;
                    }
                    else if (sumblue < sumred) {
                        obj_name = red_num1_str;
                    }
                }
                if(obj_name=="number2"){
                    if(((sumblue+1000)/(sumred+1000)<2 && (sumblue+1000)/(sumred+1000)>0.5)||sumred==sumblue){
                        obj_name= dead_num2_str;
                    }
                    else if (sumblue > sumred) {
                        obj_name = blue_num2_str;
                    }
                    else if (sumblue < sumred) {
                        obj_name = red_num2_str;
                    }
                }
            }
#ifdef DISPLAY
            cv::rectangle(boxed_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
                          cv::Point2f(std::min((int)i.x + max_width, boxed_img.cols - 1), std::min((int)i.y, boxed_img.rows - 1)),
                          color, CV_FILLED, 8, 0);
            putText(boxed_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
#endif //!DISPLAY
            CT_data.assign_data(obj_name, i);   // 정보부여를 여기서 하기 --> 로봇정보들(파빨죽) + 아머정보(enemy) ////////////////////////////
	    // std::cout<<"after assign data\n";
        }
    }
    if (current_det_fps >= 0 && current_cap_fps >= 0) {
        std::string fps_str = "FPS detection: " + std::to_string(current_det_fps) + "   FPS capture: " + std::to_string(current_cap_fps);
        putText(mat_img, fps_str, cv::Point2f(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(50, 255, 0), 2);
    }
    CT_data.after_assign();     // 적로봇 1번 2번 구분
    return boxed_img;
}

void vision_detector::vision_detector_run(data_control& CT_data,Detector& detector) {
    CT_data.runing_initialize(); //clear data before running
    this->detect_Data = detector.detect(CT_data.dataset.detectimg , confThreshold, false);  // YOLO
#ifdef DEBUG
	std::cout << " detection finish " << std::endl;
#endif //!DEBUG

#ifdef REMOTE
    cv::Mat dept = CT_data.dataset.depth_img.clone();
#else
    /* for 424 x 240*/
    int start_x=50;
    int start_y=32;
    cv::Mat dept=CT_data.dataset.depth_img(cv::Rect(start_x,start_y,423-start_x-75,239-start_y-37));
    cv::resize(dept,dept,cv::Size(424,240));

    /* for 640 480*/


#endif //!REMOTE
    ///////////////// draw_boxes 꼭 해야함 거기다가 정보부여하는 함수 넣음!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cv::Mat boxed_img = this->draw_boxes(CT_data, CT_data.dataset.display, dept, this->detect_Data, this->obj_names);
#ifdef DISPLAY
    cv::imshow("Display window" , boxed_img);
    cv::imshow("Depth window", dept);
#endif //!DISPLAY
#ifdef DEBUG
	std::cout << " (vision_detector::vision_detector_run) vision_detector_run is worked " << std::endl;
#endif //!DEBUG
}
#endif