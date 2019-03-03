#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/PoseStamped.h>
#include <icra_roboin_msgs/BehaviorStyleSet.h>
#include <icra_roboin_msgs/BehaviorGoalSet.h>
#include <tf/transform_broadcaster.h>
#include <memory>
#include <signal.h>
#include <termios.h>
#include <stdio.h>

#define KEYCODE_R 0x43 
#define KEYCODE_L 0x44
#define KEYCODE_U 0x41
#define KEYCODE_D 0x42
#define KEYCODE_Q 0x71

int kfd=0;
struct termios cooked,raw;
int behavior_;
double x,y,w;

int GetBehavior(ros::ServiceClient& client){
    int tmp;
    std::cout << "enter the index of behavior to select" << std::endl;
    std::cout << "1: goal behavior, 10: manual_speed behavior" << std::endl;
    std::cout << ">";
    std::cin >> tmp;
    std::cout << std::endl;
    std::cout << "selected behavior: " + tmp << std::endl;
    icra_roboin_msgs::BehaviorStyleSet srv;
    srv.request.behavior=tmp;
    if (client.call(srv))
    {
        if (srv.response.is_new == false) {
            ROS_INFO("already that behavior");
        } else {
            ROS_INFO("new behavior");
        }
    
    } else {
        ROS_ERROR("failed to call style service");
    }
    return tmp;
}

void GoalBehavior(ros::ServiceClient& client) {

    std::cout << "goal behavior selected!" << std::endl;
    std::cout << "enter goal destination x,y,w" << std::endl;
    std::cout << "> x:";
    std::cin >> x;
    std::cout << std::endl;
    std::cout << "> y:";
    std::cin >> y;
    std::cout << std::endl;
    std::cout << "> w:";
    std::cin >> w;
    std::cout << std::endl;

    
    icra_roboin_msgs::BehaviorGoalSet srv;
    geometry_msgs::PoseStamped pose_;

    pose_.header.frame_id  = "map";
    pose_.header.stamp = ros::Time::now();
    pose_.pose.position.x = x;
    pose_.pose.position.y = y;
    pose_.pose.position.z = 1;
    pose_.pose.orientation = tf::createQuaternionMsgFromYaw(w);

    
    srv.request.goal = pose_;

    

    if (client.call(srv))
    {
        ROS_INFO("goal sent");
    
    } else {
        ROS_ERROR("failed to call goal service");
    }

}
 



int main(int argc, char** argv)
{


    ros::init(argc, argv, "behavior_selector_node");
    ros::NodeHandle nh;
    ros::ServiceClient client1_ = nh.serviceClient<icra_roboin_msgs::BehaviorStyleSet>("behavior_node/behavior_select_service");
    ros::ServiceClient client2_ = nh.serviceClient<icra_roboin_msgs::BehaviorGoalSet>("behavior_node/goal_select_service");
    ros::Rate rate(10);
    ROS_INFO("Ros Ready!");
    

    //behavior_=GetBehavior(client1_);
    while(ros::ok()){
        behavior_=GetBehavior(client1_);
        switch(behavior_) {
            case 1:
                GoalBehavior(client2_);
                break;
            case 10:
            {
                char c;
                bool dirty = false;
                tcgetattr(kfd,&cooked);
                memcpy(&raw,&cooked,sizeof(struct termios));
                raw.c_lflag &=~ (ICANON | ECHO);
                raw.c_cc[VEOL]=1;
                raw.c_cc[VEOF]=2;
                tcsetattr(kfd, TCSANOW, &raw);
                puts("Reading from keyboard");
                puts("---------------------------");
                puts("Press Arrow for Maneuver");
                
                

                for(;;)
                {
                    if(read(kfd,&c,1)<0)
                    {
                        perror("read():");
                        exit(-1);
                    }
                    if(dirty==false){
                        switch(c)
                        {
                            case KEYCODE_L:
                            {
                                x=0;
                                y=1;
                                w=0;
                                icra_roboin_msgs::BehaviorGoalSet srv;
                                geometry_msgs::PoseStamped pose_;
                                pose_.header.frame_id  = "map";
                                pose_.header.stamp = ros::Time::now();
                                pose_.pose.position.x = x;
                                pose_.pose.position.y = y;
                                pose_.pose.position.z = w;
                                pose_.pose.orientation = tf::createQuaternionMsgFromYaw(0);

                            
                                srv.request.goal = pose_;

                                if (client2_.call(srv))
                                {
                                    ROS_INFO("goal sent");
                            
                                } else {
                                    ROS_ERROR("failed to call goal service");
                                }
                                dirty = true;
                                break;
                            }
                            case KEYCODE_R:
                            {    
                                x=0;
                                y=-1;
                                w=0;
                                icra_roboin_msgs::BehaviorGoalSet srv;
                                geometry_msgs::PoseStamped pose_;
                                pose_.header.frame_id  = "map";
                                pose_.header.stamp = ros::Time::now();
                                pose_.pose.position.x = x;
                                pose_.pose.position.y = y;
                                pose_.pose.position.z = w;
                                pose_.pose.orientation = tf::createQuaternionMsgFromYaw(0);

                            
                                srv.request.goal = pose_;

                                if (client2_.call(srv))
                                {
                                    ROS_INFO("goal sent");
                            
                                } else {
                                    ROS_ERROR("failed to call goal service");
                                }
                                dirty = true;
                                break;
                            }
                            case KEYCODE_U:
                            {
                                x=1;
                                y=0;
                                w=0;
                                icra_roboin_msgs::BehaviorGoalSet srv;
                                geometry_msgs::PoseStamped pose_;
                                pose_.header.frame_id  = "map";
                                pose_.header.stamp = ros::Time::now();
                                pose_.pose.position.x = x;
                                pose_.pose.position.y = y;
                                pose_.pose.position.z = w;
                                pose_.pose.orientation = tf::createQuaternionMsgFromYaw(0);

                            
                                srv.request.goal = pose_;

                                if (client2_.call(srv))
                                {
                                    ROS_INFO("goal sent");
                            
                                } else {
                                    ROS_ERROR("failed to call goal service");
                                }
                                dirty = true;
                                break;
                            }
                            case KEYCODE_D:
                            {  
                                x=-1;
                                y=0;
                                w=0;
                                icra_roboin_msgs::BehaviorGoalSet srv;
                                geometry_msgs::PoseStamped pose_;
                                pose_.header.frame_id  = "map";
                                pose_.header.stamp = ros::Time::now();
                                pose_.pose.position.x = x;
                                pose_.pose.position.y = y;
                                pose_.pose.position.z = w;
                                pose_.pose.orientation = tf::createQuaternionMsgFromYaw(0);

                            
                                srv.request.goal = pose_;

                                if (client2_.call(srv))
                                {
                                    ROS_INFO("goal sent");
                            
                                } else {
                                    ROS_ERROR("failed to call goal service");
                                }
                                dirty = true;
                                break;
                            }
                            default:
                                continue;
                        }
                    } else {

                        

                        dirty = false;
                    }
                    
                    
                }


                break;
            }
            default:
                std::cout << "no such behavior" << std::endl;
        }
        
        
        ros::spinOnce();
        rate.sleep(); 
    }

    


    
    

    
    return 0;



}
