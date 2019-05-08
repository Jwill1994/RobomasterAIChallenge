//v4.0
#pragma once
#ifndef CAMERA_HPP
#define CAMERA_HPP


#include "pch.hpp"
#include "Data_control.hpp"
#include "Vision_ros.hpp"

#ifdef ADD_DEEPLEARNING
#include "object_detection.hpp"
//#include "/home/nvidia/robomaster_extra/darknet/include/yolo_v2_class.hpp"
#endif

inline bool exists_test3(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}
/*this class manage realsense camera or GZbot vertual camera*/
class vision_camera {
public:
#ifndef VIRTUAL
    //for real world, realsense camera use
    rs2::context ctx;
    rs2::device_list list;
    rs2::colorizer color_map;
    rs2::pipeline pipe;
    rs2::config cfg;
    rs2::pipeline_profile profile;
    cv::Mat frame_to_mat(const rs2::frame &f);
    cv::Mat depth_frame_to_meters(const rs2::pipeline& pipe, const rs2::depth_frame& f);
    
#else
//GZbot code
#endif

private:
	int numberofimg;  
    //for read img files to continue image write
    int find_img_number();
	/*directly get distance data*/
    float VisionDataset_avoid_zero(short x, short y, data_control& CT_data);
	void ask_num_img();
public:
    /*camera class init*/
    vision_camera(const ros::NodeHandle &nh) {
        this->numberofimg = 1;
		this->ask_num_img();
#ifndef VIRTUAL
        this->list = this->ctx.query_devices();
        if (this->list.size() == 0) {
            throw std::runtime_error("vision: Device not found");
        }
        this->cfg.enable_stream(RS2_STREAM_COLOR, imgWidth, imgHeight, RS2_FORMAT_BGR8, 60);
        this->cfg.enable_stream(RS2_STREAM_DEPTH, imgWidth, imgHeight, RS2_FORMAT_Z16, 60);
        this->profile = this->pipe.start(this->cfg);
#ifdef DEBUG
        std::cout << "vision_camera initialized" << std::endl;
#endif //!DEBUG

#else
        // for GZbot code
                ImageConverter sim_img(nh);
                DepthConverter sim_depth(nh);
#endif //!VIRTUAL
    }
    /*delete camera class*/
    ~vision_camera() = default;
    /*running camera*/
    void vision_camera_run(data_control &CT_data);
    /*the simple linial align, this function is made for realsense D435 and I was get data form experiment*/  //if you want to more exact data, then try search "librealsense align"
    float linear_align(short RGB_X, short RGB_Y, data_control& CT_data);
    /*get depth data*/
    void VisionDataset_getDepth(data_control &CT_data);
    /*for making lable img*/
    void making_img(data_control &CT_data);
};

cv::Mat vision_camera::frame_to_mat(const rs2::frame& f)
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
    throw std::runtime_error("Frame format is not supported yet!");	}
cv::Mat vision_camera::depth_frame_to_meters(const rs2::pipeline& pipe, const rs2::depth_frame& f)
{
	using namespace cv;
	using namespace rs2;

	Mat dm = frame_to_mat(f);
	dm.convertTo(dm, CV_64F);
	auto depth_scale = pipe.get_active_profile()
		.get_device()
		.first<depth_sensor>()
		.get_depth_scale();
	dm = dm * depth_scale;
	return dm;
}

float vision_camera::VisionDataset_avoid_zero(short x, short y, data_control& CT_data) {
    //to use this function, x and y must be larger then 3 and smaler than Max-3
    float Depth = 0;
    float tem_Depth = 0;
    short i = 0;
    short j = 0;
    short count = 0;
    for (i = x; i < x + 3; i++) {
        for (j = y; j < y + 3; j++) {
            tem_Depth = CT_data.dataset.depth_img.at<double>((i - 1), (j - 1));  //opencv_depth frame 
            if (tem_Depth > 0) {
                count++;
                Depth = Depth + tem_Depth;
            }
        }
    }
    if (count > 0) {
        Depth = Depth / count;
#ifdef DEBUG
        std::cout << "(VisionDataset_avoid_zero) get_distance_is succeed " << std::endl;
#endif
        return Depth;
    }
    else {
#ifdef DEBUG
        std::cout << "(VisionDataset_avoid_zero) distance is zero" << std::endl;
#endif
        return 0;
    }
}

int vision_camera::find_img_number() {
    std::cout << "try to read the last number of img" << std::endl;
    std::ostringstream check_name; //
    int number = 1;
    bool flag = true;
    while (flag) {
        check_name.str("");
        check_name.clear();
        if (number < 10) {check_name << "/home/nvidia/img/" << "0000" << number << ".jpg";}
        else if (9 < number < 100) {check_name << "/home/nvidia/img/" << "000" << number << ".jpg";}
        else if (99 < number < 1000) {check_name << "/home/nvidia/img/" << "00" << number << ".jpg";}
        else if (999 < number < 10000) {check_name << "/home/nvidia/img/" << "0" << number << ".jpg";}
        else {check_name << "/home/nvidia/img/" << number << ".jpg";}
        number++;
        flag = exists_test3(check_name.str());
    }
#ifdef DEBUG
	std::cout << "(find_img_number) this number of image is obtained" << std::endl;
#endif
    return (number -1) ;
}

void vision_camera::vision_camera_run(data_control& CT_data) {
#ifndef VIRTUAL
    while (true) {
        rs2::frameset data = this->pipe.wait_for_frames();
        rs2::video_frame color_frame = data.get_color_frame();
        rs2::depth_frame depth_frame = data.get_depth_frame();
        if (!(depth_frame) || !(color_frame)) {
#ifdef DEBUG
			std::cout << "(vision_camera_run) fail to get image" << std::endl;
#endif
            continue;  // frame check based on buffer
        }
        CT_data.dataset.detectimg = this->frame_to_mat(color_frame);
	CT_data.dataset.depth_img = this->depth_frame_to_meters(this->pipe, depth_frame);
        break; //get new frame
    }
#else
    //insert GZbot code
		CT_data.dataset.detectimg = sim_img.GetImage(); // ros image get
#endif //!VIRTUAL
#ifdef DISPLAY
    CT_data.dataset.display = CT_data.dataset.detectimg.clone(); //making display image
#endif //!DISPLAY

#ifdef DISPLAY_ONLY_CAMERA
    cv::imshow("Display window" , CT_data.dataset.detectimg.clone());
    int start_x=50;
    int start_y=32;
    cv::Mat dept=CT_data.dataset.depth_img(cv::Rect(start_x,start_y,423-start_x-75,239-start_y-37));
    cv::resize(dept,dept,cv::Size(424,240));
    cv::imshow("Depth window", dept);
#endif //!DISPLAY_ONLY_CAMERA


#ifdef DEBUG
	std::cout << "(vision_camera_run) get image from camera" << std::endl;
#endif

}
float vision_camera::linear_align(short RGB_X, short RGB_Y, data_control& CT_data) {
    /*
    // based on 3m > 6 pixel moved and it is for 640*480
    short fake_depth_x = (RGB_X * 0.63125 + 112);

    short real_depth_y = (RGB_Y * 0.63125 + 88.5);
    float fake_distance = this->VisionDataset_avoid_zero(fake_depth_x, real_depth_y,CT_data);
    float distance = 0;


    if (fake_distance > 0) {
        short move_pixel = (17.72 / fake_distance);
        short real_depth_x = (RGB_X * 0.63125 + 118 - move_pixel);
        distance = this->VisionDataset_avoid_zero(real_depth_x, real_depth_y,CT_data);
    }
    */
    // based on 3m > 6 pixel moved and it is for 424*240
    float distance=0;
    float distance1_1; float distance1_2; float distance1_3;
    float distance2_1; float distance2_2; float distance2_3;
    float distance3_1; float distance3_2; float distance3_3;
    int start_x=50;
    int start_y=32;
    cv::Mat dept=CT_data.dataset.depth_img(cv::Rect(start_x,start_y,423-start_x-75,239-start_y-37));
    /*dept size : 298 * 170*/
    //cv::resize(dept,dept,cv::Size(424,240));
    short deptx=RGB_X*298/424;
    short depty=RGB_Y*170/240;
#ifdef VISION_DATACHECK
    std::cout << "RGB_XY: "+std::to_string(RGB_X) + " "+ std::to_string(RGB_Y)+" DEPTH_XY : "
                 +std::to_string(deptx)+" "+std::to_string(depty)+" / ";
#endif
    int count_valid=0;
    distance1_1=dept.at<double>(std::max(0,deptx-1),std::max(0,depty-1));
    if(distance1_1!=0) count_valid+=1; printf("%f\n",distance1_1);
    distance1_2=dept.at<double>(deptx,std::max(0,depty-1));
    if(distance1_2!=0) count_valid+=1;
    distance1_3=dept.at<double>(std::min(297,deptx+1),std::max(0,depty-1));
    if(distance1_3!=0) count_valid+=1;
    distance2_1=dept.at<double>(std::max(0,deptx-1),depty);
    if(distance2_1!=0) count_valid+=1;
    distance2_2=dept.at<double>(deptx,depty);
    if(distance2_2!=0) count_valid+=1;
    distance2_3=dept.at<double>(std::min(297,deptx+1),depty);
    if(distance2_3!=0) count_valid+=1;
    distance3_1=dept.at<double>(std::max(0,deptx-1),std::min(169,depty+1));
    if(distance3_1!=0) count_valid+=1;
    distance3_2=dept.at<double>(deptx,std::min(169,depty+1));
    if(distance3_2!=0) count_valid+=1;
    distance3_3=dept.at<double>(std::min(297,deptx+1),std::min(169,depty+1));
    if(distance3_3!=0) count_valid+=1;
    distance=(distance1_1+distance1_2+distance1_3+
              distance2_1+distance2_2+distance2_3+
              distance3_1+distance3_2+distance3_3)/count_valid;
    //distance=dept.at<double>(deptx,depty);
#ifdef DEBUG
    if (distance == 0) {
                        std::cout << "(linear_align)_fail to get distance / distance = 0" << std::endl;
		}
#endif //!DEBUG
    return distance;
}
void vision_camera::VisionDataset_getDepth(data_control &CT_data) {
#ifndef VIRTUAL
    for (int index = 0; index < max_num_robot; index++) {
        if (CT_data.dataset.Center_X[index] > 0 && CT_data.dataset.Center_Y[index] > 0) {
            CT_data.dataset.distance[index] = this->linear_align(CT_data.dataset.Center_X[index], CT_data.dataset.Center_Y[index],CT_data);
        }
    }
#else
    for (int index = 0; index < max_num_robot; index++) {
                if (CT_data.dataset.Center_X[index] > 0 && CT_data.dataset.Center_Y[index] > 0) {
                    CT_data.dataset.distance[index] = sim_depth.getDepthdata(dataset.Center_X[index], dataset.Center_Y[index]); // get depth data form slim
                    // std::cerr << index + 1 <<": distance info (m) : " << dataset.distance[index] << std::endl;  // we don`t need it reight now.
                }
                //GZbot code will insert
        }
#endif //!VIRTUAL
}
void vision_camera::ask_num_img() {
#ifdef MAKEING_IMG
	char flag = 'n';
	if (this->numberofimg == 1) {
		std::cout << "wellcome to image making world!!" << std::endl;
		std::cout << "start making image " << std::endl;
		std::cout << "if you want to continue form last img type (y) , start from 00001.jpg type (n) " << std::endl;
		std::cout << "enter yout answer" << std::endl;
		while (true) {
			std::cin >> flag;
			if (flag == 'n') {
				std::cout << "directly start with number 00001.jpg" << std::endl;
				break;
			}
			else if (flag == 'y') {
				this->numberofimg = this->find_img_number(); //fine last number of img
				std::cout << "the image file makeing is start form" << this->numberofimg << ".jpg" << std::endl;
				break;
			}
		}
	}
#endif //!MAKEING_IMG
} 
void vision_camera::making_img(data_control &CT_data) {
#ifdef MAKEING_IMG //this fucntion is making a img
    std::ostringstream img_name; // this is making img`s name
	img_name.str("");
	img_name.clear();
	try {
        if (this->numberofimg < 10) {img_name << "/home/nvidia/img/" << "0000" << this->numberofimg << ".jpg";}
        else if (9 < this->numberofimg < 100) {img_name << "/home/nvidia/img/" << "000" <<this-> numberofimg << ".jpg";}
        else if (99 < this->numberofimg < 1000) {img_name << "/home/nvidia/img/" << "00" << this->numberofimg << ".jpg";}
        else if (999 < this->numberofimg < 10000) {img_name << "/home/nvidia/img/" << "0" << this->numberofimg << ".jpg";}
        else {img_name << "/home/nvidia/img/" <<this->numberofimg << ".jpg";}
        this->numberofimg++;
        cv::imwrite(img_name.str(), CT_data.dataset.detectimg);
        std::cout << "save_image:" << this->numberofimg -1 << ".jpg" <<std::endl;
	}
	catch (cv::Exception& e) {std::cout << "error has been occured " << this->numberofimg - 1 << std::endl;}
#endif //!MAKEING_IMG
}
#endif //!CAMERA_HPP