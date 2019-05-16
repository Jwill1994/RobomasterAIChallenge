#include "blackboard.h"





namespace icra_roboin_behavior{



Blackboard::Blackboard(TeamType team = TeamType::BLUE_TEAM, RuleType rule = RuleType::TWO_VS_TWO):
                            my_team_(team), game_rule_(rule), game_state_(GameState::READY), 
                            ammo_(START_AMMO), my_health_(START_HEALTH), is_ally_alive_(true),
                            enemy_priority_(PlayerType::ENEMY_ANY), locked_on_enemy_(PlayerType::ALLY), //do not lockon
                            behavior_style_(icra_roboin_behavior::BehaviorStyle::READY),
                            behavior_process_(icra_roboin_behavior::BehaviorProcess::IDLE)
{
    ros::NodeHandle nh;
    enemy_detection_sub_ = nh.subscribe("enemy_info",5,&Blackboard::EnemyDetectionCB,this);
    tf_ptr_ = std::make_shared<tf::TransformListener>(ros::Duration(10));
    namespace_ = ros::this_node::getNamespace();
    namespace_.erase(0,namespace_.find_first_not_of("/"));
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
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                             */
/*                                        Get Interface                                        */
/*                                                                                             */
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/*   Referee Info Interface   */

//Game State Info
ros::Time Blackboard::GetTimeGameStarted() const{
    return time_game_started_;
}
const ros::Time Blackboard::GetTimePassedFromGameStart() {
    UpdateTime();
    return time_passed_from_game_start_;
}  
GameState Blackboard::GetGameState() {
    if(gamestatus.game_status==4){
        game_state_=GameState::PLAY;
    }
    else if(gamestatus.game_status==5){
        game_state_=GameState::END;
    }
    else{
        game_state_=GameState::READY;
    }

    return game_state_;
}
//Zone Info
bool Blackboard::GetIsBuffZoneOnline() {
    if(robotstatus.id==3 || robotstatus.id==4){
        if(bonusstatus.red_bonus==2){
        is_buff_zone_online_=false;
        }
        else{
        is_buff_zone_online_=true;
        }
    }

    else if(robotstatus.id==13 || robotstatus.id==14){
        if(bonusstatus.blue_bonus==2){
        is_buff_zone_online_=false;
        }
        else{
        is_buff_zone_online_=true;
        }
    }
    return is_buff_zone_online_;
}
ros::Time Blackboard::GetTimeLastBuffed() {
    if(robotstatus.id==3 || robotstatus.id==4){
        if(bonusstatus.red_bonus==1){
        time_last_buffed_ = this->GetTimePassedFromGameStart();
        }
    }

    else if(robotstatus.id==13 || robotstatus.id==14){
        if(bonusstatus.blue_bonus==1){
        time_last_buffed_ = this->GetTimePassedFromGameStart();
        }
    }
    return time_last_buffed_;
}  
const ros::Time Blackboard::GetTimeLeftForBuffZoneToOnline() {
    UpdateTime();
    return time_left_for_buff_zone_to_online_;
}  
bool Blackboard::GetIsReloadZoneOnline() {
    if(supplierstatus.status==0){
        is_reload_zone_online_=false;
    }
    else{
        is_reload_zone_online_=true;
    }

    return is_reload_zone_online_;
}
ros::Time Blackboard::GetTimeLastReloaded() {
    if(supplierstatus.status==2){
    time_last_reloaded_ = this->GetTimePassedFromGameStart();
    }
    return time_last_reloaded_;
}  
const ros::Time Blackboard::GetTimeLeftForReloadZoneToOnline() {
    UpdateTime();
    return time_left_for_reload_zone_to_online_;
}  
//HP Info
int Blackboard::GetMyHealth() {
    my_health_ = robotstatus.remain_hp;
    return my_health_;
}
bool Blackboard::GetIsHitFastResponse() const{
    return is_hit_fast_response_;
}
bool Blackboard::GetHitConfirmedFastResponse() const{
    return hit_confirmed_fast_response_;
} 
void Blackboard::ConfirmHitFastResponse(){
    is_hit_fast_response_ = false;
    hit_confirmed_fast_response_ = true;
}
bool Blackboard::GetIsHitSmartResponse() const{
    return is_hit_smart_response_;
} 
bool Blackboard::GetHitConfirmedSmartResponse() const{
    return hit_confirmed_smart_response_;
} 
void Blackboard::ConfirmHitSmartResponse(){
    is_hit_smart_response_ = false;
    hit_confirmed_smart_response_ = true;
}
ArmorType Blackboard::GetWhichArmorHit() {
    if(robotdamage.damage_source==0){
        which_armor_hit_ = ArmorType::FRONT;
    }
    else if(robotdamage.damage_source==1){
        which_armor_hit_ = ArmorType::REAR;
    }
    else if(robotdamage.damage_source==2){
        which_armor_hit_ = ArmorType::LEFT;
    }
    else if(robotdamage.damage_source==3){
        which_armor_hit_ = ArmorType::RIGHT;
    }
    return which_armor_hit_;
}  
ros::Time Blackboard::GetTimeLastHit(){

    if(robotdamage.damage_type == 0){
            time_last_hit_ = this->GetTimePassedFromGameStart();
    }
    return time_last_hit_;
}  
//Defense Buff Info
bool Blackboard::GetHasBuff(){
        has_buff_=robotbonus.bonus;

    return has_buff_;
}
const ros::Time Blackboard::GetTimeBuffLeft() {
    UpdateTime();
    return time_buff_left_;
} 
//Ammunition Info
int Blackboard::GetAmmo() const{
    return ammo_;
}
bool Blackboard::GetIsReloading(){
    if(supplierstatus.status==2){
        is_reloading_=true;
    }
    else{
        is_reloading_=false;
    }
    return is_reloading_;
}

/*   Team Info Interface   */
geometry_msgs::PoseStamped Blackboard::GetAllyPose() const{
    return ally_pose_;
}
TeamType Blackboard::GetMyTeam(){
    if(robotstatus.id==3 || robotstatus.id==4){
        my_team_=TeamType::RED_TEAM;
    }
    else if(robotstatus.id==13 || robotstatus.id==14){
        my_team_=TeamType::BLUE_TEAM;
    }
    else{
        my_team_=TeamType::NONE;
    }
    return my_team_;
}
bool Blackboard::GetIsAllyAlive() const{
    return is_ally_alive_;
}

/*   Perception Info Interface   */



// check it for amcl pose
const geometry_msgs::PoseStamped Blackboard::GetMyPose(){
    UpdateMyPose();
    return my_pose_;
} 
geometry_msgs::PoseStamped Blackboard::GetAllyPoseFromVision() const{
    return ally_pose_from_vision_;
}
geometry_msgs::PoseStamped Blackboard::GetEnemyPose(PlayerType who) const{
  switch(who){
      case PlayerType::ENEMY_ONE:
        return enemy_pose_1_ghost_;
      case PlayerType::ENEMY_TWO:
        return enemy_pose_2_ghost_;
      default:
        throw std::invalid_argument( "wrong enemy type" );
        ROS_ERROR("blackboard GetEnemyPose error: wrong enemy type");
  }
}
geometry_msgs::PoseStamped Blackboard::GetEnemyEstim(PlayerType who) const{
  switch(who){
      case PlayerType::ENEMY_ONE:
        return enemy_pose_1_estim_;
      case PlayerType::ENEMY_TWO:
        return enemy_pose_2_estim_;
      default:
        throw std::invalid_argument( "wrong enemy type" );
        ROS_ERROR("blackboard GetEnemyEstim error: wrong enemy type");
  }    
} 
int Blackboard::GetNumberOfDetectedEnemies() const{
    return number_of_detected_enemies_;
}
bool Blackboard::GetIsEnemyDetected(PlayerType who) const{
  switch(who){
      case PlayerType::ENEMY_ONE:
        return is_enemy_1_detected_;
      case PlayerType::ENEMY_TWO:
        return is_enemy_2_detected_;
      case PlayerType::ENEMY_ANY:
        return is_enemy_detected_;        
      default:
        throw std::invalid_argument( "wrong enemy type" );
        ROS_ERROR("blackboard GetIsEnemyDetected error: wrong enemy type");
  } 
}
PlayerType Blackboard::GetWhichEnemyDetected() const {
    if (is_enemy_1_detected_ && is_enemy_2_detected_){
        return PlayerType::ENEMY_ANY;
    } else if(is_enemy_1_detected_){
        return PlayerType::ENEMY_ONE;
    } else if(is_enemy_2_detected_){
        return PlayerType::ENEMY_TWO;
    } else {
        return PlayerType::ALLY;
    }
}
bool Blackboard::GetIsNewEnemy() const{
    return is_new_enemy_;
}
bool Blackboard::IsNewEnemy(){
    if(is_new_enemy_){
        is_new_enemy_ = false;
        return true;
    } else {
        return false;
    }    
}

ros::Time Blackboard::GetTimeLastSeen(PlayerType who) const{
    switch(who){
        case PlayerType::ALLY:
          return time_ally_last_seen_;
        case PlayerType::ENEMY_ONE:
          return time_enemy_1_last_seen_;
        case PlayerType::ENEMY_TWO:
          return time_enemy_2_last_seen_;
        case PlayerType::ENEMY_ANY:
          return time_enemy_last_seen_;
        case PlayerType::UNKNOWN:
          return time_unknown_last_seen_;
        default:
          return ros::Time(0);
    }
}

/*   Behavior Info Interface   */
PlayerType Blackboard::GetLockedOnEnemy() const{
    return locked_on_enemy_;
}
bool Blackboard::GetIsNewLockonTarget() const{
    return is_new_lockon_target_;
}
bool Blackboard::IsNewLockonTarget(){
    if(is_new_lockon_target_){
        is_new_lockon_target_ = false;
        return true;
    } else {
        return false;
    }
}
bool Blackboard::GetIsNewGoal() const{
    return is_new_goal_;
}
bool Blackboard::IsNewGoal(){
    if(is_new_goal_){
        is_new_goal_ = false;
        return true;
    } else {
        return false;
    }
}
icra_roboin_msgs::GoalDescription Blackboard::GetGoal() const{
    return goal_;
}
const geometry_msgs::PoseStamped Blackboard::GetGoalPoseQuaternion(){
    TransformGoalPoseQuaternion();
    return goal_pose_quaternion_;    
}

BehaviorStyle Blackboard::GetBehaviorStyle() const{
    return behavior_style_;
}
BehaviorProcess Blackboard::GetBehaviorProcess() const{
    return behavior_process_;
}

/*   Smart Decision and Tactics Info Interface   */
PlayerType Blackboard::GetEnemyPriority() const{
    return enemy_priority_;
}






/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                             */
/*                                        Set Interface                                        */
/*                                                                                             */
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

void Blackboard::SetGoal(const icra_roboin_msgs::GoalDescription new_goal){
    goal_ = new_goal;
    is_new_goal_ = true;
}
void Blackboard::SetBehaviorStyle(const BehaviorStyle new_style){
    behavior_style_ = new_style;
}
void Blackboard::SetBehaviorProcess(const BehaviorProcess process){
    behavior_process_ = process;
}

void Blackboard::SetEnemyPriority(const PlayerType who){
    enemy_priority_ = who;
}

void Blackboard::SetLockedOnEnemy(const PlayerType who) {
    if(who != PlayerType::ALLY && who != PlayerType::ENEMY_ONE && who != PlayerType::ENEMY_TWO && who != PlayerType::ENEMY_ANY && who != PlayerType::UNKNOWN){
        throw std::invalid_argument( "wrong enemy type" );
        ROS_ERROR("blackboard set enenmy lockon error: wrong enemy type");
    }
    locked_on_enemy_ = who;
}

void Blackboard::AmmoMinusOne() {
    ammo_ --;
}

void Blackboard::SetIsReloading(const bool flag) {
    is_reloading_ = flag;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                             */
/*                                      Internal Members                                       */
/*                                                                                             */
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
void Blackboard::UpdateMyPose(){
    tf::Stamped<tf::Pose> my_tf_pose;
    my_tf_pose.setIdentity();
    my_tf_pose.frame_id_=namespace_ + "/" + "base_link";
    my_tf_pose.stamp_=ros::Time(0);   
    try {
        geometry_msgs::PoseStamped my_pose;
//        my_pose.pose = my_amcl_pose.pose.pose;
        tf::poseStampedTFToMsg(my_tf_pose,my_pose);
        tf_ptr_ -> transformPose(namespace_ + "/" + "map", my_pose, my_pose_);
    }
    catch (tf::LookupException& ex) {
        ROS_ERROR("blackboard UpdateMyPose error :%s", ex.what());
    }
}
void Blackboard::UpdateTime(){
//    int a = 180 - gamestatus.remaining_time;
    int a = time_last_buffed_.toSec() + 30;
    time_passed_from_game_start_ = ros::Time(180 - gamestatus.remaining_time);
    if(is_buff_zone_online_){
        time_left_for_buff_zone_to_online_ = ros::Time(0);
    } else {

        time_left_for_buff_zone_to_online_ = ros::Time(a+180-gamestatus.remaining_time); //buffzone opens every 1min
        if(time_left_for_buff_zone_to_online_ <= ros::Time(0)){
            time_left_for_buff_zone_to_online_ = ros::Time(0);
        }
    }
    time_buff_left_ = ros::Time(a+180-gamestatus.remaining_time);
    if(time_buff_left_ <= ros::Time(0)){
        time_buff_left_ = ros::Time(0);
    }
    if(supplierstatus.status!=0){
        time_left_for_reload_zone_to_online_ = ros::Time(0);
    }
    else if(supplierstatus.status == 0){
        if(time_last_reloaded_.toSec()<=60){
            time_left_for_reload_zone_to_online_ = ros::Time(60 - time_last_reloaded_.toSec());
        }
        else if(60<time_last_reloaded_.toSec()<120){
            time_left_for_reload_zone_to_online_ = ros::Time(120-time_last_reloaded_.toSec());
        }
    }
    }


void Blackboard::TransformGoalPoseQuaternion(){
    goal_pose_quaternion_.header = goal_.header;
    goal_pose_quaternion_.pose.position.x = goal_.x;
    goal_pose_quaternion_.pose.position.y = goal_.y;
    goal_pose_quaternion_.pose.position.z = 1;
    goal_pose_quaternion_.pose.orientation = tf::createQuaternionMsgFromYaw(goal_.yaw);
}



void Blackboard::EnemyAlert(){
    //TODO
}



/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/*                                                                                             */
/*                                          Callbacks                                          */
/*                                                                                             */
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
void Blackboard::GameStatusCB(const roborts_msgs::GameStatus::ConstPtr& msg){
    gamestatus.game_status = msg->game_status;
    gamestatus.remaining_time = msg->remaining_time;

/*
uint8 PRE_MATCH = 0
uint8 SETUP = 1
uint8 INIT = 2
uint8 FIVE_SEC_CD = 3
uint8 ROUND = 4
uint8 CALCULATION = 5
*/
}

void Blackboard::GameResultCB(const roborts_msgs::GameResult::ConstPtr& msg){
    gameresult.result = msg->result;
/*
uint8  DRAW=0
uint8  RED_WIN=1
uint8  BLUE_WIN=2
*/

}

void Blackboard::GameSurvivorCB(const roborts_msgs::GameSurvivor::ConstPtr& msg){
    gamesurvivor.red3 = msg->red3;
    gamesurvivor.red4 = msg->red4;
    gamesurvivor.blue3 = msg->blue3;
    gamesurvivor.blue4 = msg->blue4;
    /* bool */
}


void Blackboard::BonusStatusCB(const roborts_msgs::BonusStatus::ConstPtr& msg){
    bonusstatus.red_bonus = msg->red_bonus;
    bonusstatus.blue_bonus = msg->blue_bonus;
/*
uint8 UNOCCUPIED = 0
uint8 BEING_OCCUPIED= 1
uint8 OCCUPIED = 2
*/

}

void Blackboard::SupplierStatusCB(const roborts_msgs::SupplierStatus::ConstPtr& msg){
    supplierstatus.status = msg->status;
/*
uint8 CLOSE = 0
uint8 PREPARING = 1
uint8 SUPPLYING = 2
*/

}

void Blackboard::RobotStatusCB(const roborts_msgs::RobotStatus::ConstPtr& msg){
    robotstatus.id = msg->id;
    robotstatus.level = msg->level;
    robotstatus.remain_hp = msg->remain_hp;
    robotstatus.max_hp = msg->max_hp;
    robotstatus.heat_cooling_limit = msg->heat_cooling_limit;
    robotstatus.heat_cooling_rate = msg->heat_cooling_rate;
    robotstatus.gimbal_output = msg->gimbal_output;
    robotstatus.chassis_output = msg->chassis_output;
    robotstatus.shooter_output = msg->shooter_output;

/*
uint8 id
uint8 level
uint16 remain_hp
uint16 max_hp
uint16 heat_cooling_limit
uint16 heat_cooling_rate
bool gimbal_output
bool chassis_output
bool shooter_output
*/
}

void Blackboard::RobotHeatCB(const roborts_msgs::RobotHeat::ConstPtr& msg){
    robotheat.chassis_volt = msg->chassis_volt;
    robotheat.chassis_current = msg->chassis_current;
    robotheat.chassis_power = msg->chassis_power;
    robotheat.chassis_power_buffer = msg->chassis_power_buffer;
    robotheat.shooter_heat = msg->shooter_heat;
/*
uint16 chassis_volt
uint16 chassis_current
float64  chassis_power
uint16 chassis_power_buffer
uint16 shooter_heat
*/

}

void Blackboard::RobotBonusCB(const roborts_msgs::RobotBonus::ConstPtr& msg){
    robotbonus.bonus = msg->bonus;
/*
bool bonus
*/

}

void Blackboard::RobotDamageCB(const roborts_msgs::RobotDamage::ConstPtr& msg){
    robotdamage.damage_type = msg->damage_type;
    robotdamage.damage_source = msg->damage_source;
    is_hit_fast_response_=true;
    is_hit_smart_response_ = true;

/*
        uint8 ARMOR = 0
        uint8 OFFLINE = 1
        uint8 EXCEED_HEAT = 2
        uint8 EXCEED_POWER = 3

        uint8 FORWARD = 0
        uint8 BACKWARD = 1
        uint8 LEFT = 2
        uint8 RIGHT = 3
 */

}

void Blackboard::RobotShootCB(const roborts_msgs::RobotShoot::ConstPtr& msg){
    robotshoot.frequency = msg->frequency;
    robotshoot.speed = msg->speed;
/*
uint8 frequency
float64 speed
*/

}

void Blackboard::ProjectileSupplyCB(const roborts_msgs::ProjectileSupply::ConstPtr& msg){
    projectilsupply.supply = msg->supply;
/*
bool supply
*/

}

void Blackboard::MyPoseCB(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg){
    my_amcl_pose.pose.pose.position.x = msg->pose.pose.position.x;
    my_amcl_pose.pose.pose.position.y = msg->pose.pose.position.y;
    my_amcl_pose.pose.pose.orientation.w = msg->pose.pose.orientation.w;
    my_amcl_pose.pose.pose.position.z = msg->pose.pose.orientation.z;
}






void Blackboard::EnemyDetectionCB(const icra_roboin_msgs::YoloDetectionInfo::ConstPtr& yolo){
    //TODO change camera frame id from base_link to camera link
/*
    if (yolo->number_of_detection != 0){
        number_of_detection_ = yolo->number_of_detection;
        number_of_detected_enemies_ = 0;
        is_enemy_detected_ = false;
*/
        //////////////////////////////////////////////////////////
        /*                         Ally                         */
        //////////////////////////////////////////////////////////
/*
        if(yolo->enemy_detected[0] == 1){
            is_ally_detected_ = true;
            time_ally_last_seen_ = this->GetTimePassedFromGameStart();

            //tf transform code
            tf::Stamped<tf::Pose> ally_cam_tf, ally_global_tf;
            geometry_msgs::PoseStamped ally_cam_pose, ally_global_pose;
            ally_cam_pose.header.frame_id=namespace_ + "/" +"base_link";
            ally_cam_pose.header.stamp = yolo->stamp;
            ally_cam_pose.pose.position.z = (float(yolo->distance[0])+ROBOT_PERIMETER)/1000 * std::sin((float(yolo->angle_verti[0]) / 100)*3.141592/180);
            double flat_d =( (float(yolo->distance[0])+ROBOT_PERIMETER)/1000 * std::cos((float(yolo->angle_verti[0]) / 100)*3.141592/180) ); 
            ally_cam_pose.pose.position.x = flat_d * std::cos((-1*float(yolo->angle_hori[0]) / 100)*3.141592/180);
            ally_cam_pose.pose.position.y = flat_d * std::sin((-1*float(yolo->angle_hori[0]) / 100)*3.141592/180);

            tf::Quaternion quaternion = tf::createQuaternionFromYaw((-1*float(yolo->angle_hori[0]) / 100)*3.141592/180);
            ally_cam_pose.pose.orientation.w=quaternion.w();
            ally_cam_pose.pose.orientation.x=quaternion.x();
            ally_cam_pose.pose.orientation.y=quaternion.y();
            ally_cam_pose.pose.orientation.z=quaternion.z();

            tf::poseStampedMsgToTF(ally_cam_pose, ally_cam_tf);
            ally_cam_tf.stamp_ = ros::Time(0);
            try
            {
                tf_ptr_->transformPose(namespace_ + "/" +"map",ally_cam_tf,ally_global_tf);
                tf::poseStampedTFToMsg(ally_global_tf,ally_global_pose);
                ally_pose_from_vision_ = ally_global_pose;
            }
            catch (tf::TransformException& ex) {
                ROS_ERROR("blackboard enemy detection callback tf error");
            }
        } else {
            is_ally_detected_ = false;
        }
        
*/
        //////////////////////////////////////////////////////////
        /*                       Enemy 1                        */
        //////////////////////////////////////////////////////////
        if(yolo->enemy_detected[0] == 1){
            if(is_enemy_1_detected_ != true){
                is_new_enemy_ = true;
            }
            is_enemy_detected_ = true;
            is_enemy_1_detected_ = true;
            time_enemy_last_seen_ = this->GetTimePassedFromGameStart();
            time_enemy_1_last_seen_ = this->GetTimePassedFromGameStart();
            EnemyAlert();
            //ROS_INFO("Enemy 1 Detected!");
            number_of_detected_enemies_++;
            //tf transform code
            tf::Stamped<tf::Pose> enemy1_cam_tf, enemy1_global_tf;
            geometry_msgs::PoseStamped enemy1_cam_pose, enemy1_global_pose;
            enemy1_cam_pose.header.frame_id=namespace_ + "/" +"base_link";
            enemy1_cam_pose.header.stamp = yolo->stamp;
            enemy1_cam_pose.pose.position.z = (float(yolo->distance[0])+ROBOT_PERIMETER)/1000 * std::sin((float(yolo->angle_verti[0]) / 100)*3.141592/180);
            double flat_d = ( (float(yolo->distance[0])+ROBOT_PERIMETER)/1000 * std::cos((float(yolo->angle_verti[0]) / 100)*3.141592/180) ) ;   
            enemy1_cam_pose.pose.position.x = flat_d * std::cos((-1*float(yolo->angle_hori[0]) / 100)*3.141592/180);
            enemy1_cam_pose.pose.position.y = flat_d * std::sin((-1*float(yolo->angle_hori[0]) / 100)*3.141592/180);

            tf::Quaternion quaternion = tf::createQuaternionFromYaw((-1*float(yolo->angle_hori[0]) / 100)*3.141592/180);
            enemy1_cam_pose.pose.orientation.w=quaternion.w();
            enemy1_cam_pose.pose.orientation.x=quaternion.x();
            enemy1_cam_pose.pose.orientation.y=quaternion.y();
            enemy1_cam_pose.pose.orientation.z=quaternion.z();

            tf::poseStampedMsgToTF(enemy1_cam_pose, enemy1_cam_tf);
            enemy1_cam_tf.stamp_ = ros::Time(0);
            try
            {
                tf_ptr_->transformPose(namespace_ + "/" +"map",enemy1_cam_tf,enemy1_global_tf);
                tf::poseStampedTFToMsg(enemy1_global_tf,enemy1_global_pose);
                enemy_pose_1_ = enemy1_global_pose;
                enemy_pose_1_ghost_ = enemy_pose_1_;
            }
            catch (tf::TransformException& ex) {
                ROS_ERROR("blackboard enemy detection callback tf error");
            }
            
            if(GetEnemyPriority() == PlayerType::ENEMY_ONE | GetEnemyPriority() == PlayerType::ENEMY_ANY) {
                SetLockedOnEnemy(PlayerType::ENEMY_ONE);
            }
            
        } else {
            is_enemy_1_detected_ = false;
        }
        


        //////////////////////////////////////////////////////////
        /*                       Enemy 2                        */
        //////////////////////////////////////////////////////////
        if(yolo->enemy_detected[1]==2){
            if(is_enemy_2_detected_ != true){
                is_new_enemy_ = true;
            }
            is_enemy_detected_ = true;
            is_enemy_2_detected_ = true;
            time_enemy_last_seen_ = this->GetTimePassedFromGameStart();
            time_enemy_2_last_seen_ = this->GetTimePassedFromGameStart();
            EnemyAlert();
            //ROS_INFO("Enemy 2 Detected!");
            number_of_detected_enemies_++;
            //tf transform code
            tf::Stamped<tf::Pose> enemy2_cam_tf, enemy2_global_tf;
            geometry_msgs::PoseStamped enemy2_cam_pose, enemy2_global_pose;
            enemy2_cam_pose.header.frame_id=namespace_ + "/" +"base_link";
            enemy2_cam_pose.header.stamp = yolo->stamp;
            enemy2_cam_pose.pose.position.z = (float(yolo->distance[1])+ROBOT_PERIMETER)/1000 * std::sin((float(yolo->angle_verti[1]) / 100)*3.141592/180);
            double flat_d =( (float(yolo->distance[1])+ROBOT_PERIMETER)/1000 * std::cos((float(yolo->angle_verti[1]) / 100)*3.141592/180) );  
            enemy2_cam_pose.pose.position.x = flat_d * std::cos((-1*float(yolo->angle_hori[1]) / 100)*3.141592/180);
            enemy2_cam_pose.pose.position.y = flat_d * std::sin((-1*float(yolo->angle_hori[1]) / 100)*3.141592/180);

            tf::Quaternion quaternion = tf::createQuaternionFromYaw((-1*float(yolo->angle_hori[1]) / 100)*3.141592/180);
            enemy2_cam_pose.pose.orientation.w=quaternion.w();
            enemy2_cam_pose.pose.orientation.x=quaternion.x();
            enemy2_cam_pose.pose.orientation.y=quaternion.y();
            enemy2_cam_pose.pose.orientation.z=quaternion.z();

            tf::poseStampedMsgToTF(enemy2_cam_pose, enemy2_cam_tf);
            enemy2_cam_tf.stamp_ = ros::Time(0);
            try
            {
                tf_ptr_->transformPose(namespace_ + "/" +"map",enemy2_cam_tf,enemy2_global_tf);
                tf::poseStampedTFToMsg(enemy2_global_tf,enemy2_global_pose);
                enemy_pose_2_ = enemy2_global_pose;
                enemy_pose_2_ghost_ = enemy_pose_2_;
            }
            catch (tf::TransformException& ex) {
                ROS_ERROR("blackboard enemy detection callback tf error");
            }
            
            if(GetEnemyPriority() == PlayerType::ENEMY_TWO | GetEnemyPriority() == PlayerType::ENEMY_ANY) {
                SetLockedOnEnemy(PlayerType::ENEMY_TWO);
            }
            
        } else {
            is_enemy_2_detected_ = false;
        }
        
        

}















}
