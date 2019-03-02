#ifndef ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H
#define ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H


#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseStamped.h>
#include "../enums.h"
#include "roborts_msgs/ArmorDetectionAction.h"
#include "icra_roboin_msgs/SetBehavior.h"
#include "icra_roboin_msgs/BlackboardGeneralInfo.h"
#include <memory>



namespace icra_roboin_behavior {




class Blackboard {
    

    public:
        Blackboard();
        ~Blackboard() = default;
        
        const geometry_msgs::PoseStamped GetMyPose();
        geometry_msgs::PoseStamped GetEnemyPose() const;
        geometry_msgs::PoseStamped GetGoalPose() const;
        bool IsNewGoal();
        
        void EnemyDetectionFeedbackCB(const roborts_msgs::ArmorDetectionFeedbackConstPtr& feedback);

        bool GetGeneralInfoServiceCB(icra_roboin_msgs::BlackboardGeneralInfo::Request& req, icra_roboin_msgs::BlackboardGeneralInfo::Response& resp);

        void UpdateBehaviorStates();
        



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


        icra_roboin_behavior::BehaviorStyle behavior_style_;
        icra_roboin_behavior::BehaviorState behavior_state_;
        icra_roboin_behavior::ChassisMode chassis_mode_;
        icra_roboin_behavior::BehaviorState chassis_state_;
        icra_roboin_behavior::GimbalMode gimbal_mode_;
        icra_roboin_behavior::BehaviorState gimbal_state_;




        geometry_msgs::PoseStamped goal_pose_;
        bool is_new_goal_pose_;

        
        

        std::shared_ptr<tf::TransformListener> tf_ptr_;
        //ros::Subscriber sub_;
        //ros::Publisher pub_;
        actionlib::SimpleActionClient<roborts_msgs::ArmorDetectionAction> enemy_detection_action_client_;
        
        
        ros::ServiceServer general_info_server_;
        

};






}
#endif


