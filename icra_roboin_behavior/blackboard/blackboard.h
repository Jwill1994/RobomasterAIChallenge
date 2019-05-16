#ifndef ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H
#define ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H


#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseStamped.h>
#include <memory>
#include <vector>
#include <array>
#include <algorithm>
#include "../enums.h"
#include "../constants.h"
#include "icra_roboin_msgs/YoloDetectionInfo.h"
#include "icra_roboin_msgs/GoalDescription.h"
#include "icra_roboin_msgs/RefereeGameState.h"
#include "icra_roboin_msgs/RefereeHit.h"
#include "icra_roboin_msgs/RefereePenalty.h"
#include "icra_roboin_msgs/RefereeBuff.h"
#include "icra_roboin_msgs/RefereeReload.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>

#include "roborts_msgs/GameStatus.h"
#include "roborts_msgs/GameResult.h"
#include "roborts_msgs/GameSurvivor.h"
#include "roborts_msgs/BonusStatus.h"
#include "roborts_msgs/SupplierStatus.h"
#include "roborts_msgs/RobotStatus.h"
#include "roborts_msgs/RobotHeat.h"
#include "roborts_msgs/RobotBonus.h"
#include "roborts_msgs/RobotDamage.h"
#include "roborts_msgs/RobotShoot.h"
#include "roborts_msgs/ProjectileSupply.h"


namespace icra_roboin_behavior {



class Blackboard {
    private:
        ros::Subscriber referee_game_status;
        ros::Subscriber referee_game_result;
        ros::Subscriber referee_game_survivor;
        ros::Subscriber referee_bonus_status;
        ros::Subscriber referee_supplier_status;
        ros::Subscriber referee_robot_status;
        ros::Subscriber referee_robot_heat;
        ros::Subscriber referee_robot_bonus;
        ros::Subscriber referee_robot_damage;
        ros::Subscriber referee_robot_shoot;
        ros::Subscriber referee_projectile_supply;

        ros::Subscriber my_pose_setting;
///////////////////////////////////////////////////////////////
/////////////////////////  callback  //////////////////////////
///////////////////////////////////////////////////////////////
        void GameStatusCB(const roborts_msgs::GameStatus::ConstPtr& msg);
        void GameResultCB(const roborts_msgs::GameResult::ConstPtr& msg);
        void GameSurvivorCB(const roborts_msgs::GameSurvivor::ConstPtr& msg);
        void BonusStatusCB(const roborts_msgs::BonusStatus::ConstPtr& msg);
        void SupplierStatusCB(const roborts_msgs::SupplierStatus::ConstPtr& msg);
        void RobotStatusCB(const roborts_msgs::RobotStatus::ConstPtr& msg);
        void RobotHeatCB(const roborts_msgs::RobotHeat::ConstPtr& msg);
        void RobotBonusCB(const roborts_msgs::RobotBonus::ConstPtr& msg);
        void RobotDamageCB(const roborts_msgs::RobotDamage::ConstPtr& msg);
        void RobotShootCB(const roborts_msgs::RobotShoot::ConstPtr& msg);
        void ProjectileSupplyCB(const roborts_msgs::ProjectileSupply::ConstPtr& msg);

        void MyPoseCB(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);
    

    public: //Interfaces
        Blackboard(TeamType team, RuleType rule);
        ~Blackboard() = default;

        /*   Referee Info Interface   */
        //Game State Info
        ros::Time GetTimeGameStarted() const;
        const ros::Time GetTimePassedFromGameStart();
        GameState GetGameState();
        //Zone Info
        bool GetIsBuffZoneOnline();
        ros::Time GetTimeLastBuffed();
        const ros::Time GetTimeLeftForBuffZoneToOnline();
        bool GetIsReloadZoneOnline();
        ros::Time GetTimeLastReloaded();
        const ros::Time GetTimeLeftForReloadZoneToOnline();  //TODO need to be changed to abide rule
        //HP Info
        int GetMyHealth();
        bool GetIsHitFastResponse() const; // read only, got hit by enemy and need urgent behavior-level response 
        void ConfirmHitFastResponse();  // set is_hit_fast_response to false, set hit_confirmed_fast_response_ true,
        bool GetHitConfirmedFastResponse() const; // meaning every behavior-level measure ought to be taken when hit is finished
        bool GetIsHitSmartResponse() const; // read only, got hit by enemy and need intelligent decision-level response
        void ConfirmHitSmartResponse();  // set is_hit_smart_response to false, set hit_confirmed_smart_response_ true,
        bool GetHitConfirmedSmartResponse() const; //meaning every decision-level measure ought to be taken when hit is finished
        ArmorType GetWhichArmorHit();
        ros::Time GetTimeLastHit();
        //Defense Buff Info
        bool GetHasBuff();
        const ros::Time GetTimeBuffLeft();
        //Ammunition Info
        int GetAmmo() const;
        bool GetIsReloading();

        /*   Team Info Interface   */
        geometry_msgs::PoseStamped GetAllyPose() const;
        TeamType GetMyTeam();
        bool GetIsAllyAlive() const;

        /*   Perception Info Interface   */
        const geometry_msgs::PoseStamped GetMyPose(); // get my pose from TF. lazily updates my_pose_.
        geometry_msgs::PoseStamped GetAllyPoseFromVision() const;
        geometry_msgs::PoseStamped GetEnemyPose(PlayerType who) const; //who: ENEMY_ONE ENEMY_TWO
        geometry_msgs::PoseStamped GetEnemyEstim(PlayerType who) const; //who: ENEMY_ONE ENEMY_TWO
        int GetNumberOfDetectedEnemies() const;
        bool GetIsEnemyDetected(PlayerType who) const; //who: ENEMY_ONE ENEMY_TWO ENEMY_ANY
        PlayerType GetWhichEnemyDetected() const;
        bool GetIsNewEnemy() const; //read only
        bool IsNewEnemy(); //when called, is_enemy_new_ is set to false
        ros::Time GetTimeLastSeen(PlayerType who) const;
        
        /*   Behavior Info Interface   */
        PlayerType GetLockedOnEnemy() const; 
        bool GetIsNewLockonTarget() const; //read only
        bool IsNewLockonTarget(); //when called, is_new_lockon_target_ is set to false
        bool GetIsNewGoal() const; //read only
        bool IsNewGoal(); //when called, is_new_goal_ is set to false
        icra_roboin_msgs::GoalDescription GetGoal() const; // goal for current behavior
        const geometry_msgs::PoseStamped GetGoalPoseQuaternion(); // transform goal pose into quaternion lazily.
        BehaviorStyle GetBehaviorStyle() const;
        BehaviorProcess GetBehaviorProcess() const;

        /*   Smart Decision and Tactics Info Interface   */
        PlayerType GetEnemyPriority() const;



        /*   External Set Interface   */
        void SetGoal(const icra_roboin_msgs::GoalDescription goal);
        void SetBehaviorStyle(const BehaviorStyle new_style);
        void SetBehaviorProcess(const BehaviorProcess process);
        void SetEnemyPriority(const PlayerType who);
        void SetLockedOnEnemy(const PlayerType who); //who: ALLY, ENEMY_ONE ENEMY_TWO       ALLY means do not lock on
        void AmmoMinusOne();
        void SetIsReloading(const bool flag);

        ros::Time timer;






        //fix from here








    private: // Referee Info

        //Game State Info
        ros::Time time_game_started_ = ros::Time(0);
        ros::Time time_passed_from_game_start_ = ros::Time(0);
        GameState game_state_ = GameState::PLAY;
        RuleType game_rule_ = RuleType::TWO_VS_TWO; //1vs1, 2vs2...
        PenaltyType penalty_received_;

        //Zone Info
        bool is_buff_zone_online_=true;
        ros::Time time_last_buffed_ = ros::Time(0);
        ros::Time time_left_for_buff_zone_to_online_ = ros::Time(0);
        bool is_reload_zone_online_=true;
        ros::Time time_last_reloaded_ = ros::Time(0);
        ros::Time time_left_for_reload_zone_to_online_ = ros::Time(0);

        //HP Info
        int my_health_ = 2000;
        bool is_hit_fast_response_=false;
        bool is_hit_smart_response_=false;
        bool hit_confirmed_fast_response_=false;
        bool hit_confirmed_smart_response_=false;
        ArmorType which_armor_hit_ = ArmorType::FRONT;
        ros::Time time_last_hit_ = ros::Time(0);

        //Defense Buff Info
        bool has_buff_=false;
        ros::Time time_buff_left_ = ros::Time(0);
        bool has_enemy_buff_=false;
        ros::Time time_enemy_buff_left_ = ros::Time(0);
        std::array<double,3> enemy_buff_time_estimation_moments_; //variance, skewness, kurtosis

        //Ammunition Info
        int ammo_ = 50;
        bool is_reloading_ = false;

    private: //Team Info
        geometry_msgs::PoseStamped ally_pose_;
        TeamType my_team_;
        bool is_ally_alive_=false;
        
    private: // Perception Info

        //My Pose
        geometry_msgs::PoseStamped my_pose_;
        geometry_msgs::PoseStamped amcl_pose_;
        geometry_msgs::PoseStamped uwb_pose_;

        //Enemy Pose
        geometry_msgs::PoseStamped enemy_pose_1_;  //real pose from vision
        geometry_msgs::PoseStamped enemy_pose_2_;  
        geometry_msgs::PoseStamped enemy_pose_1_ghost_;  //last seen location
        geometry_msgs::PoseStamped enemy_pose_2_ghost_;
        geometry_msgs::PoseStamped enemy_pose_1_estim_;  //approximate enemy location estimated by AI
        geometry_msgs::PoseStamped enemy_pose_2_estim_;
        ros::Time time_enemy_1_last_seen_ = ros::Time(0);
        ros::Time time_enemy_2_last_seen_ = ros::Time(0);
        ros::Time time_enemy_last_seen_ = ros::Time(0);

        //Ally Pose
        geometry_msgs::PoseStamped ally_pose_from_vision_;  //ally pose from vision
        ros::Time time_ally_last_seen_ = ros::Time(0);

        //Unknown Pose
        geometry_msgs::PoseStamped unknown_pose_;  //real pose from vision  
        geometry_msgs::PoseStamped unknown_pose_ghost_;  //last seen location
        geometry_msgs::PoseStamped unknown_pose_estim_;  //approximate enemy location estimated by AI
        ros::Time time_unknown_last_seen_ = ros::Time(0);


        //Detection Info
        int number_of_detection_;
        int number_of_detected_enemies_ = 0;

        bool is_ally_detected_=false;
        bool is_enemy_1_detected_=false;
        bool is_enemy_2_detected_=false;
        bool is_enemy_detected_=false;
        bool is_unknown_detected_=false;

        bool is_new_enemy_=false;

    private: // Behavior Info

        PlayerType locked_on_enemy_ = PlayerType::UNKNOWN; // who: ALLY, ENEMY_ONE ENEMY_TWO       ALLY means do not lock on
        bool is_new_lockon_target_=false;
        bool is_new_goal_=false;
        icra_roboin_msgs::GoalDescription goal_;
        geometry_msgs::PoseStamped goal_pose_quaternion_;
        BehaviorStyle behavior_style_;
        BehaviorProcess behavior_process_;

    private: // Smart Decision and Tactics Info
        PlayerType enemy_priority_ = PlayerType::ENEMY_ONE;





///////////////////Techincal//////////////////////////



    private: //Resources
        std::shared_ptr<tf::TransformListener> tf_ptr_;
        ros::Subscriber enemy_detection_sub_;  // receives Yolo detection result.   Topic name:"enemy_info"
        std::string namespace_;  // ROS namespace of this node


    
    public: // Callback functions
        void EnemyDetectionCB(const icra_roboin_msgs::YoloDetectionInfo::ConstPtr& yolo);  // callback for detection_sub_ Topic name: "enemy_info"
        

        

    private: //Private Member Functions
        void UpdateMyPose();
        void UpdateTime();
        void TransformGoalPoseQuaternion();
        void EnemyAlert();

    private: //referee
        ////////////////////////////////////////////////////////////////////////////
        /////////////////////// referee value //////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////
        roborts_msgs::GameStatus gamestatus;
        roborts_msgs::GameResult gameresult;
        roborts_msgs::GameSurvivor gamesurvivor;
        roborts_msgs::BonusStatus bonusstatus;
        roborts_msgs::SupplierStatus supplierstatus;
        roborts_msgs::RobotStatus robotstatus;
        roborts_msgs::RobotHeat robotheat;
        roborts_msgs::RobotBonus robotbonus;
        roborts_msgs::RobotDamage robotdamage;
        roborts_msgs::RobotShoot robotshoot;
        roborts_msgs::ProjectileSupply projectilsupply;
        geometry_msgs::PoseWithCovarianceStamped my_amcl_pose;

};











}
#endif


