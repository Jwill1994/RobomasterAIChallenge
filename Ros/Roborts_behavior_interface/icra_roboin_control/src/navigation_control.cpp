#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "roborts_msgs/GlobalPlannerAction.h"
#include <tf/transform_broadcaster.h>
#include <sstream>

/* rosrun icra_roboin_control navigation_control_node _x:=5 _y:=1 _yaw:=0 */


int main(int argc, char** argv)
{
    ros::init(argc,argv,"navigation_controller");
    ros::NodeHandle nh("~");
    actionlib::SimpleActionClient<roborts_msgs::GlobalPlannerAction> ac("global_planner_node_action",true);


    double pose_x, pose_y, pose_yaw;
    nh.getParam("x",pose_x);
    nh.getParam("y",pose_y);
    nh.getParam("yaw",pose_yaw);
    ROS_INFO("Goal:(%f,%f,%f)",pose_x,pose_y,pose_yaw);


    ROS_INFO("Waiting for Action Server");
    ac.waitForServer();




    ROS_INFO("Connected to action server!");
    roborts_msgs::GlobalPlannerGoal nav_goal;
    
    nav_goal.goal.header.frame_id  = "map";
    nav_goal.goal.header.stamp = ros::Time::now();
    nav_goal.goal.pose.position.x = pose_x;
    nav_goal.goal.pose.position.y = pose_y;
    nav_goal.goal.pose.position.z = pose_yaw;
    nav_goal.goal.pose.orientation = tf::createQuaternionMsgFromYaw(0);
    
    ac.sendGoal(nav_goal);


    ROS_INFO("Sent goal");
    
    ac.waitForResult();
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Succeed");
    else
        ROS_INFO("fail");


    return 0;


}
