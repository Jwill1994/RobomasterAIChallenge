#include "behavior_interface.h"

namespace icra_roboin_behavior {

BehaviorInterface::BehaviorInterface(icra_roboin_behavior::ChassisExecutor*& chassis_executor,
                    icra_roboin_behavior::GimbalExecutor*& gimbal_executor,
                    icra_roboin_behavior::Blackboard*& blackboard,
                    std::vector<std::shared_ptr<icra_roboin_behavior::BehaviorBase>>& behavior_factory): 
                                                                    chassis_executor_(chassis_executor),
                                                                    gimbal_executor_(gimbal_executor),
                                                                    blackboard_(blackboard),
                                                                    behavior_factory_(behavior_factory)
                                                                    
{
  ros::NodeHandle nh("~");
  set_behavior_style_service_ = nh.advertiseService("behavior_select_service",&BehaviorInterface::SetBehaviorStyleCB,this);
  set_goal_service_ = nh.advertiseService("goal_select_service",&BehaviorInterface::SetBehaviorGoalCB,this);
  general_info_server_ = nh.advertiseService("blackboard/general_info_service",&BehaviorInterface::GetGeneralInfoServiceCB,this);
}

bool BehaviorInterface::SetBehaviorStyleCB(icra_roboin_msgs::BehaviorStyleSet::Request &req, icra_roboin_msgs::BehaviorStyleSet::Response &res) {
  int tmp = req.behavior;
  if (int(blackboard_->GetBehaviorStyle()) == tmp){
    res.is_new = false;
  } else {
    res.is_new = true;
    //ROS_INFO("req:%d,BB:%d",tmp,int(blackboard_->GetBehaviorStyle());
    chassis_executor_->Cancel();
    gimbal_executor_->Cancel();
  }
  blackboard_->SetBehaviorStyle(static_cast<icra_roboin_behavior::BehaviorStyle>(tmp));
  ROS_DEBUG("behavior interface: Behavior received: %d",req.behavior);
  return true;
}

bool BehaviorInterface::SetBehaviorGoalCB(icra_roboin_msgs::BehaviorGoalSet::Request &req, icra_roboin_msgs::BehaviorGoalSet::Response &res) {
  blackboard_ -> SetGoalPose(req.goal);
  res.is_new = true;
  ROS_DEBUG("behavior interface: Goal received: %f,%f,%f",req.goal.pose.position.x,req.goal.pose.position.y,req.goal.pose.position.z);
  return true;
}

bool BehaviorInterface::GetGeneralInfoServiceCB(icra_roboin_msgs::BlackboardGeneralInfo::Request& req, 
                                        icra_roboin_msgs::BlackboardGeneralInfo::Response& resp)
{
    UpdateBlackboardState();
    resp.stamp = ros::Time();
    resp.my_pose = blackboard_->GetMyPose();
    resp.enemy_pose = blackboard_->GetEnemyPose();
    resp.goal_pose = blackboard_->GetGoalPose();
    resp.is_enemy_detected = blackboard_-> IsEnemyDetected();
    resp.has_defense_bonus = blackboard_-> HasDefenseBonus();
    resp.defense_time_left = blackboard_-> GetDefenseTimeLeft();
    resp.current_behavior_state = int(blackboard_->GetBehaviorState());
    resp.current_behavior_style = int(blackboard_->GetBehaviorStyle());

    return true;
}






void BehaviorInterface::Run(){
  for(auto behav: behavior_factory_){
    if(behav->GetBehaviorStyle()==blackboard_->GetBehaviorStyle()){
      behav->Run();
      break;
    }
  }
}


void BehaviorInterface::UpdateBlackboardState(){
  for(auto behav: behavior_factory_){
    if(behav->GetBehaviorStyle()==blackboard_->GetBehaviorStyle()){
      blackboard_->SetBehaviorState(behav->Update());
      break;
    }
  }
}










}