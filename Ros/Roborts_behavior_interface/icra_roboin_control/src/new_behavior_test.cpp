#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/PoseStamped.h>
#include <icra_roboin_msgs/BehaviorStyleSet.h>
#include <icra_roboin_msgs/BehaviorGoalSet.h>
#include <tf/transform_broadcaster.h>
/* rosrun icra_roboin_control navigation_control_node _x:=5 _y:=1 _yaw:=0 */


int main(int argc, char** argv)
{
    int behavior_;
    double x,y;
    std::cout << "enter the index of behavior to select" << std::endl;
    std::cout << "1: goal behavior, 6:rotate behavior, 12:stop behavior " << std::endl;
    std::cout << ">";
    std::cin >> behavior_;
    std::cout << std::endl;
    std::cout <<"now enter goal x" << std::endl;
    std::cout << ">";
    std::cin >> x;
    std::cout << std::endl;
    std::cout <<"now enter goal y" << std::endl;
    std::cout << ">";
    std::cin >> y;
    std::cout << std::endl;
    



    ros::init(argc, argv, "behavior_selector_node");
    ros::NodeHandle nh;
    ros::ServiceClient client1 = nh.serviceClient<icra_roboin_msgs::BehaviorStyleSet>("behavior_node/behavior_select_service");
    ros::ServiceClient client2 = nh.serviceClient<icra_roboin_msgs::BehaviorGoalSet>("behavior_node/goal_select_service");
    ros::Rate rate(10);

    
    while(ros::ok())
    {
        
        icra_roboin_msgs::BehaviorStyleSet srv1;
        icra_roboin_msgs::BehaviorGoalSet srv2;
        geometry_msgs::PoseStamped pose_;
        pose_.header.frame_id  = "map";
        pose_.header.stamp = ros::Time::now();
        pose_.pose.position.x = x;
        pose_.pose.position.y = y;
        pose_.pose.position.z = 1;
        pose_.pose.orientation = tf::createQuaternionMsgFromYaw(0);

        srv1.request.behavior = behavior_;
        srv2.request.goal = pose_;
        
        if (client1.call(srv1))
        {
            if (srv1.response.is_new == false) {
                ROS_INFO("already that behavior");
            } else {
                ROS_INFO("new behavior");
            }
        
        } else {
            ROS_ERROR("failed to call style service");
        }

        if (client2.call(srv2))
        {
            ROS_INFO("goal sent");
        
        } else {
            ROS_ERROR("failed to call goal service");
        }
        ros::spinOnce();
        rate.sleep(); 
    }

    
    return 0;
}
