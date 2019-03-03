cmake_minimum_required(VERSION 2.8.3)
project(icra_roboin_control)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  actionlib
  actionlib_msgs
  std_msgs
  geometry_msgs
  nav_msgs
  roborts_msgs
  roborts_common
  roborts_costmap
  roborts_decision
  icra_roboin_msgs

)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_package()





add_executable(new_behavior_test
  src/new_behavior_test.cpp
  )

target_link_libraries(new_behavior_test
  PRIVATE
  ${catkin_LIBRARIES}
  )
add_dependencies(new_behavior_test
  icra_roboin_msgs_generate_messages)
