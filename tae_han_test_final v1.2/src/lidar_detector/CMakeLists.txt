cmake_minimum_required(VERSION 2.8.3)
project(lidar_detector)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  geometry_msgs
  sensor_msgs
  std_msgs
  roscpp
  icra_roboin_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
add_library(lidar_detector src/lidar_detector.cpp)
add_executable(lidar_detector_node src/lidar_detector.cpp)
target_link_libraries(lidar_detector_node ${catkin_LIBRARIES})

add_library(lidar_filter src/lidar_filter.cpp src/hcsr04.cpp src/jetsonGPIO.cpp)
add_executable(lidar_filter_node src/lidar_filter.cpp src/hcsr04.cpp src/jetsonGPIO.cpp)
target_link_libraries(lidar_filter_node ${catkin_LIBRARIES})



