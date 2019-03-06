#include "gimbal_executor.h"

#define PI 3.141592

namespace roborts_decision{
GimbalExecutor::GimbalExecutor():excution_mode_(ExcutionMode::IDLE_MODE),
                                 execution_state_(BehaviorState::IDLE){
  ros::NodeHandle nh;
  cmd_gimbal_angle_pub_ = nh.advertise<roborts_msgs::GimbalAngle>("cmd_gimbal_angle", 1);
  cmd_gimbal_rate_pub_  = nh.advertise<roborts_msgs::GimbalRate>("cmd_gimbal_rate", 1);

}

void GimbalExecutor::Execute(const roborts_msgs::GimbalAngle &gimbal_angle){
  excution_mode_ = ExcutionMode::ANGLE_MODE;
  cmd_gimbal_angle_pub_.publish(gimbal_angle);
}

// void GimbalExecutor::Execute(){
//   excution_mode_ = ExcutionMode::ANGLE_MODE;
//   ros::Rate rate(2);

//   roborts_msgs::GimbalAngle gimbal_angle_;

//   gimbal_angle_.yaw_mode = true;
//   gimbal_angle_.pitch_mode = false;

//   gimbal_angle_.pitch_angle = 0.0;

//   int i = 0;

//   while(ros::ok()){
    
//     gimbal_angle_.yaw_angle = abs(sin(i*PI/180)) * PI/2;
//     i++;
//     cmd_gimbal_angle_pub_.publish(gimbal_angle_);
//     std::cout<<1;
//     rate.sleep();
//   }

// }

void GimbalExecutor::Execute(const roborts_msgs::GimbalRate &gimbal_rate){
  excution_mode_ = ExcutionMode::RATE_MODE;
  cmd_gimbal_rate_pub_.publish(gimbal_rate);
}

BehaviorState GimbalExecutor::Update(){
  switch (excution_mode_){
    case ExcutionMode::IDLE_MODE:
      execution_state_ = BehaviorState::IDLE;
      break;

    case ExcutionMode::ANGLE_MODE:
      execution_state_ = BehaviorState::RUNNING;
      break;

    case ExcutionMode::RATE_MODE:
      execution_state_ = BehaviorState::RUNNING;
      break;

    default:
      ROS_ERROR("Wrong Execution Mode");
  }
  return execution_state_;
}

void GimbalExecutor::Cancel(){
  switch (excution_mode_){
    case ExcutionMode::IDLE_MODE:
      ROS_WARN("Nothing to be canceled.");
      break;

    case ExcutionMode::ANGLE_MODE:
      cmd_gimbal_rate_pub_.publish(zero_gimbal_rate_);
      excution_mode_ = ExcutionMode::IDLE_MODE;
      break;

    case ExcutionMode::RATE_MODE:
      cmd_gimbal_rate_pub_.publish(zero_gimbal_rate_);
      excution_mode_ = ExcutionMode::IDLE_MODE;
      break;

    default:
      ROS_ERROR("Wrong Execution Mode");
  }

}
}