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


add_executable(behavior_selector_node
  src/behavior_selector.cpp
  )

target_link_libraries(behavior_selector_node
  PRIVATE
  ${catkin_LIBRARIES}
  )

add_executable(fake_enemy_pose_node
  src/fake_enemy_pose.cpp
  )

target_link_libraries(fake_enemy_pose_node
  PRIVATE
  ${catkin_LIBRARIES}
  )
