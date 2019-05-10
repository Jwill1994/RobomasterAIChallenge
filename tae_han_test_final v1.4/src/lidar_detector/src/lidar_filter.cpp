// 후방 각도 무시
// 후방 센서값 3개 받기
// #define SONIC
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
#include "./jetsonGPIO.h"
#include "./hcsr04.h"
using namespace std;
#endif

ros::Subscriber lidar_sub;
ros::Publisher lidar_pub;
sensor_msgs::LaserScan scan_pub;
bool pub_ok = false;
double plus_end_cut = 35 * 3.14159265358979 / 180;
double minus_end_cut = -35 * 3.14159265358979 / 180;
float sensor_place = 0.0;

void get_scan(const sensor_msgs::LaserScan::ConstPtr& scan) {
    scan_pub = *scan;
    double current_angle = scan->angle_min;
    for (int i=0; i<scan->ranges.size(); i++) {
        // minus_end_cut < current_angle < plus_end_cut
        if((current_angle > minus_end_cut) && (current_angle < plus_end_cut)) {
            scan_pub.ranges[i] = scan->range_max + 1.0;
            if(i < scan->intensities.size()) {scan_pub.intensities[i] = 0.0;}
        }
        current_angle += scan->angle_increment;
    }
    pub_ok = true;
}
#ifdef SONIC
int getkey() {
    int character;
    struct termios orig_term_attr;
    struct termios new_term_attr;

    /* set the terminal to raw mode */
    tcgetattr(fileno(stdin), &orig_term_attr);
    memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
    new_term_attr.c_lflag &= ~(ECHO|ICANON);
    new_term_attr.c_cc[VTIME] = 0;
    new_term_attr.c_cc[VMIN] = 0;
    tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

    /* read a character from the stdin stream without blocking */
    /*   returns EOF (-1) if no character is available */
    character = fgetc(stdin);

    /* restore the original terminal attributes */
    tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

    return character;
}

void exec_ultra(HCSR04 *hcsr04, HCSR04 *hcsr04ws) { 
    if(getkey() != 27){
        // unsigned int duration = ping() ;
        // unsigned int duration = ping_median(5) ;
        unsigned int duration = hcsr04->pingMedian(5) ;
	unsigned int duration_ws = hcsr04ws->pingMedian(5) ;
        if (duration != NO_ECHO) {
            // print out distance in inches and centimeters
            cout << "Duration1: " << duration << "// Ultrasonic1" << " Distance (m): " << duration/5800.0 << endl ;
        }
        if (duration_ws != NO_ECHO) {
            // print out distance in inches and centimeters
            cout << "Duration2: " << duration_ws << "// Ultrasonic2" << " Distance (m): " << duration_ws/5800.0 << endl ;
        }
    }
}
#endif

int main(int argc, char **argv)
{
    #ifdef SONIC
    // Use gpio165 as trigger, gpio166 as echo
    HCSR04 *hcsr04 = new HCSR04(gpio394,gpio393);
    HCSR04 *hcsr04ws = new HCSR04(gpio392,gpio397);
    // Make the HC-SR04 available in user space
    hcsr04->exportGPIO() ;
    hcsr04ws->exportGPIO() ;
    // Then set the direction of the pins
    hcsr04->setDirection() ;
    hcsr04ws->setDirection() ; 
    #endif
    ros::init(argc, argv, "lidar_filter");
    ros::NodeHandle n;
    lidar_pub = n.advertise<sensor_msgs::LaserScan>("scan", 5);
    lidar_sub = n.subscribe("scan_before", 2, get_scan);
	while(ros::ok()) {
		if (pub_ok) {
			lidar_pub.publish(scan_pub);
			pub_ok = false;
            #ifdef SONIC
			exec_ultra(hcsr04, hcsr04ws);
            #endif
		}
		ros::spinOnce();
	}
    return 0;
}




