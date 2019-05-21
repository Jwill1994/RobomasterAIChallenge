#include "src/all.hpp"

bool team_col = false;
bool not_yet = true;

void team_color(const roborts_msgs::RobotStatus::ConstPtr& msg) {
        if (team_col == false) {
                if (msg->id == 3 || msg->id == 4) {us_color = "red";}
                else if (msg->id == 13 || msg->id == 14) {us_color = "blue";}

                team_col = true;
        }
}

void game_starter(const roborts_msgs::GameStatus::ConstPtr& msg) {
        if (not_yet == true && msg->game_status == 4) {
                not_yet = false;
		ROS_ERROR("starting");
        }
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "vision_node");
	ros::NodeHandle nh;
        ros::Subscriber team_sub;
        ros::Subscriber start_sub;
        team_sub = nh.subscribe("robot_status", 2, team_color);
        start_sub = nh.subscribe("game_status", 2, game_starter);
	darknet::Detector detector_yolo(cfg_file, weights_file); // YOLO
	vision_detector detector(detector_yolo); // object detector class setup
        while(not_yet) {ros::spinOnce();}
	GimbalControl gimbalControl(nh); // 짐벌조절
	send_control send_control; // gimbal에 보낼 정보들
	vision_ros vision_ros(nh); // ros부분
	data_control CT_data; // 데이터 관리
	ImageConverter imageconverter(&CT_data); // ROS로 이미지 받아오기

        while (ros::ok()) {
                ros::spinOnce();
                if(get_data) {
                        detector.vision_detector_run(CT_data, detector_yolo); // YOLO
                        send_control.send_data_maker(CT_data); // 보낼 정보 만들기
                        gimbalControl.run(send_control.to_gimbal); // 창민 부분
                        vision_ros.pubEnemyInfo(CT_data);
                        get_data = false;
                }
        }
}
