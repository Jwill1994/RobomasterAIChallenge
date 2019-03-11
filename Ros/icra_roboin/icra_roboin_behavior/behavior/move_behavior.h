#ifndef ICRA_ROBOIN_BEHAVIOR_MOVE_BEHAVIOR_H
#define ICRA_ROBOIN_BEHAVIOR_MOVE_BEHAVIOR_H
#include "behavior_base.h"
#include <tf/tf.h>


namespace icra_roboin_behavior {

class MoveBehavior: public BehaviorBase{
    public:
        MoveBehavior(icra_roboin_behavior::ChassisExecutor*& chassis_executor,
                    icra_roboin_behavior::GimbalExecutor*& gimbal_executor,
                    icra_roboin_behavior::LockonModule*& lockon_module,
                    icra_roboin_behavior::Blackboard*& blackboard
                    ): BehaviorBase::BehaviorBase(chassis_executor,gimbal_executor,
                                                    lockon_module,blackboard)
        {
            behavior_style_ = icra_roboin_behavior::BehaviorStyle::MOVE;
        }
        virtual ~MoveBehavior() =default;

        bool Run() {
            if(blackboard_->IsNewGoalPose()){
                chassis_executor_->Execute(blackboard_->GetGoalPoseQuaternion());
            }
            if(blackboard_->GetLockedOnEnemy() != 0){
                
                geometry_msgs::PoseStamped mypose = blackboard_->GetMyPose();
                double yaw_diff = icra_roboin_behavior::tools::GetAngle( blackboard_->GetEnemyPose(blackboard_->GetLockedOnEnemy())
                                                                ,blackboard_->GetMyPose() );
                lockon_module_ -> SetTargetAngle(yaw_diff);

                /*                                                
                double w = icra_roboin_behavior::tools::Clip(yaw_diff,-3.0,3.0);
                //TODO: add PID here
                lockon_module_ -> SetTargetAngularVelocity(-1 * w);
                */
            }
            if(blackboard_->GetLockedOnEnemy() == 0){
                
                lockon_module_ -> SetTargetAngularVelocity(0); //TODO integrate with search behav
            }
            return true;
            //TODO: check whether goal is sent successfully
        }

        bool Cancel() {
            chassis_executor_->Cancel();
        }

        icra_roboin_behavior::BehaviorState Update() {
            return chassis_executor_->Update();
        }

        icra_roboin_behavior::BehaviorStyle GetBehaviorStyle() {return behavior_style_;}


         
        
};




}




#endif



