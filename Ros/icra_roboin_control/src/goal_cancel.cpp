#include <ros/ros.h>
#include <actionlib_msgs/GoalID.h>

int main(int argc, char** argv)
{
    ros::init(argc,argv,"goal_cancel_node");
    ros::NodeHandle nh;
    ros::Publisher pub_ = nh.advertise<actionlib_msgs::GoalID>("move_base/cancel",1);
    ros::Rate loop_rate(10);
    int count = 0;
    while(count < 2)
    {
        actionlib_msgs::GoalID cancel_call;
        cancel_call.stamp = ros::Time::now();
        
        
        pub_.publish(cancel_call);
        ROS_INFO("cancel called");
        ros::spinOnce();
        loop_rate.sleep();
        count++;
    }
    
    
    return 0;
}
