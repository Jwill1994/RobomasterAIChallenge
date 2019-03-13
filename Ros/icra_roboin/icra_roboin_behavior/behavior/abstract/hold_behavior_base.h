#ifndef ICRA_ROBOIN_BEHAVIOR_HOLD_BEHAVIOR_BASE_H
#define ICRA_ROBOIN_BEHAVIOR_HOLD_BEHAVIOR_BASE_H
#include "behavior_base.h"

namespace icra_roboin_behavior{

class HoldBehaviorBase : public BehaviorBase{
    public:
        HoldBehaviorBase(icra_roboin_behavior::ChassisExecutor*& chassis_executor,
                            icra_roboin_behavior::GimbalExecutor*& gimbal_executor,
                            icra_roboin_behavior::LockonModule*& lockon_module,
                            icra_roboin_behavior::Blackboard*& blackboard): 
                            BehaviorBase::BehaviorBase(chassis_executor,gimbal_executor
                                                        ,lockon_module,blackboard){}
        
        virtual ~HoldBehaviorBase() = default;
        
        virtual bool Run() override{
            RunHold();
            RunLockon();

            return true;
        }

        virtual void RunHold(){
            icra_roboin_msgs::LockonSpeedControl speed;
            icra_roboin_msgs::GoalDescription goal = blackboard_->GetGoal();
            speed.x = 0;
            speed.y = 0;
            lockon_yaw_ = goal.yaw;
            ROS_INFO("run %s behavior yaw:%f",behavior_class_name_.c_str(),lockon_yaw_);
            chassis_executor_->Execute(speed);
        }


        virtual void RunLockon() {
            if(blackboard_->GetLockedOnEnemy() == PlayerType::ENEMY_ONE | blackboard_->GetLockedOnEnemy() == PlayerType::ENEMY_TWO){
                if( (ros::Time::now() - (blackboard_->GetTimeLastSeen(blackboard_->GetLockedOnEnemy()))).toSec() > 3 ){
                    blackboard_->SetLockedOnEnemy(PlayerType::ALLY);
                    NoLockonTargetBehavior();
                } else{
                    lockon_module_->LockonInterface(LockonMode::TARGET_ENEMY_LOCKON,blackboard_->GetLockedOnEnemy());
                }
                
            } else if(blackboard_->GetLockedOnEnemy() == PlayerType::ALLY) {
                NoLockonTargetBehavior();
            }
        }

        virtual void NoLockonTargetBehavior() {
            if(blackboard_->GetIsEnemyDetected(PlayerType::ENEMY_ANY)){
                OnDetect();
            } else if(blackboard_->GetIsHitFastResponse()){
                OnHit();
            } else {
                NoEngage();
            }
        }
        virtual void OnHit() {
            switch(blackboard_->GetWhichArmorHit()){
                case ArmorType::LEFT:
                  lockon_module_->LockonInterface(LockonMode::ANGULAR_VEL,4);
                  break;
                case ArmorType::RIGHT:
                  lockon_module_->LockonInterface(LockonMode::ANGULAR_VEL,-4);
                  break;
                case ArmorType::REAR:
                  lockon_module_->LockonInterface(LockonMode::ANGULAR_VEL,4);
                  break;
            } 
        }

        virtual void OnDetect() {
            blackboard_->ConfirmHitFastResponse();
            if(blackboard_->GetEnemyPriority() == PlayerType::ENEMY_ANY){
                switch(blackboard_->GetWhichEnemyDetected()){
                    case PlayerType::ENEMY_ANY:
                        blackboard_->SetLockedOnEnemy(PlayerType::ENEMY_ONE);
                        lockon_module_->LockonInterface(LockonMode::TARGET_ENEMY_LOCKON,blackboard_->GetLockedOnEnemy());
                        break;
                    case PlayerType::ENEMY_ONE:
                        blackboard_->SetLockedOnEnemy(PlayerType::ENEMY_ONE);
                        lockon_module_->LockonInterface(LockonMode::TARGET_ENEMY_LOCKON,blackboard_->GetLockedOnEnemy());
                        break;
                    case PlayerType::ENEMY_TWO:
                        blackboard_->SetLockedOnEnemy(PlayerType::ENEMY_TWO);
                        lockon_module_->LockonInterface(LockonMode::TARGET_ENEMY_LOCKON,blackboard_->GetLockedOnEnemy());
                        break;
                }
            }
        }

        virtual void NoEngage() = 0;

        

        virtual bool Cancel() override{
            chassis_executor_->Cancel();
            ROS_INFO("%s : canceld",behavior_class_name_.c_str());
            return true;
        }

        virtual BehaviorProcess Update() override{
            return chassis_executor_->Update();
        }

        virtual BehaviorStyle GetBehaviorStyle() const override{
            return behavior_style_;
        }

    protected:
        double lockon_yaw_;















};


}
#endif