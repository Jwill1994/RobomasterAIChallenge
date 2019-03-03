#include "blackboard.h"

namespace icra_roboin_behavior{



Blackboard::Blackboard(): is_enemy_detected_(false),
                            enemy_detection_action_client_("armor_detection_node_action",true),
                            behavior_style_(icra_roboin_behavior::BehaviorStyle::STOP),behavior_state_(icra_roboin_behavior::BehaviorState::IDLE)
{
    tf_ptr_ = std::make_shared<tf::TransformListener>(ros::Duration(10));
    
    if(false){   //temporarily disable enemy detection for development
        enemy_detection_action_client_.waitForServer();
        ROS_INFO("enemy detection server connected");
        enemy_detection_command_.command = 1; // 1: start    2: pause    3: stop
        enemy_detection_action_client_.sendGoal(enemy_detection_command_,
                                                actionlib::SimpleActionClient<roborts_msgs::ArmorDetectionAction>::SimpleDoneCallback(),
                                                actionlib::SimpleActionClient<roborts_msgs::ArmorDetectionAction>::SimpleActiveCallback(),
                                                boost::bind(&Blackboard::EnemyDetectionFeedbackCB, this, _1));
    }
    
}

//todo
int Blackboard::GetStartTime() {return game_start_timestamp_;}
int Blackboard::GetDefenseTimeLeft() {return defense_time_left_;}
bool Blackboard::HasDefenseBonus() {return has_defense_bonus_;}
//




void Blackboard::EnemyDetectionFeedbackCB(const roborts_msgs::ArmorDetectionFeedbackConstPtr& feedback){
    if (feedback->detected){
        is_enemy_detected_ = true;
        EnemyAlert();
        ROS_INFO("Enemy Detected!");
        UpdateEnemyPose(feedback->enemy_pos);

    } else {
        is_enemy_detected_ = false;
    }
}

const geometry_msgs::PoseStamped Blackboard::GetMyPose(){
    UpdateMyPose();
    return my_pose_;
}

geometry_msgs::PoseStamped Blackboard::GetEnemyPose() const{
    return enemy_pose_;
}

geometry_msgs::PoseStamped Blackboard::GetGoalPose() const{
    return goal_pose_;
}

bool Blackboard::IsNewGoalPose() {
    if(is_new_goal_pose_){
        is_new_goal_pose_ = false;
        return true;
    } else {
        return false;
    }
}

bool Blackboard::IsEnemyDetected() {
    return is_enemy_detected_;
}


void Blackboard::UpdateMyPose() {
    tf::Stamped<tf::Pose> my_tf_pose;
    my_tf_pose.setIdentity();
    my_tf_pose.frame_id_="base_link";
    my_tf_pose.stamp_=ros::Time();
    try {
        geometry_msgs::PoseStamped my_pose;
        tf::poseStampedTFToMsg(my_tf_pose,my_pose);
        tf_ptr_ -> transformPose("map", my_pose, my_pose_);
    }
    catch (tf::LookupException& ex) {
        ROS_ERROR("blackboard UpdateMyPose error :%s", ex.what());
    }
}

void Blackboard::UpdateEnemyPose(geometry_msgs::PoseStamped enemy) {
    tf::Stamped<tf::Pose> enemy_cam_tf, enemy_global_tf;
    geometry_msgs::PoseStamped enemy_cam_pose, enemy_global_pose;
    enemy_cam_pose = enemy;
    double distance = std::sqrt(std::pow(enemy_cam_pose.pose.position.x,2) + std::pow(enemy_cam_pose.pose.position.y,2));
    double yaw = std::atan(enemy_cam_pose.pose.position.y/enemy_cam_pose.pose.position.x);
    tf::Quaternion _q = tf::createQuaternionFromRPY(0,0,yaw);
    enemy_cam_pose.pose.orientation.w = _q.w();
    enemy_cam_pose.pose.orientation.x = _q.x();
    enemy_cam_pose.pose.orientation.y = _q.y();
    enemy_cam_pose.pose.orientation.z = _q.z();
    tf::poseStampedMsgToTF(enemy_cam_pose, enemy_cam_tf);
    enemy_cam_tf.stamp_ = ros::Time(0);
    try
    {
        tf_ptr_->transformPose("map",enemy_cam_tf,enemy_global_tf);
        tf::poseStampedTFToMsg(enemy_global_tf,enemy_global_pose);
        enemy_pose_ = enemy_global_pose;
    }
    catch (tf::TransformException& ex) {
        ROS_ERROR("blackboard UpdateEnemyPose tf error");
    }
}

void Blackboard::EnemyAlert(){
//TODO
}




icra_roboin_behavior::BehaviorStyle Blackboard::GetBehaviorStyle(){
    return behavior_style_;
}
icra_roboin_behavior::BehaviorState Blackboard::GetBehaviorState(){
    return behavior_state_;
}


void Blackboard::SetGoalPose(const geometry_msgs::PoseStamped new_goal_pose){
    goal_pose_ = new_goal_pose;
    is_new_goal_pose_ = true;
}
void Blackboard::SetBehaviorStyle(const icra_roboin_behavior::BehaviorStyle new_style){
    behavior_style_ = new_style;
}
void Blackboard::SetBehaviorState(const icra_roboin_behavior::BehaviorState new_state){
    behavior_state_ = new_state;
}





}