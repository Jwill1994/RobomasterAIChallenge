// v4.0
// v3.01까지 곽동환 작업, v4.0부터 김형철 작업
//#define DISPLAY // 화면 보이기

//#define DEBUG // 각 함수가 잘 작동하는지 확인
//#define VISION_DATACHECK // 디스플레이, CV 관련 디버깅
//#define ZIMBAL_DATACHECK // 짐벌 관련 디버깅
//#define MAKE_IMG   // 이미지를 만들고 싶을때
#define START_NEW // 이미지 번호를 1번부터 배정
//#define WATCH_LOOP_TIME

#include "src/all.hpp"

int main(int argc, char **argv) {
	ros::init(argc, argv, "vision_node");
	ros::NodeHandle nh;
        ros::NodeHandle n_local("~");
        n_local.param<std::string>("us_color", us_color, "none");
        //ROS_ERROR("us color is : %s\n", us_color);
        ROS_ERROR("us color is : ", us_color, "\n");
        ROS_ERROR(us_color[0]);
        printf(us_color);
	darknet::Detector detector_yolo(cfg_file, weights_file); // YOLO
	vision_detector detector(detector_yolo); // object detector class setup
	send_control send_control; // gimbal에 보낼 정보들
	GimbalControl gimbalControl(nh); // 짐벌조절
	vision_ros vision_ros(nh); // ros부분
	data_control CT_data; // 데이터 관리
	ImageConverter imageconverter(&CT_data); // ROS로 이미지 받아오기
#ifdef WATCH_LOOP_TIME
        float start_time;
        float end_time;
        float F_P_S;
#endif //!WATCH_LOOP_TIME
    while (ros::ok()) {
#ifdef WATCH_LOOP_TIME
        start_time=std::clock();
#endif //!WATCH_LOOP_TIME
        ros::spinOnce();
        if(get_data) {
                detector.vision_detector_run(CT_data, detector_yolo); // YOLO
                send_control.send_data_maker(CT_data); // 보낼 정보 만들기
                gimbalControl.run(send_control.to_gimbal); // 창민 부분
                vision_ros.pubEnemyInfo(CT_data);
                get_data = false;
        }
#ifdef WATCH_LOOP_TIME
        end_time=std::clock();
        F_P_S=1000000/(end_time-start_time);
        std::cout << "FPS : " << std::to_string(F_P_S) << std::endl;
#endif //!WATCH_LOOP_TIME
        if(cv::waitKey(1)==113) {break;}
	}
}
