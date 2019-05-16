#include "khc/lidar_controller.hpp"

void command_input(const std_msgs::Int8::ConstPtr& msg) {behave = msg->data;}

void lidar_input(const sensor_msgs::LaserScan::ConstPtr& msg) {
    if (behave != 0) {return;}
    geometry_msgs::Twist vel;
    current_angle = msg->angle_min;
    counter = 0; angle_counter = 0; left = 0; side_incline = 0;

    for (short i=0; i<msg->ranges.size(); i++) {
        if (current_angle => side_start && current_angle =< side_end) {
            current_point[0] = msg->ranges[i] * cos(current_angle);
            current_point[1] = msg->ranges[i] * sin(current_angle);
            counter++;}
        else if (current_angle > side_end) {break;} // 원하는 구간 다 지남
        current_angle += msg->angle_increment;
        if (counter > 1) {
            side_incline += (current_point[1] - past_point[1]) / (current_point[0] - past_point[0]);
            angle_counter++;}
        past_point[0] = current_point[0]; past_point[1] = current_point[1];
    }
    side_incline /= angle_counter;
    if (side_incline > min_incline_diff) {vel.angular.z = 1.0;}
    else if (side_incline < -1 * min_incline_diff) {vel.angular.z = -1.0;}
    current_angle = msg->angle_min;
    if (msg->ranges[90] < 1.5) {
        if (msg->ranges[90] - reload_wanted_left > min_xy_diff) {vel.linear.y = 1.0;}
        else if (msg->ranges[90] - reload_wanted_left < -1*min_xy_diff) {vel.linear.y = -1.0;}
    }
    if (msg->ranges[180] - reload_wanted_back > min_xy_diff) {vel.linear.x = -1.0;}
    else if (msg->ranges[180] - reload_wanted_back < -1*min_xy_diff) {vel.linear.x = 1.0;}
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
