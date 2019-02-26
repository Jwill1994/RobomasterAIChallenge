cmake_minimum_required(VERSION 2.8.3)
project(icra_roboin_control)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  tf
  actionlib
  actionlib_msgs
  move_base_msgs
  std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_package()

add_executable(navigation_control_node
  src/navigation_control.cpp
  )

target_link_libraries(navigation_control_node
  PRIVATE
  ${catkin_LIBRARIES}
  )

add_executable(goal_cancel_node
  src/goal_cancel.cpp
  )

target_link_libraries(goal_cancel_node
  PRIVATE
  ${catkin_LIBRARIES}
  )
