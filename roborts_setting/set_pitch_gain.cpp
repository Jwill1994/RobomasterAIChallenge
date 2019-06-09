#include "icra_roboin_msgs/PitchGain.h"
#include "ros/ros.h"
#include <cstdio>
using namespace std;

void setPitchGain(ros::ServiceClient pitch_gain_client_, icra_roboin_msgs::PitchGain &pitch_gain_);




int main(int argc, char **argv) {
    ros::init(argc, argv, "set_pitch_gain_node");

    ros::NodeHandle nh;

    ros::ServiceClient pitch_gain_client = nh.serviceClient<icra_roboin_msgs::PitchGain>("pitch_gain");
    icra_roboin_msgs::PitchGain pitch_gain;

    ros::Rate rate(10);

    while(ros::ok()) {
        float p, i, d;
        printf("enter p i d gains (0 for no-change): ");
        scanf("%f %f %f", &p, &i, &d);
        pitch_gain.request.p = p;
        pitch_gain.request.i = i;
        pitch_gain.request.d = d;

        setPitchGain(pitch_gain_client, pitch_gain);

    }
}


void setPitchGain(ros::ServiceClient pitch_gain_client_, icra_roboin_msgs::PitchGain &pitch_gain_) {

    if(pitch_gain_client_.call(pitch_gain_)) {
        if(pitch_gain_.response.received) {
            ROS_INFO_STREAM("Set pitch gain P: " << pitch_gain_.request.p << " I: " << pitch_gain_.request.i
                                                 << "D: " << pitch_gain_.request.d);
        } else {
            ROS_WARN("Not Set");
        }
    } else {
        ROS_ERROR("Call Fail");
    }
}