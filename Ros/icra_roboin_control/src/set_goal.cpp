#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <tf/transform_broadcaster.h>
#include <sstream>

/* rosrun icra_roboin_control navigation_control_node _x:=5 _y:=1 _yaw:=0 */


int main(int argc, char** argv)
{
    ros::init(argc,argv,"navigation_controller");
    ros::NodeHandle nh("~");
    actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> ac("move_base",true);


    double pose_x, pose_y, pose_yaw;
    nh.getParam("x",pose_x);
    nh.getParam("y",pose_y);
    nh.getParam("yaw",pose_yaw);
    ROS_INFO("Goal:(%f,%f,%f)",pose_x,pose_y,pose_yaw);


    ROS_INFO("Waiting for Action Server");
    ac.waitForServer();




    ROS_INFO("Connected to action server!");
    move_base_msgs::MoveBaseGoal nav_goal;

    nav_goal.target_pose.header.frame_id  = "map";
    nav_goal.target_pose.header.stamp = ros::Time::now();
    nav_goal.target_pose.pose.position.x = pose_x;
    nav_goal.target_pose.pose.position.y = pose_y;
    nav_goal.target_pose.pose.position.z = pose_yaw;
    nav_goal.target_pose.pose.orientation = tf::createQuaternionMsgFromYaw(0);
    
    ac.sendGoal(nav_goal);


    ROS_INFO("Sent goal");
    
    ac.waitForResult();
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
        ROS_INFO("Succeed");
    else
        ROS_INFO("fail");


    return 0;


}
