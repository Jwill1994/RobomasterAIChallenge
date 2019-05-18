#ifndef ICRA_ROBOIN_BEHAVIOR_SPECIFIC_ANGLE_BEHAVIOR_H
#define ICRA_ROBOIN_BEHAVIOR_SPECIFIC_ANGLE_BEHAVIOR_H
#include "abstract/move_behavior_base.h"


namespace icra_roboin_behavior {

class SpecificAngleBehavior: public MoveBehaviorBase{
    public:
        SpecificAngleBehavior(icra_roboin_behavior::ChassisExecutor*& chassis_executor,
                    icra_roboin_behavior::GimbalExecutor*& gimbal_executor,
                    icra_roboin_behavior::LockonModule*& lockon_module,
                    icra_roboin_behavior::Blackboard*& blackboard
                    ): MoveBehaviorBase::MoveBehaviorBase(chassis_executor,gimbal_executor,
                                                    lockon_module,blackboard)
        {
            behavior_style_ = icra_roboin_behavior::BehaviorStyle::SPECIFIC_ANGLE;
            behavior_class_name_ = "specific angle behavior";
        }
        ~SpecificAngleBehavior() = default;


        void RunLockon() override {
            lockon_module_->LockonInterface(LockonMode::GLOBAL_YAW, blackboard_->GetGoal().yaw);
        }


        void NoEngage() override{
            
        }






};




}




#endif
