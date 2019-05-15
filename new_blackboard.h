#ifndef ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H
#define ICRA_ROBOIN_BEHAVIOR_BLACKBOARD_H

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

#include "roborts_msgs/GimbalAngle.h"

#include "icra_roboin_msgs/YoloDetectionInfo.h"

#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>
#include <actionlib/client/simple_action_client.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Int32.h>
#include <math.h>
#include "../tools.h"
#include <memory>
#include <vector>
#include <array>
#include <algorithm>
#include <string>
#include "../enums.h"
#include "../constants.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int32.h"
#include <geometry_msgs/PoseWithCovarianceStamped.h>

namespace icra_roboin_behavior {


class Blackboard {

    public:
        Blackboard();
        ~Blackboard()=default;


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
        ros::Subscriber ally_pose_setting;

        ros::Subscriber vision;



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
        void AllyPoseCB(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg);

        void VisionCB(const icra_roboin_msgs::YoloDetectionInfo::ConstPtr& msg);

/////////////////////////////////
////////*   game info   *////////
/////////////////////////////////

     private:

        int ally_last_buff_time;
        int enemy_last_buff_time;
        int my_hp;
        int ammo = 50;
        bool is_hit;
        int which_armor;
        int last_hit_time;
        geometry_msgs::PoseStamped my_pose;
        geometry_msgs::PoseStamped ally_pose;
        geometry_msgs::PoseStamped enemy1_position;
        geometry_msgs::PoseStamped enemy2_position;
        int enemy1_posetime;
        int enemy2_posetime;
        ros::Time starttime;
        int number_of_detection;



	


     public:
        int get_ally_last_buff_time();
        int get_enemy_last_buff_time();
        int get_my_hp();
        int get_ally_hp();
        int get_ammo();
        bool get_is_hit();
        int get_which_armor();
        int get_last_hit_time();
        geometry_msgs::PoseStamped get_my_pose();
        geometry_msgs::PoseStamped get_ally_pose();
        geometry_msgs::PoseStamped get_enemy1_position();
        geometry_msgs::PoseStamped get_enemy2_position();
        int get_enemy1_posetime();
        int get_enemy2_posetime();
        ros::Time get_starttime();
        int get_number_of_detection();

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
	roborts_msgs::ProjectileSupply projectilesupply;


        icra_roboin_msgs::YoloDetectionInfo vision_data;




/*
	int get_game_status();
	int get_remaining_time();
	int get_red_bonus();
 	int get_blue_bonus();
	int get_result();
	bool get_red3_survival();
	bool get_red4_survival();
	bool get_blue3_survival();
	bool get_blue4_survival();
	bool get_projectile_supply();
	bool get_bonus();
	int get_damage_type();
	int get_damage_source();
	int get_id();
	int get_remaining_hp();
	int get_max_hp();
	int get_supply_status();
*?



        









};


}
