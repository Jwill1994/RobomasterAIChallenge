#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>
#include <cstdlib>
#include <algorithm>
#include <memory>
#include <thread>
#include <mutex>
#include <iostream>
/* rosrun icra_roboin_control navigation_control_node _x:=5 _y:=1 _yaw:=0 */

void rvizCB(const geometry_msgs::PoseStamped::ConstPtr& msg);
void inputThreadFunction();
geometry_msgs::PoseStamped enemy_pose_;
double x,y,yaw;

int main(int argc, char** argv)
{
    ros::init(argc,argv,"fake_enemy_pose_publisher");
    ros::NodeHandle nh("~");
    ros::NodeHandlePtr nh_rviz_ptr;
    ros::NodeHandle nh_enemy("/enemy1");
    ros::Subscriber rviz_sub;
    std::thread input_thread;
    
    ros::Publisher enemy_pose_publisher = nh_enemy.advertise<geometry_msgs::PoseStamped>("pose",10);

    int use_rviz_pose_;
    nh.getParam("use_rviz_pose",use_rviz_pose_);

    if(use_rviz_pose_== 1){
        ROS_INFO("use rviz to emulate enemy pose");
        nh_rviz_ptr = std::move(ros::NodeHandlePtr(new ros::NodeHandle("/move_base_simple")));
        rviz_sub = nh_rviz_ptr -> subscribe("goal",1,rvizCB);
    } else {
        ROS_INFO("use custom enemy pose");
        ROS_INFO("enter x,y,yaw");
        ROS_INFO(">");
        input_thread = std::thread(inputThreadFunction);
    }

    

    
    ros::Rate rate(10);
    while(ros::ok()) 
    {


        enemy_pose_publisher.publish(enemy_pose_);

        ros::spinOnce();
        rate.sleep();
    }

    if(input_thread.joinable()){
        input_thread.join();
    }

    return 0;

}

void rvizCB(const geometry_msgs::PoseStamped::ConstPtr& msg) {
    ROS_INFO("got_rviz_goal");
    enemy_pose_ = *msg;
}

void inputThreadFunction() {
    //future work
}