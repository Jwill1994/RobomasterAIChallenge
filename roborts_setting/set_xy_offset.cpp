#include "icra_roboin_msgs/XYOffset.h"
#include "ros/ros.h"
#include <cstdio>
using namespace std;

//void setXYOffset(ros::ServiceClient &xy_offset_client_, icra_roboin_msgs::XYOffset &xy_offset_);

int prev_x = 0;
int prev_y = 0;

int main(int argc, char **argv) {
    ros::init(argc, argv, "set_xy_offset_node");
    ros::NodeHandle nh;
    ros::ServiceClient offset_client = nh.serviceClient<icra_roboin_msgs::XYOffset>("xy_offset");
    icra_roboin_msgs::XYOffset xy_offset;

    ros::Rate rate(10);

    while(ros::ok()) {
        int x_offset, y_offset;
        printf("enter x y offset: ");
        cin >> x_offset >> y_offset;

        printf("set x y offset to %d %d\n", x_offset, y_offset);
        xy_offset.request.x_offset = x_offset;
        xy_offset.request.y_offset = y_offset;


        if(offset_client.call(xy_offset)) {
            if(xy_offset.response.received) {
                if(x_offset != 0) prev_x = x_offset;
                if(y_offset != 0) prev_y = y_offset;
                ROS_INFO_STREAM("Set offset x: " << prev_x << " y: " << prev_y);
            } else {
                ROS_WARN("Not Set");
            }
        } else {
            ROS_ERROR("Call Fail");
        }


    }
}

/*
void setXYOffset(ros::ServiceClient &xy_offset_client_, icra_roboin_msgs::XYOffset &xy_offset_) {

    if(xy_offset_client_.call(yaw_gain_)) {
        if(yaw_gain_.response.received) {
            ROS_INFO_STREAM("Set offset x: " << xy_offset_.request.x_offset << " y: " << xy_offset_.request.y_offset);
        } else {
            ROS_WARN("Not Set");
        }
    } else {
        ROS_ERROR("Call Fail");
    }
}
*/
