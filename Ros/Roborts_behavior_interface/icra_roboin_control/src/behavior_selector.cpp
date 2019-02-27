#include <ros/ros.h>
#include "icra_roboin_msgs/SetBehavior.h"
#include <cstdlib>


void CommandInit();
void Command();
char command;

int main(int argc, char** argv)
{
    ros::init(argc, argv, "behavior_selector_node");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<icra_roboin_msgs::SetBehavior>("behavior_select_service");
    ros::Rate rate(10);

    CommandInit();
    while(ros::ok())
    {
        Command();
        if(command == 27) return 0;
        icra_roboin_msgs::SetBehavior srv;
        srv.request.behavior = atoi(&command); //command index
        if (client.call(srv))
        {
            if (srv.response.received == false) {
                ROS_INFO("behavior selection successful");
            } else {
                ROS_INFO("already that action");
            }
        
        } else {
            ROS_ERROR("failed to call service");
            return 1;
        }
        ros::spinOnce();
        rate.sleep(); 
    }

    
    return 0;

}

void CommandInit() {

  
    std::cout << "**************************************************************************************" << std::endl;
    std::cout << "*********************************please send a command********************************" << std::endl;
    std::cout << "1: back boot area behavior" << std::endl
              << "2: patrol behavior" << std::endl
              << "3: chase_behavior" << std::endl
              << "4: search behavior" << std::endl
              << "5: escape behavior" << std::endl
              << "6: goal behavior" << std::endl
              << "7: cancel all behavior" << std::endl
              << "esc: exit program" << std::endl;
    std::cout << "**************************************************************************************" << std::endl;
    std::cout << "> ";
    

  
}

void Command() {
    std::cin >> command;
    std::cout << std::endl;
    if (command != '1' && command != '2' && command != '3' && command != '4' && command != '5' && command != '6'  && command != '7' && command != 27) {
      std::cout << "please input again!" << std::endl;
      std::cout << "> ";
      std::cin >> command;
      std::cout << std::endl;
    }

}