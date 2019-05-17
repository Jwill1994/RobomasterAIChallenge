//cd /sys/class/gpio
//echo 393 > /sys/class/gpio/export
//echo 394 > /sys/class/gpio/export

#define SONIC
#include <ros/ros.h>
#include "sensor_msgs/LaserScan.h"

#ifdef SONIC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <unistd.h>
#include "khc/jetsonGPIO.h"
#include "khc/hcsr04.h"
using namespace std;
#endif

ros::Subscriber lidar_sub;
ros::Publisher lidar_pub;
sensor_msgs::LaserScan scan_pub;
bool pub_ok = false;
bool sonic_ok = false;
double sonic_dist = 0;
double plus_end_cut = 35 * 3.14159265358979 / 180;
double minus_end_cut = -35 * 3.14159265358979 / 180;
float sensor_place = 0.0;
double lidar_box_dist = 0.36;
void get_scan(const sensor_msgs::LaserScan::ConstPtr& scan) {
    scan_pub = *scan;
    double current_angle = scan->angle_min;
    for (int i=0; i<scan->ranges.size(); i++) {
        // minus_end_cut < current_angle < plus_end_cut
        if((current_angle > minus_end_cut) && (current_angle < plus_end_cut)) {
            scan_pub.ranges[i] = std::numeric_limits<float>::infinity();
            if(i < scan->intensities.size()) {scan_pub.intensities[i] = 0.0;}
        }
        current_angle += scan->angle_increment;
    }
    if (sonic_ok) {
        sonic_ok = false;
        if (sonic_dist > 0.15 && sonic_dist < 1.3) { // lidar minimum 0.15 meter
            scan_pub.ranges[177] = sonic_dist + lidar_box_dist;
            scan_pub.ranges[178] = sonic_dist + lidar_box_dist;
            scan_pub.ranges[179] = sonic_dist + lidar_box_dist;
            scan_pub.ranges[180] = sonic_dist + lidar_box_dist;
            scan_pub.ranges[181] = sonic_dist + lidar_box_dist;
            scan_pub.ranges[182] = sonic_dist + lidar_box_dist;
            scan_pub.ranges[183] = sonic_dist + lidar_box_dist;
            scan_pub.ranges[184] = sonic_dist + lidar_box_dist;
            scan_pub.intensities[177] = 47.0;
            scan_pub.intensities[178] = 47.0;
            scan_pub.intensities[179] = 47.0;
            scan_pub.intensities[180] = 47.0;
            scan_pub.intensities[181] = 47.0;
            scan_pub.intensities[182] = 47.0;
            scan_pub.intensities[183] = 47.0;
            scan_pub.intensities[184] = 47.0;
        }
    }
    pub_ok = true;
}
#ifdef SONIC
int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);
    character = fgetc(stdin);
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);
    return character;
}

void exec_ultra(HCSR04 *hcsr04) { 
    if(getkey() != 27){
        unsigned int duration = hcsr04->pingMedian(5) ;
        if (duration != NO_ECHO) {sonic_dist = duration / 5800.0; sonic_ok = true;std::cout<<"yes value\n";}
        else if (duration == NO_ECHO) {std::cout<<"no value\n";}
}}
#endif

int main(int argc, char **argv) {
    #ifdef SONIC
    HCSR04 *hcsr04 = new HCSR04(gpio395,gpio388);
    hcsr04->exportGPIO();
    hcsr04->setDirection();
    #endif
    ros::init(argc, argv, "lidar_filter");
    ros::NodeHandle n;
    lidar_pub = n.advertise<sensor_msgs::LaserScan>("scan", 3);
    lidar_sub = n.subscribe("scan_before", 2, get_scan);
	while(ros::ok()) {
        #ifdef SONIC
        exec_ultra(hcsr04);
        #endif
		ros::spinOnce();
		if (pub_ok) {lidar_pub.publish(scan_pub); pub_ok = false;}
	}
    return 0;
}




