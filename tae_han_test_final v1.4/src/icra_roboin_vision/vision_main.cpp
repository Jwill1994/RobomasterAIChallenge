// v4.0
// v3.01까지 곽동환 작업, v4.0부터 김형철 작업

#define BASIC_FUNCTION  //this is for basic function (using ROS)
#define DISPLAY  // control opencv_ imshow function with object_Detection
#ifndef DISPLAY
    #define DISPLAY_ONLY_CAMERA  //Show only Camera image
#endif
//#define DEBUG  			//show what function started and worked
//#define VISION_DATACHECK 	//show vision output data such as number of detection
//#define ZIMBAL_DATACHECK 	//show zimbal`s output data such as angle
//#define MAKEING_IMG 		//this fucntion is making a img
#define REMOTE			// ROS Topic으로 color, depth 이미지 받아오기 okay????  dummy
#ifdef REMOTE
#include "src/remote.hpp"
#endif
//#define WATCH_LOOP_TIME
#include "src/all.hpp"
#include <time.h>

int main(int argc, char **argv) {
	ros::init(argc, argv, "vision_node");
	ros::NodeHandle nh;
	darknet::Detector detector_yolo(cfg_file, weights_file); //yolo detector
	vision_detector detector(detector_yolo); //object detector class setup
	send_control send_control; //send data to black board and gimblal
	GimbalControl gimbalControl(nh);
	vision_ros vision_ros(nh);
	data_control CT_data; 		// 이 데이터로 모든것들을 관리
#ifdef REMOTE
	ImageConverter imageconverter(&CT_data);
#else
	vision_camera camera(nh); //camera class initialize
#endif
#ifdef WATCH_LOOP_TIME
        float start_time;
        float end_time;
        float F_P_S;
#endif //!WATCH_LOOP_TIME
    while (ros::ok()) {
#ifdef WATCH_LOOP_TIME
        start_time=std::clock();
#endif //!WATCH_LOOP_TIME
#ifdef REMOTE
        if(get_data) {
                detector.vision_detector_run(CT_data, detector_yolo);	// run object detector and assign output data
                //camera.making_img(CT_data); 							// for making img for labeling
                send_control.send_data_maker(CT_data);					// making send data.
                gimbalControl.run(send_control.to_gimbal);			// 창민 part
                //robotsInfo.pubEnemyInfo(send_control.to_black_board);
                get_data = false;
        }
#else
        camera.vision_camera_run(CT_data);  					// get camera image
        detector.vision_detector_run(CT_data, detector_yolo);	// run object detector and assign output data
        camera.making_img(CT_data); 							// for making img for labeling
        send_control.send_data_maker(CT_data);					// making send data.
        gimbalControl.run(send_control.to_gimbal);			// 창민 part
        //robotsInfo.pubEnemyInfo(send_control.to_black_board);
#endif
#ifdef WATCH_LOOP_TIME
        end_time=std::clock();
        F_P_S=1000000/(end_time-start_time);
        std::cout << "FPS : " << std::to_string(F_P_S) << std::endl;
#endif //!WATCH_LOOP_TIME

        if(cv::waitKey(1)==113) {break;}
        ros::spinOnce();
	}
}
