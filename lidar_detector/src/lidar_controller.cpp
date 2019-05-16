#include "khc/lidar_controller.hpp"

void reload_control() {
    geometry_msgs::Twist vel;
    if (lidar_ok == false) {return;} // 라이다 값이 안들어옴
    current_angle = scan.angle_min;
    counter = 0; angle_counter = 0; left = 0; side_incline = 0;
    for (short i=0; i<scan.ranges.size(); i++) {
        if (current_angle > side_start && current_angle < side_end) {
            current_point[0] = scan.ranges[i] * cos(current_angle);
            current_point[1] = scan.ranges[i] * sin(current_angle);
            counter++;}
        else if (current_angle > side_end) {break;} // 원하는 구간 다 지남
        current_angle += scan.angle_increment;
        if (counter > 1) {
            side_incline += (current_point[1] - past_point[1]) / (current_point[0] - past_point[0]);
            angle_counter++;} past_point[0] = current_point[0]; past_point[1] = current_point[1];}
    side_incline /= angle_counter;
    if (side_incline > min_incline_diff || side_incline < -1 * min_incline_diff) {
        vel.angular.z = side_incline * angular_sensitivity;} // x angular
    current_angle = scan.angle_min;
    for (short i=0; i<scan.ranges.size(); i++) {if (current_angle >= -90.0) {left = i; break;}}
    if (scan.ranges[left] < 1.5) { // 1.5 이상이면 박스 밖을 보는 것
        if (abs(scan.ranges[left] - reload_wanted_left) > min_xy_diff) { // y linear
            vel.linear.y = (scan.ranges[left] - reload_wanted_left) * linear_sensitivity;}
    }
    if (abs(scan.ranges[180] - reload_wanted_back) > min_xy_diff) { // x linear
        vel.linear.x = -1 * (scan.ranges[180] - reload_wanted_back) * linear_sensitivity;}
    vel_pub_.publish(vel);
    lidar_ok = false;
}

/*callback function*/
void command_input(const std_msgs::Int8::ConstPtr& msg) {
    behave = msg->data;
}

void lidar_input(const sensor_msgs::LaserScan::ConstPtr& msg) {
    scan.angle_min = msg->angle_min;
    scan.angle_increment = msg->angle_increment;
    scan.ranges = msg->ranges;
    lidar_ok = true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "lidar_controller");
    ros::NodeHandle n;
    lidar_sub_ = n.subscribe("scan", 1, lidar_input);
    command_sub_ = n.subscribe("reload_lidar_command", 1, command_input);
    vel_pub_ = n.advertise<geometry_msgs::Twist>("cmd_vel", 3);
    while(ros::ok()) {
        ros::spinOnce();
        if (behave == 1) {reload_control();}}
    return 0;
}
