//V3.01
#pragma once
#ifndef OBJECT_DETECTION_HPP
#define OBJECT_DETECTION_HPP


#include "pch.hpp"
#include "yolo_class.hpp"
#include "Data_control.hpp"
#include "camera.hpp"


class vision_detector {
private:

	std::string  names_file;
	std::string  cfg_file;
	std::string  weights_file;
	static std::vector<bbox_t> detect_Data;
	static std::vector<std::string> obj_names;
	/*filename maker*/
	std::vector<std::string> objects_names_from_file(std::string const filename) {
		std::ifstream file(filename);
		std::vector<std::string> file_lines;
		if (!file.is_open()) return file_lines;
		for (std::string line; getline(file, line);) file_lines.push_back(line);
		std::cout << "object names loaded \n";
		return file_lines;
	}
	static darknet::Detector abc;

	/*drawing box*/
	static void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names,int current_det_fps = -1, int current_cap_fps = -1)
	{
		int const colors[6][3] = { { 1,0,1 },{ 0,0,1 },{ 0,1,1 },{ 0,1,0 },{ 1,1,0 },{ 1,0,0 } };

		for (auto &i : result_vec) {
			cv::Scalar color = darknet:: obj_id_to_color(i.obj_id);
			cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);
			if (obj_names.size() > i.obj_id) {
				std::string obj_name = obj_names[i.obj_id];
				if (i.track_id > 0) obj_name += " - " + std::to_string(i.track_id);
				cv::Size const text_size = getTextSize(obj_name, cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, 2, 0);
				int const max_width = (text_size.width > i.w + 2) ? text_size.width : (i.w + 2);
				cv::rectangle(mat_img, cv::Point2f(std::max((int)i.x - 1, 0), std::max((int)i.y - 30, 0)),
					cv::Point2f(std::min((int)i.x + max_width, mat_img.cols - 1), std::min((int)i.y, mat_img.rows - 1)),
					color, CV_FILLED, 8, 0);
				putText(mat_img, obj_name, cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(0, 0, 0), 2);
			}
		}
		if (current_det_fps >= 0 && current_cap_fps >= 0) {
			std::string fps_str = "FPS detection: " + std::to_string(current_det_fps) + "   FPS capture: " + std::to_string(current_cap_fps);
			putText(mat_img, fps_str, cv::Point2f(10, 20), cv::FONT_HERSHEY_COMPLEX_SMALL, 1.2, cv::Scalar(50, 255, 0), 2);
		}
	}

	/*detecting*/
	static void CUDA_Detect_VisionDataet(std::vector<bbox_t> detect_Data, VisionDataset& dataset) {

		int count_enemy = 0;
		int detection_num = 0;
		for (auto &i : detect_Data) {
			//cv::Scalar color = obj_id_to_color(i.obj_id);
			//cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);  // doesn`t used
			if (i.prob > confThreshold) {
				if (i.obj_id == enemy_id) {
					count_enemy = count_enemy + 1;
					detection_num = detection_num + 1;
					if (detection_num < 6) {
						dataset.height[detection_num] = i.h;
						dataset.width[detection_num] = i.w;
						dataset.Center_X[detection_num] = i.x + 0.5 * (i.w);
						dataset.Center_Y[detection_num] = i.y + 0.5 * (i.h);
						dataset.prob[detection_num] = i.prob;
						dataset.robot_id[detection_num] = 2; //enemy
					}
				}
				else if (i.obj_id == alliance_id) {
					detection_num = detection_num + 1;
					dataset.height[detection_num] = i.h;
					dataset.width[detection_num] = i.w;
					dataset.Center_X[detection_num] = i.x + 0.5*(i.w);
					dataset.Center_Y[detection_num] = i.y + 0.5*(i.h);
					dataset.robot_id[detection_num] = 1; //alliance

				}
				else if (i.obj_id == dead_id) {
					detection_num = detection_num + 1;
					dataset.height[detection_num] = i.h;
					dataset.width[detection_num] = i.w;
					dataset.Center_X[detection_num] = i.x + 0.5*(i.w);
					dataset.Center_Y[detection_num] = i.y + 0.5*(i.h);
					dataset.robot_id[detection_num] = 3; //dead robot

				}
			}
		}
		dataset.number_of_detection = detection_num;
	}


public:
	/*detector initialize*/
	vision_detector() {
#ifndef VIRTUAL
		names_file = "/home/nvidia/CLionProjects/vision_dev/yolo/yolo3.names";// class file path (name of objects)
		cfg_file = "/home/nvidia/CLionProjects/vision_dev/yolo/yolov3.cfg";  //cfg File and weights File path setting
		weights_file = "/home/nvidia/CLionProjects/vision_dev/yolo/yolov3-tiny.backup";
		darknet::Detector abc(cfg_file, weights_file);
		abc.nms = nmsThreshold;
		std::vector<std::string> obj_names = objects_names_from_file(names_file);
#else
		//GZbot code insert (GZbot yolo wighte file pate is needed)
		names_file = "/home/nvidia/CLionProjects/vision_dev/yolo/yolo3.names";// class file path (name of objects)
		cfg_file = "/home/nvidia/CLionProjects/vision_dev/yolo/yolov3.cfg";  //cfg File and weights File path setting
		weights_file = "/home/nvidia/CLionProjects/vision_dev/yolo/yolov3-tiny.backup";  
		darknet::Detector abc(cfg_file, weights_file);
		abc.nms = nmsThreshold;
		std::vector<std::string> obj_names = objects_names_from_file(names_file);
#endif //!VIRTUAL
#ifdef DEBUG
		std::cout << "vision_detector initialized" << std::endl;
#endif
	}

	~vision_detector() = default;
	
	static void vision_detector_run(data_control& CT_data) {


		CT_data.runing_initialize(); //clear data before running
		detect_Data = abc.detect(CT_data.dataset.detectimg , 0.2, false);

#ifdef DISPLAY
		draw_boxes(CT_data.dataset.display, detect_Data, obj_names);  //for display drowing boxed
#endif !DISPLAY

		CUDA_Detect_VisionDataet(detect_Data , CT_data.dataset); // input detection data
		CT_data.VisionDataset_KCFCORMaker();  //left top X and Y coordinate maker
		CT_data.armour_assign(detect_Data); //assign armour to each robot;
		vision_camera::VisionDataset_getDepth(CT_data);  //insert distance of each robot

#ifdef DISPLAY
		cv::imshow("Display window" , CT_data.dataset.display);
#endif //!DISPLAY

	}

};

#endif