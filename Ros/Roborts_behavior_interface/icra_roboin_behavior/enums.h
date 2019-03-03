#ifndef ICRA_ROBOIN_BEHAVIOR_ENUMS_H
#define ICRA_ROBOIN_BEHAVIOR_ENUMS_H


namespace icra_roboin_behavior
{

enum class BehaviorState {
    RUNNING=1,
    SUCCESS,
    FAILURE,
    IDLE,
};

enum class BehaviorStyle {
    MOVE=1,
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
    STOP,
};

enum class ChassisMode {
    NAVIGATION=1,
    SPEED,
    ACCEL,
    IDLE,
};
enum class GimbalMode {
    ANGLE=1,
    IDLE,
};


}

#endif