cmake_minimum_required(VERSION 2.8.3)
project(icra_roboin_msgs)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  nav_msgs
  geometry_msgs
  actionlib
  message_generation
)



add_service_files(
  DIRECTORY srv
  FILES
  BlackboardGeneralInfo.srv
  BehaviorStyleSet.srv
  BehaviorGoalSet.srv
  SetGoal_2.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
  nav_msgs
)


catkin_package(CATKIN_DEPENDS message_runtime)



