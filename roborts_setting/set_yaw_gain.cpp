#include "icra_roboin_msgs/YawGain.h"
#include "ros/ros.h"
#include <cstdio>
using namespace std;

void setYawGain(ros::ServiceClient &yaw_gain_client_, icra_roboin_msgs::YawGain &yaw_gain_);



int main(int argc, char **argv) {
    ros::init(argc, argv, "set_yaw_gain_node");
    ros::NodeHandle nh;
    ros::ServiceClient yaw_gain_client = nh.serviceClient<icra_roboin_msgs::YawGain>("yaw_gain");
    icra_roboin_msgs::YawGain yaw_gain;

    ros::Rate rate(10);

    while(ros::ok()) {
        float p, i, d;
        printf("enter p i d gains (0 for no-change): ");
        cin >> p >> i >> d;
        //scanf("%f %f %f", &p, &i, &d);
        printf("set yaw pid to %f %f %f\n", p, i, d);
        yaw_gain.request.p = p;
        yaw_gain.request.i = i;
        yaw_gain.request.d = d;

        //setYawGain(yaw_gain_client, yaw_gain);
        if(yaw_gain_client.call(yaw_gain)) {
            if(yaw_gain.response.received) {
                ROS_INFO_STREAM("Set yaw gain P: " << yaw_gain.request.p << " I: " << yaw_gain.request.i
                                                   << "D: " << yaw_gain.request.d);
            } else {
                ROS_WARN("Not Set");
            }
        } else {
            ROS_ERROR("Call Fail");
        }


    }
}


void setYawGain(ros::ServiceClient &yaw_gain_client_, icra_roboin_msgs::YawGain &yaw_gain_) {

    if(yaw_gain_client_.call(yaw_gain_)) {
        if(yaw_gain_.response.received) {
            ROS_INFO_STREAM("Set yaw gain P: " << yaw_gain_.request.p << " I: " << yaw_gain_.request.i
                                               << "D: " << yaw_gain_.request.d);
        } else {
            ROS_WARN("Not Set");
        }
    } else {
        ROS_ERROR("Call Fail");
    }
}
