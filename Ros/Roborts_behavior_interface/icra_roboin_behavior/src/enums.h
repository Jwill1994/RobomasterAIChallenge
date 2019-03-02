#ifndef ICRA_ROBOIN_BEHAVIOR_ENUMS_H
#define ICRA_ROBOIN_BEHAVIOR_ENUMS_H


namespace icra_roboin_behavior
{

enum class BehaviorState {
    RUNNING,
    SUCCESS,
    FAILURE,
    IDLE,
};

enum class BehaviorStyle {
    MOVE,
    FORCE_MOVE,
    ATTACK,
    CHASE,
    PATROL,
    ROTATE,
    RUNAWAY,
    RELOAD,
    BACKBOOT,
    MANUAL_SPEED,
    MANUAL_ACCEL,
    STAY,
};

enum class ChassisMode {
    NAVIGATION,
    SPEED,
    ACCEL,
    IDLE,
};
enum class GimbalMode {
    ANGLE,
    IDLE,
};


}

#endif