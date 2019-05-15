# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "icra_roboin_msgs: 10 messages, 13 services")

set(MSG_I_FLAGS "-Iicra_roboin_msgs:/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg;-Iicra_roboin_msgs:/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg;-Istd_msgs:/opt/ros/kinetic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/kinetic/share/geometry_msgs/cmake/../msg;-Inav_msgs:/opt/ros/kinetic/share/nav_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(icra_roboin_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv" "std_msgs/Header"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv" "std_msgs/Header"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg" "actionlib_msgs/GoalID:std_msgs/Header:icra_roboin_msgs/YoloDetectionResult:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg" "actionlib_msgs/GoalID:std_msgs/Header:icra_roboin_msgs/YoloDetectionFeedback:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv" "icra_roboin_msgs/GoalDescription:geometry_msgs/PoseStamped:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv" "std_msgs/Header"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv" "std_msgs/Header"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv" "std_msgs/Header"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg" ""
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg" "actionlib_msgs/GoalID:std_msgs/Header:icra_roboin_msgs/YoloDetectionGoal"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv" "std_msgs/Header"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg" "std_msgs/Header:icra_roboin_msgs/YoloDetectionResult:icra_roboin_msgs/YoloDetectionGoal:icra_roboin_msgs/YoloDetectionActionGoal:icra_roboin_msgs/YoloDetectionActionResult:actionlib_msgs/GoalID:icra_roboin_msgs/YoloDetectionActionFeedback:icra_roboin_msgs/YoloDetectionFeedback:actionlib_msgs/GoalStatus"
)

get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv" NAME_WE)
add_custom_target(_icra_roboin_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "icra_roboin_msgs" "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv" "icra_roboin_msgs/GoalDescription:std_msgs/Header"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Services
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_cpp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Module File
_generate_module_cpp(icra_roboin_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(icra_roboin_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(icra_roboin_msgs_generate_messages icra_roboin_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_cpp _icra_roboin_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(icra_roboin_msgs_gencpp)
add_dependencies(icra_roboin_msgs_gencpp icra_roboin_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS icra_roboin_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Services
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_eus(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Module File
_generate_module_eus(icra_roboin_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(icra_roboin_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(icra_roboin_msgs_generate_messages icra_roboin_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_eus _icra_roboin_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(icra_roboin_msgs_geneus)
add_dependencies(icra_roboin_msgs_geneus icra_roboin_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS icra_roboin_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Services
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_lisp(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Module File
_generate_module_lisp(icra_roboin_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(icra_roboin_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(icra_roboin_msgs_generate_messages icra_roboin_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_lisp _icra_roboin_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(icra_roboin_msgs_genlisp)
add_dependencies(icra_roboin_msgs_genlisp icra_roboin_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS icra_roboin_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Services
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_nodejs(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Module File
_generate_module_nodejs(icra_roboin_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(icra_roboin_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(icra_roboin_msgs_generate_messages icra_roboin_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_nodejs _icra_roboin_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(icra_roboin_msgs_gennodejs)
add_dependencies(icra_roboin_msgs_gennodejs icra_roboin_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS icra_roboin_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_msg_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg;/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Services
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/PoseStamped.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/kinetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv"
  "${MSG_I_FLAGS}"
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg;/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/kinetic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)
_generate_srv_py(icra_roboin_msgs
  "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
)

### Generating Module File
_generate_module_py(icra_roboin_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(icra_roboin_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(icra_roboin_msgs_generate_messages icra_roboin_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv" NAME_WE)
add_dependencies(icra_roboin_msgs_generate_messages_py _icra_roboin_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(icra_roboin_msgs_genpy)
add_dependencies(icra_roboin_msgs_genpy icra_roboin_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS icra_roboin_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/icra_roboin_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(icra_roboin_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(icra_roboin_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(icra_roboin_msgs_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(icra_roboin_msgs_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/icra_roboin_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(icra_roboin_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(icra_roboin_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(icra_roboin_msgs_generate_messages_eus nav_msgs_generate_messages_eus)
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(icra_roboin_msgs_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/icra_roboin_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(icra_roboin_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(icra_roboin_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(icra_roboin_msgs_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(icra_roboin_msgs_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/icra_roboin_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(icra_roboin_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(icra_roboin_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(icra_roboin_msgs_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(icra_roboin_msgs_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/icra_roboin_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(icra_roboin_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(icra_roboin_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(icra_roboin_msgs_generate_messages_py nav_msgs_generate_messages_py)
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(icra_roboin_msgs_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
