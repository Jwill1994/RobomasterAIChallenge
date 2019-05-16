// lidar        -- map_frame
// measurement  -- lidar_frame
// data_check   -- measurement를 map_frame으로 변환
// publish      -- map_frame
#include "khc/lidar_detector.hpp"

/*맵 정보 받아옴 (한번만)*/
void get_mapInfo(const nav_msgs::OccupancyGrid::ConstPtr& msg) {
    if (map_ok == false) {
        frame = msg->header.frame_id;
        map_info.info = msg->info;
        map_info.data = msg->data;
        map_ok = true;
    }
}

/*라이다 pose 받아옴*/
void get_pose(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) {
    pose[0] = msg->pose.pose.position.x;
    pose[1] = msg->pose.pose.position.y;
    pose[2] = msg->pose.pose.orientation.z + pi;
}

/*measurement 받아옴*/
void get_measurement(const icra_roboin_msgs::Obstacles::ConstPtr& msg) {
    measurement.clear();
    for (short init=0; init<msg->circles.size(); init++) {
        if ((abs(msg->circles[init].center.x)+abs(msg->circles[init].center.y)) < 0.4) {std::cout<<"object too close! will have too much error\n";}
        else {
            std::vector<double> pnt;
            pnt.push_back(msg->circles[init].center.x);
            pnt.push_back(msg->circles[init].center.y);
            measurement.push_back(pnt);
        }
    }
    measure_ok = true;
}

/*map_frame이동 -> 벽&로봇 구분*/
void data_check() {
    pub_point.clear();
    short ptr = 0;
    for (short i=0; i<measurement.size(); i++) { // map_frame 으로 이동
        measurement[i][0] = pose[0] + measurement[i][0]*cos(pose[2]) - measurement[i][1]*sin(pose[2]);
        measurement[i][1] = pose[1] + measurement[i][0]*sin(pose[2]) + measurement[i][1]*cos(pose[2]);
    }
    for (short i=0; i<measurement.size(); i++) { // 확률 확인
        int x_cell = measurement[i][0] / resolution;
        int y_cell = measurement[i][1] / resolution;
        if (x_cell > map_info.info.width || x_cell < 0) {return;}
        if (y_cell > map_info.info.height || y_cell < 0) {return;}
        int prob = 0;
        int num = 0;
        for (short j=-1; j<2; j++) {
            for (short k=-1; k<2; k++) {
                if ((x_cell + j) < map_info.info.width && (x_cell + j) > 0
                && (y_cell + k) < map_info.info.height && (y_cell + k) > 0) {
                    int before_prob = map_info.data[(y_cell+k)*map_info.info.width + (x_cell+j)];
                    if (before_prob == -1) {prob += 80; num++;}
                    else {prob += before_prob; num++;}
                }}}
        prob /= num;
        if (prob > -1 && prob < prob_threshold) {
            if (measurement[i][0] > 0.33 && measurement[i][1] < 0.22 && measurement[i][1] > -0.22) {std::cout<<"back_part"<<std::endl;}
            else {pub_point.push_back(measurement[i]);}
        }
    }
}

/*PoseArray로 내놓음 / MarkerArray도 괜찮을듯*/
void publish_point() {
    if (pub_point.size() == 0) {
        return;
    }
    geometry_msgs::PoseArray pose_array;
    for (short i=0; i<pub_point.size(); i++) {
        geometry_msgs::Pose pose_one;
        pose_one.position.x = pub_point[i][0];
        pose_one.position.y = pub_point[i][1];
        pose_array.poses.push_back(pose_one);
    }
    pose_array.header.frame_id = frame;
    dynamic_pub_.publish(pose_array);
    measure_ok = false;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "D_detector");
    ros::NodeHandle n;
    map_sub_ = n.subscribe("map", 1, get_mapInfo);
	pose_sub_ = n.subscribe("amcl_pose", 1, get_pose);
    obstacles_sub_ = n.subscribe("obst", 1, get_measurement);
	dynamic_pub_ = n.advertise<geometry_msgs::PoseArray>("obstacles", 3);
    while(ros::ok()) {
		ros::spinOnce();
		if (measure_ok && map_ok) {
			data_check();
			publish_point();
        }
	}
    return 0;
}
