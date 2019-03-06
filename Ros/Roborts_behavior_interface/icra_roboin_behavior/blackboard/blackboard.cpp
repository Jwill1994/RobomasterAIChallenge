#include "blackboard.h"

namespace icra_roboin_behavior{



Blackboard::Blackboard(): is_enemy_detected_(false),
                            behavior_style_(icra_roboin_behavior::BehaviorStyle::STOP),
                            behavior_state_(icra_roboin_behavior::BehaviorState::IDLE)
{
    ros::NodeHandle nh;
    sub_ = nh.subscribe("enemy_info",5,&Blackboard::EnemyDetectionCB,this);
    tf_ptr_ = std::make_shared<tf::TransformListener>(ros::Duration(10));
    
    
    
}

//todo
int Blackboard::GetStartTime() {return game_start_timestamp_;}
int Blackboard::GetDefenseTimeLeft() {return defense_time_left_;}
bool Blackboard::HasDefenseBonus() {return has_defense_bonus_;}
//




void Blackboard::EnemyDetectionCB(const icra_roboin_msgs::YoloDetectionInfo::ConstPtr& yolo){
    if (yolo->number_of_detection != 0){
        is_enemy_detected_ = true;
        EnemyAlert();
        ROS_INFO("Enemy Detected!");
        enemy_poses_.clear();
        number_of_enemy_=0;
        for(int i=0;i>2;i++){
            tf::Stamped<tf::Pose> enemy_cam_tf, enemy_global_tf;
            geometry_msgs::PoseStamped enemy_cam_pose, enemy_global_pose;
            enemy_cam_pose.header.frame_id="camera";
            enemy_cam_pose.header.stamp = yolo->stamp;
            enemy_cam_pose.pose.position.z = yolo->distance[i] * std::sin((float(yolo->angle_verti[i]) / 100)*3.141592/180);
            double flat_d = yolo->distance[i] * std::cos((float(yolo->angle_verti[i]) / 100)*3.141592/180);
            enemy_cam_pose.pose.position.x = flat_d * std::cos((float(yolo->angle_hori[i]) / 100)*3.141592/180);
            enemy_cam_pose.pose.position.y = flat_d * std::sin((float(yolo->angle_hori[i]) / 100)*3.141592/180);
            
            //TODO: make code to classify ally and enemy with ally pose data 
            // if (not_enemy) break;
            number_of_enemy_++;

            tf::poseStampedMsgToTF(enemy_cam_pose, enemy_cam_tf);
            enemy_cam_tf.stamp_ = ros::Time(0);
            try
            {
                tf_ptr_->transformPose("map",enemy_cam_tf,enemy_global_tf);
                tf::poseStampedTFToMsg(enemy_global_tf,enemy_global_pose);
                enemy_poses_.push_back(enemy_global_pose);
            }
            catch (tf::TransformException& ex) {
                ROS_ERROR("blackboard enemy detection callback tf error");
            }
        }
        enemy_poses_estimate_ = enemy_poses_;
    } else {
        is_enemy_detected_ = false;
        number_of_enemy_ = 0;
    }
}

const geometry_msgs::PoseStamped Blackboard::GetMyPose(){
    UpdateMyPose();
    return my_pose_;
}

std::vector<geometry_msgs::PoseStamped> Blackboard::GetEnemyPoses() const{
    return enemy_poses_;
}

int Blackboard::GetEnemyNumber() const {
    return number_of_enemy_;
}

geometry_msgs::PoseStamped Blackboard::GetGoalPose() const{
    return goal_pose_;
}

geometry_msgs::PoseStamped Blackboard::GetGoalPoseQuaternion() const{
    geometry_msgs::PoseStamped goal_pose_q;
    goal_pose_q.header=goal_pose_.header;
    goal_pose_q.pose.position.x=goal_pose_.pose.position.x;
    goal_pose_q.pose.position.y=goal_pose_.pose.position.y;
    goal_pose_q.pose.position.z=1;
    goal_pose_q.pose.orientation = tf::createQuaternionMsgFromYaw(goal_pose_.pose.position.z);
    return goal_pose_q;
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