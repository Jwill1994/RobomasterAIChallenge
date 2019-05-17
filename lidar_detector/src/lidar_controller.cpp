#include "khc/lidar_controller.hpp"

void command_input(const std_msgs::Int8::ConstPtr& msg) {behave = msg->data;}

void lidar_input(const sensor_msgs::LaserScan::ConstPtr& msg) {
    if (behave != 0) {return;}
    geometry_msgs::Twist vel; side_incline = 0;
    current_angle = msg->angle_min + msg->angle_increment*100; // -80도 부터 보기 시작
    for (short i =0; i<num_angle; i++) { // -60도 까지 보기
        side_incline += (msg->ranges[101+i]*sin(current_angle + msg->angle_increment)-msg->ranges[100+i] * sin(current_angle)) /
                        (msg->ranges[101+i]*cos(current_angle + msg->angle_increment)-msg->ranges[100+i] * cos(current_angle)) / num_angle;
        current_angle += msg->angle_increment;
    }
    if (side_incline > min_incline_diff) {vel.angular.z = vel_give;}
    else if (side_incline < -1 * min_incline_diff) {vel.angular.z = -1*vel_give;}
    if (msg->ranges[90] < 1.5) {
        if (msg->ranges[90] - reload_wanted_left > min_xy_diff) {vel.linear.y = vel_give;}
        else if (msg->ranges[90] - reload_wanted_left < -1*min_xy_diff) {vel.linear.y = -1*vel_give;}
    }
    if (msg->ranges[180] - reload_wanted_back > min_xy_diff) {vel.linear.x = -1*vel_give;}
    else if (msg->ranges[180] - reload_wanted_back < -1*min_xy_diff) {vel.linear.x = vel_give;}
    vel_pub_.publish(vel);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "lidar_controller");
    ros::NodeHandle n;
    lidar_sub_ = n.subscribe("scan", 1, lidar_input);
    command_sub_ = n.subscribe("reload_lidar_command", 1, command_input);
    vel_pub_ = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
    ros::spin();
    return 0;
}
