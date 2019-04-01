//V3.01
#pragma once
#ifndef CAMERA_HPP
#define CAMERA_HPP


#include "pch.hpp"
#include "Data_control.hpp"
#include "Vision_ros.hpp"

#ifdef ADD_DEEPLEARNING
#include "object_detection.hpp"
#endif

class vision_camera
{
private:
	int Width = 640;
	int Height = 480;
#ifndef VIRTUAL
  //resolution of camera 640*480 is defult

	rs2::context ctx;
	rs2::device_list list;
	static rs2::colorizer color_map;
	rs2::pipeline pipe;
	static rs2::config cfg;
	static rs2::pipeline_profile profile;
	static rs2::video_frame color_frame;
	static rs2::depth_frame depth_frame;
	static cv::Mat frame_to_mat(const rs2::frame& f)
	{
		using namespace cv;
		using namespace rs2;

		auto vf = f.as<video_frame>();
		const int w = vf.get_width();
		const int h = vf.get_height();

		if (f.get_profile().format() == RS2_FORMAT_BGR8)
		{
			return Mat(Size(w, h), CV_8UC3, (void*)f.get_data(), Mat::AUTO_STEP);
		}
		else if (f.get_profile().format() == RS2_FORMAT_RGB8)
		{
			auto r = Mat(Size(w, h), CV_8UC3, (void*)f.get_data(), Mat::AUTO_STEP);
			cvtColor(r, r, CV_RGB2BGR);
			return r;
		}
		else if (f.get_profile().format() == RS2_FORMAT_Z16)
		{
			return Mat(Size(w, h), CV_16UC1, (void*)f.get_data(), Mat::AUTO_STEP);
		}
		else if (f.get_profile().format() == RS2_FORMAT_Y8)
		{
			return Mat(Size(w, h), CV_8UC1, (void*)f.get_data(), Mat::AUTO_STEP);
		}

		throw std::runtime_error("Frame format is not supported yet!");
	}
#else
	//GZbot code


#endif

	static float VisionDataset_avoid_zero(short x, short y) {
		//to use this function, x andy must be larger then 3 and smaler than Max-3
		float Depth = 0;
		float tem_Depth = 0;
		short i = 0;
		short j = 0;
		short count = 0;


		for (i = x; i < x + 3; i++) {

			for (j = y; j < y + 3; j++) {
				tem_Depth = depth_frame.get_distance((i - 1), (j - 1));

				if (tem_Depth > 0) {
					count++;
					Depth = Depth + tem_Depth;
				}
			}
		}

		if (count > 0) {

			Depth = Depth / count;
			return Depth;

		}
		else {
#ifdef DEBUG
			std::cout << "(VisionDataset_avoid_zero) distance is zero" << std::endl;
#endif

			return 0;
		}

	}


public:
#ifdef BASIC_FUNCTION
	ros::init(argc, argv, "vision_node");
	ros::NodeHandle nh;
#endif

	/*camera class init*/
	vision_camera() {
#ifndef VIRTUAL

		list = ctx.query_devices();
		if (list.size() == 0) {
			throw std::runtime_error("vision: Device not found");
		}

		cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);

		cfg.enable_stream(RS2_STREAM_COLOR, Width, Height, RS2_FORMAT_BGR8, 60);
		cfg.enable_stream(RS2_STREAM_DEPTH, Width, Height, RS2_FORMAT_Z16, 60);
		profile = pipe.start(cfg);
#ifdef DEBUG
		std::cout << "vision_camera initialized" << std::endl;
#endif !DEBUG

#else
// for GZbot code
		ImageConverter sim_img(nh);
		DepthConverter sim_depth(nh);

#endif !VIRTUAL
		}
	/*delete camera class*/
	~vision_camera() = default;

	/*running camera*/
	void vision_camera_run(data_control& CT_data) {

#ifndef VIRTUAL
		while (true) {
			rs2::frameset data = pipe.wait_for_frames();
			color_frame = data.get_color_frame();
			depth_frame = data.get_depth_frame();
			if (!depth_frame || !color_frame) {
				continue;  // frame check based on buffer
			}
			CT_data.dataset.detectimg = frame_to_mat(color_frame);


			break; //get new frame
		}
#else
		//insert GZbot code
		dataset.detectimg = sim_img.GetImage(); // ros image get
#endif !VIRTUAL

#ifdef DISPLAY
			CT_data.dataset.display = CT_data.dataset.detectimg; //making display image
#endif !DISPLAY

	}

	/*directly get distance data*/
	static float linial_align(short RGB_X, short RGB_Y) {
			// based on 3m > 6 pixel moved and it is for 640*480
			short fake_depth_x = (RGB_X * 0.63125 + 112);
	
			short real_depth_y = (RGB_Y * 0.63125 + 88.5);
			float fake_distance = VisionDataset_avoid_zero(fake_depth_x, real_depth_y);
			float distance = 0;
	
	
			if (fake_distance > 0) {
				short move_pixel = (17.72 / fake_distance);
				short real_depth_x = (RGB_X * 0.63125 + 118 - move_pixel);
				distance = VisionDataset_avoid_zero(real_depth_x, real_depth_y);
			}
	
	#ifdef DEBUG
			if (distance = 0) {
				std::cout << "(linial_align)_fail to get distance / distance = 0" << std::endl;
			}
	#endif
			return distance;
		}
	
	/*get depth data*/
	static void VisionDataset_getDepth(data_control& CT_data) {
#ifndef VIRTUAL
		for (int index = 0; index < 6; index++) {
			if (CT_data.dataset.Center_X[index] > 0 && CT_data.dataset.Center_Y[index] > 0) {
				CT_data.dataset.distance[index] = linial_align(CT_data.dataset.Center_X[index], CT_data.dataset.Center_Y[index]);
				// std::cerr << index + 1 <<": distance info (m) : " << dataset.distance[index] << std::endl;  // we don`t need it reight now.
			}
#else 
		for (int index = 0; index < 6; index++) {
			if (CT_data.dataset.Center_X[index] > 0 && CT_data.dataset.Center_Y[index] > 0) {
				CT_data.dataset.distance[index] = sim_depth.getDepthdata(dataset.Center_X[index], dataset.Center_Y[index]); // get depth data form slim
				// std::cerr << index + 1 <<": distance info (m) : " << dataset.distance[index] << std::endl;  // we don`t need it reight now.
			}
		//GZbot code will insert
#endif !VIRTUAL
		}

	}

	/*for making lable img*/
	static void making_img(data_control& CT_data) {
#ifdef MAKEING_IMG //this fucntion is making a img


#endif
	}

};

#endif