#include "blackboard.h"

namespace icra_roboin_behavior{

Blackboard::Blackboard()
{
	ros::NodeHandle nh;
	referee_game_status = nh.subscribe("game_status",1,&Blackboard::GameStatusCB,this);
        referee_game_result = nh.subscribe("game_result",1,&Blackboard::GameResultCB,this);
        referee_game_survivor = nh.subscribe("game_survivor",1,&Blackboard::GameSurvivorCB,this);
        referee_bonus_status = nh.subscribe("field_bonus_status",1,&Blackboard::BonusStatusCB,this);
        referee_supplier_status = nh.subscribe("field_supplier_status",1,&Blackboard::SupplierStatusCB,this);
        referee_robot_status = nh.subscribe("robot_status",1,&Blackboard::RobotStatusCB,this);
        referee_robot_heat = nh.subscribe("robot_heat",1,&Blackboard::RobotHeatCB,this);
        referee_robot_bonus = nh.subscribe("robot_bonus",1,&Blackboard::RobotBonusCB,this);
        referee_robot_damage = nh.subscribe("robot_damage",1,&Blackboard::RobotDamageCB,this);
        referee_robot_shoot = nh.subscribe("robot_shoot",1,&Blackboard::RobotShootCB,this);
        referee_projectile_supply = nh.subscribe("projectile_supply",1,&Blackboard::ProjectileSupplyCB,this);

        my_pose_setting = nh.subscribe("amcl_pose",1,&Blackboard::MyPoseCB,this);
        ally_pose_setting = nh.subscribe("ally_pose",1,&Blackboard::AllyPoseCB,this);

        vision = nh.subscribe("enemy_info",1,&Blackboard::VisionCB,this);



}
////////////////////////////////////////////////////////////////
//////////////////////////  callback  //////////////////////////
////////////////////////////////////////////////////////////////
void Blackboard::GameStatusCB(const roborts_msgs::GameStatus::ConstPtr& msg){
    	gamestatus.game_status = msg->game_status;
	gamestatus.remaining_time = msg->remaining_time;
}

void Blackboard::GameResultCB(const roborts_msgs::GameResult::ConstPtr& msg){
   	gameresult.result = msg->result;
}

void Blackboard::GameSurvivorCB(const roborts_msgs::GameSurvivor::ConstPtr& msg){
        gamesurvivor.red3 = msg->red3;
        gamesurvivor.red4 = msg->red4;
        gamesurvivor.blue3 = msg->blue3;
        gamesurvivor.blue4 = msg->blue4;

}


void Blackboard::BonusStatusCB(const roborts_msgs::BonusStatus::ConstPtr& msg){
        bonusstatus.red_bonus = msg->red_bonus;
        bonusstatus.blue_bonus = msg->blue_bonus;

}

void Blackboard::SupplierStatusCB(const roborts_msgs::SupplierStatus::ConstPtr& msg){
        supplierstatus.status = msg->status;
}

void Blackboard::RobotStatusCB(const roborts_msgs::RobotStatus::ConstPtr& msg){
        robotstatus.id = msg->id;
        robotstatus.level = msg->level;;
        robotstatus.remain_hp = msg->remain_hp;
        robotstatus.max_hp = msg->max_hp;
        robotstatus.heat_cooling_limit = msg->heat_cooling_limit;
        robotstatus.heat_cooling_rate = msg->heat_cooling_rate;
        robotstatus.gimbal_output = msg->gimbal_output;
        robotstatus.chassis_output = msg->chassis_output;
        robotstatus.shooter_output = msg->shooter_output;

}

void Blackboard::RobotHeatCB(const roborts_msgs::RobotHeat::ConstPtr& msg){
        robotheat.chassis_volt = msg->chassis_volt;
        robotheat.chassis_current = msg->chassis_current;
        robotheat.chassis_power = msg->chassis_power;
        robotheat.chassis_power_buffer = msg->chassis_power_buffer;
        robotheat.shooter_heat = msg->shooter_heat;
}

void Blackboard::RobotBonusCB(const roborts_msgs::RobotBonus::ConstPtr& msg){
        robotbonus.bonus = msg->bonus;
}

void Blackboard::RobotDamageCB(const roborts_msgs::RobotDamage::ConstPtr& msg){
        robotdamage.damage_type = msg->damage_type;
        robotdamage.damage_source = msg->damage_source;
}

void Blackboard::RobotShootCB(const roborts_msgs::RobotShoot::ConstPtr& msg){
        robotshoot.frequency = msg->frequency;
        robotshoot.speed = msg->speed;
}

void Blackboard::ProjectileSupplyCB(const roborts_msgs::ProjectileSupply::ConstPtr& msg){
        projectilesupply.suupply = msg->supply;
}

void Blackboard::MyPoseCB(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg){
    my_pose.pose = msg->pose.pose;
}

void Blackboard::AllyPoseCB(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg){
    ally_pose.pose = msg->pose.pose;
}

void Blackboard::VisionCB(const icra_roboin_msgs::YoloDetectionInfo::ConstPtr& msg){
    vision_data.enemy_detected = msg->enemy_detected; //1 engage 2 enemy 3 dead
    vision_data.angle_hori = msg->angle_hori;
    vision_data.distance = msg->distance;
}


////////////////////////////////////////////////////////////////////
//////////////////////////  get function  //////////////////////////
////////////////////////////////////////////////////////////////////
int Blackboard::get_ally_last_buff_time(){
    if(robotstatus.id == 3 || robotstatus.id == 4){
        if(bonusstatus.red_bonus==1){
            ally_last_buff_time = 180 - gamestatus.remaining_time;
        }
    }

    else if(robotstatus.id == 13 || robotstatus.id == 14){
        if(bonusstatus.blue_bonus==1){
            ally_last_buff_time = 180 - gamestatus.remaining_time;
        }
    }
    return ally_last_buff_time;
}

int Blackboard::get_enemy_last_buff_time(){
    if(robotstatus.id == 3 || robotstatus.id == 4){
        if(bonusstatus.blue_bonus==1){
            enemy_last_buff_time = 180 - gamestatus.remaining_time;
        }
    }

    else if(robotstatus.id == 13 || robotstatus.id == 14){
        if(bonusstatus.red_bonus==1){
            enemy_last_buff_time = 180 - gamestatus.remaining_time;
        }
    }
    return enemy_last_buff_time;

}

int Blackboard::get_my_hp(){
    return my_hp;
}

int Blackboard::get_ammo(){
    return ammo;
}

bool Blackboard::get_is_hit(){
    if(robotdamage.damage_type == 0 || robotdamage.damage_type == 1 || robotdamage.damage_type == 2 || robotdamage.damage_type == 3){
        is_hit = 1;
    }
    else{
        is_hit = 0;
    }
    return is_hit;
}

int Blackboard::get_which_armor(){
    which_armor = robotdamage.damage_source;
    return which_armor;
    //0 front 1 back 2 left 3 right
}

int Blackboard::get_last_hit_time(){
    if(is_hit()){
        last_hit_time = 180 - gamestatus.remaining_time;
    }

    return last_hit_time;
}

geometry_msgs::PoseStamped Blackboard::get_my_pose(){
    return my_pose;
}

geometry_msgs::PoseStamped Blackboard::get_ally_pose(){
    return ally_pose;
}

geometry_msgs::PoseStamped Blackboard::get_enemy1_position();
geometry_msgs::PoseStamped Blackboard::get_enemy2_position();
int Blackboard::get_enemy1_posetime();
int Blackboard::get_enemy2_posetime();
ros::Time Blackboard::get_starttime(){
    starttime = ros::Time::now();
    return starttime;
}

int Blackboard::get_number_of_detection(){
    return number_of_detection
}




///////////////////////////////////////////////////////////////
///////////////////// vision massage //////////////////////////
///////////////////////////////////////////////////////////////















}



/*
#game status
uint8 PRE_MATCH = 0
uint8 SETUP = 1
uint8 INIT = 2
uint8 FIVE_SEC_CD = 3
uint8 ROUND = 4
uint8 CALCULATION = 5
uint8 game_status
uint16 remaining_time

#bonus zone status
uint8 UNOCCUPIED = 0
uint8 BEING_OCCUPIED= 1
uint8 OCCUPIED = 2
uint8 red_bonus
uint8 blue_bonus


#game result
uint8  DRAW=0
uint8  RED_WIN=1
uint8  BLUE_WIN=2
uint8  result

#game survival
bool red3
bool red4
bool blue3
bool blue4

#projectile supply
bool supply

#robot bonus
bool bonus

#robot damage
uint8 ARMOR = 0
uint8 OFFLINE = 1
uint8 EXCEED_HEAT = 2
uint8 EXCEED_POWER = 3
uint8 damage_type
uint8 FORWARD = 0
uint8 BACKWARD = 1
uint8 LEFT = 2
uint8 RIGHT = 3
uint8 damage_source

#robot power and heat data
uint16 chassis_volt
uint16 chassis_current
float64  chassis_power
uint16 chassis_power_buffer
uint16 shooter_heat

#robot shoot data
uint8 frequency
float64 speed

#robot status
uint8 id
uint8 level
uint16 remain_hp
uint16 max_hp
uint16 heat_cooling_limit
uint16 heat_cooling_rate
bool gimbal_output
bool chassis_output
bool shooter_output

#supplier status
uint8 CLOSE = 0
uint8 PREPARING = 1
uint8 SUPPLYING = 2
uint8 status
*/
