//v3.01
#pragma once
#ifndef DATA_CONTROL_HPP
#define DATA_CONTROL_HPP

#include "pch.hpp"

struct armour_data {   //need to change
	// if you learning, you should do max labeling obliqued label
	short dominant_armour = 0;
	short number_of_armer = 0;
	short armour_type[6] = { 0, 0, 0, 0, 0, 0 };
	double armour_confidence[6] = { 0, 0, 0, 0, 0, 0 };
	short Center_x[6] = { 0, 0, 0, 0, 0, 0 };
	short Center_y[6] = { 0, 0, 0, 0, 0, 0 };
	short width[6] = { 0, 0, 0, 0, 0, 0 };
	short height[6] = { 0, 0, 0, 0, 0, 0 };
	double distance[6] = { 0, 0, 0, 0, 0, 0 };
};

static struct VisionDataset {

	bool Detection;

	cv::Mat detectimg;  //opencv color img 
	cv::Mat afterimg;
#ifdef DISPLAY
	cv::Mat display;
#endif
	short number_of_detection = 0;
	short how_old = 0;
	short Center_X[6] = { 0,0,0,0,0,0 };  // this dataset can store maximun 3 robot
	short Center_Y[6] = { 0,0,0,0,0,0 };
	short robot_id[6] = { 0,0,0,0,0,0 };  //red or blue or die data will give  0= no_data , 1 = allay , 2= enemy , 3=dead

	double prob[6] = { 0, 0, 0, 0, 0, 0 };

	double height[6] = { 0,0,0,0,0,0 };
	double width[6] = { 0,0,0,0,0,0 };

	double KCF_X[6] = { 0,0,0,0,0,0 };  //left top x 
	double KCF_Y[6] = { 0,0,0,0,0,0 };  //left top y

	double distance[6] = { 0,0,0,0,0,0 };

	double KCF_X_old[6] = { 0,0,0,0,0,0 };
	double KCF_Y_old[6] = { 0,0,0,0,0,0 };

	short trakcer_data[6] = { 4,4,4,4,4,4 };

	armour_data armour[6];

};

/*for vision data control*/
class data_control {
private:
	static void armour_initialize(armour_data& armour) {
		armour.number_of_armer = 0;
		int index = 0;
		for (index = 0; index < 6; index++) {
			armour.armour_type[index] = 0;
			armour.armour_confidence[index] = 0;
			armour.Center_x[index] = 0;
			armour.Center_y[index] = 0;
			armour.width[index] = 0;
			armour.height[index] = 0;
			armour.distance[index] = 0;
			armour.dominant_armour = 0;
		}
	}
	static void VisionDataset_initialize(VisionDataset& dataset) {
		//delete detection information from frame 

		dataset.number_of_detection = 0;

		for (int index = 0; index < 6; index++) {

			dataset.Center_X[index] = 0;
			dataset.Center_Y[index] = 0;
			dataset.height[index] = 0;
			dataset.width[index] = 0;
			dataset.KCF_X[index] = 0;
			dataset.KCF_Y[index] = 0;
			dataset.distance[index] = 0;
			dataset.prob[index] = 0;
			dataset.robot_id[index] = 0;

			for (int i = 0; i < 6; i++) {
				armour_initialize(dataset.armour[index]);
			}
		}
#ifdef DEBUG
		std::cout << "(VisionDataset_initialize)_is worked" << std::endl;
#endif
	}
	static bool VisionDataset_checker(int numberofdetection) {
		// if there are no detection return true

		if (numberofdetection <= 0)
		{
#ifdef DEBUG
			std::cout << "(VisionDataset_checker)_numberofdetection is zero" << std::endl;
#endif
			return true;
		}

		return false;

	}
	
	bool First_tracking = true;

public:
	static VisionDataset dataset;

	/*data_control initialize*/
	data_control() {
		VisionDataset_initialize(dataset);

#ifdef DEBUG
		std::cout << "data_control initialized" << std::endl;
#endif //!DEBUG
	}
	~data_control() = default;

	/*clear the data set before detecting*/
	void runing_initialize() {
		VisionDataset_initialize(dataset);
		dataset.how_old = 0;
		First_tracking = true;
	}
	/*for tracking but doesn`t needed*/
	static void VisionDataset_continueTraking() {
		dataset.detectimg = dataset.afterimg;
		// copy new img to old img 
#ifdef DEBUG
		std::cout << "(VisionDataset_continueTraking) is worked" << std::endl;
#endif //!DEBUG
	}
	/*for making left top x and y corrdinate*/
	static void VisionDataset_KCFCORMaker()
		{
	
			int index;
			for (index = 0; index < 6; index++) {
				if (dataset.Center_X[index] > 0 && dataset.Center_Y[index] > 0) {
					dataset.KCF_X[index] = (dataset.Center_X[index]) - ((dataset.width[index]) * 0.5);
					dataset.KCF_Y[index] = (dataset.Center_Y[index]) - ((dataset.height[index]) * 0.5);
				}
			}
	#ifdef VISION_DATACHECK
			std::cout << "(VisionDataset_KCFCORMaker)" << "dataset.Center_X[0]:" << dataset.Center_X[0] << " dataset.Center_X[1]:" << dataset.Center_X[index] << " dataset.Center_X[2]:" << dataset.Center_X[2] << std::endl;
			std::cout << "(VisionDataset_KCFCORMaker)" << " dataset.KCF_X[0]:" << dataset.KCF_X[0] << " dataset.KCF_X[1]:" << dataset.KCF_X[1] << " dataset.KCF_X[2]:" << dataset.KCF_X[2] << std::endl;
	#endif
	}
	/*for assign armour each robot*/
	static void armour_assign(std::vector<bbox_t> detect_Data) {

		short index = 0;

		int number_of_armer = 0;

		for (auto &i : detect_Data) {

			//cv::Scalar color = obj_id_to_color(i.obj_id);

			//cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 2);  // doesn`t used

			if (i.prob > confThreshold && ((i.obj_id == Number1) || (i.obj_id == Number2))) {
				for (index = 1; index < 6; index++) {   //first we check the detected robot data and check only ememy

					if (dataset.Center_X[index] > 0 && dataset.Center_Y[index] > 0) {  //if there are no data, check next data

						if (dataset.KCF_X[index] < (i.x + 0.5*(i.w)) && dataset.KCF_Y[index] < (i.y + 0.5*(i.h)) && (i.x + 0.5*(i.w)) < (dataset.KCF_X[index] + dataset.width[index]) && (i.y + 0.5*(i.h)) < (dataset.KCF_Y[index] + dataset.height[index])) {
							dataset.armour[index].Center_x[number_of_armer] = i.x + 0.5*(i.w);
							dataset.armour[index].Center_y[number_of_armer] = i.y + 0.5*(i.h);
							dataset.armour[index].width[number_of_armer] = i.w;
							dataset.armour[index].height[number_of_armer] = i.h;
							dataset.armour[index].armour_type[number_of_armer] = i.obj_id;        //next using this data,configure enemy`s Id
							dataset.armour[index].armour_confidence[number_of_armer] = i.prob;
							dataset.armour[index].number_of_armer++;
						}
					}
#ifdef VISION_DATACHECK
					std::cout << "(armour_assign) Armour " << index << " founded Number of" << index << " :" << dataset.armour[index].number_of_armer << std::endl;
#endif
				}
			}
		}
	}
};

#ifdef BASIC_FUNCTION
/*for send data to Ros*/
#include "Vision_ros.hpp"

class send_control {
private:

public:
	send_control() {
	}
	~send_control() = default;

};



#ifdef VIRTUAL
class ImageConverter

{
private:

	image_transport::ImageTransport it_;
	image_transport::Subscriber image_sub_;
	cv_bridge::CvImagePtr cv_ptr_;
	bool is_new_img_;

public:
	ImageConverter(ros::NodeHandle nh) : it_(nh) {
		image_sub_ = it_.subscribe("simulated_image_topic", 1, &ImageConverter::imageCB, this);
	}
	~ImageConverter() = default;
	void imageCB(const sensor_msgs::ImageConstPtr& msg) {
		try {
			cv_ptr_ = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
			is_new_img_ = true;
		}
		catch (cv_bridge::Exception& e) {
			ROS_ERROR("cv_bridge exception: %s", e.what());
			return;
		}
	}
	cv::Mat GetImage() {
		while (is_new_img_);
		is_new_img_ = false;
		return cv_ptr_->image;
	}
};



class DepthConverter

{
private:

	image_transport::ImageTransport it_;

	image_transport::Subscriber image_sub_;

	cv_bridge::CvImagePtr cv_ptr_;
	bool is_new_img_;

public:

	DepthConverter(ros::NodeHandle nh) : it_(nh) {
		image_sub_ = it_.subscribe("simulated_depth_image_topic", 1, &DepthConverter::imageCB, this);
	}
	~DepthConverter() = default;

	void imageCB(const sensor_msgs::ImageConstPtr& msg) {
		try {
			cv_ptr_ = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_16UC1);
			is_new_img_ = true;
		}
		catch (cv_bridge::Exception& e) {
			ROS_ERROR("cv_bridge exception: %s", e.what());
			return;
		}
	}
	cv::Mat GetDepth() {
		while (is_new_img_);
		is_new_img_ = false;
		return cv_ptr_->image;
	}
	int getDepthdata(short x, short y) {
		return cv_ptr_->image.at<shrot int>(cv::Point(x, y));
	}

};

static float SIMUL
#endif //!VIRTUAL
#endif
#endif // !DATA_CONTROL_HPP
