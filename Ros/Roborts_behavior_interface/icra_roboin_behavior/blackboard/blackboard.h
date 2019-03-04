#ifndef ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H
#define ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H


#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseStamped.h>
#include "../enums.h"
#include "roborts_msgs/ArmorDetectionAction.h"
#include <memory>



namespace icra_roboin_behavior {




class Blackboard {
    

    public:
        Blackboard();
        ~Blackboard() = default;
        
        int GetStartTime();
        int GetDefenseTimeLeft();
        bool HasDefenseBonus();

        const geometry_msgs::PoseStamped GetMyPose();
        geometry_msgs::PoseStamped GetEnemyPose() const;
        geometry_msgs::PoseStamped GetGoalPose() const;
        geometry_msgs::PoseStamped GetGoalPoseQuaternion() const;

        bool IsNewGoalPose();
        bool IsEnemyDetected();

        icra_roboin_behavior::BehaviorStyle GetBehaviorStyle();
        icra_roboin_behavior::BehaviorState GetBehaviorState();
        
        void SetGoalPose(const geometry_msgs::PoseStamped new_goal_pose);
        void SetBehaviorStyle(const icra_roboin_behavior::BehaviorStyle new_style);
        void SetBehaviorState(const icra_roboin_behavior::BehaviorState new_state);
        
        void EnemyDetectionFeedbackCB(const roborts_msgs::ArmorDetectionFeedbackConstPtr& feedback);
        

    private:
        
        int game_start_timestamp_; 
        bool has_defense_bonus_;
        int defense_time_left_;

        geometry_msgs::PoseStamped my_pose_;
        geometry_msgs::PoseStamped amcl_pose_;
        geometry_msgs::PoseStamped uwb_pose_;
        void UpdateMyPose();

        geometry_msgs::PoseStamped enemy_pose_;
        geometry_msgs::PoseStamped enemy_pose_estimate_;
        bool is_enemy_detected_;
        bool is_enemy_new_;
        void EnemyAlert();
        void UpdateEnemyPose(geometry_msgs::PoseStamped enemy);
        roborts_msgs::ArmorDetectionGoal enemy_detection_command_;

        geometry_msgs::PoseStamped goal_pose_;
        bool is_new_goal_pose_;

        icra_roboin_behavior::BehaviorStyle behavior_style_;
        icra_roboin_behavior::BehaviorState behavior_state_;

        std::shared_ptr<tf::TransformListener> tf_ptr_;
        actionlib::SimpleActionClient<roborts_msgs::ArmorDetectionAction> enemy_detection_action_client_;
        

};






}
#endif

