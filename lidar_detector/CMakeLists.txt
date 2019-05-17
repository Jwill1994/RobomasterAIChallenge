cmake_minimum_required(VERSION 2.8.3)
project(lidar_detector)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  sensor_msgs
  roscpp
  roborts_msgs
)

catkin_package()

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(lidar_filter src/lidar_filter.cpp src/khc/hcsr04.cpp src/khc/jetsonGPIO.cpp)
add_executable(lidar_filter_node src/lidar_filter.cpp src/khc/hcsr04.cpp src/khc/jetsonGPIO.cpp)
target_link_libraries(lidar_filter_node ${catkin_LIBRARIES})

