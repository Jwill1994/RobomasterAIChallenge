# cmake_minimum_required(VERSION <specify CMake version here>)
project(icra_roboin_vision)
cmake_minimum_required(VERSION 3.1)

# CMAKE_MINIMUM_REQUIRED ( VERSION 2.9 )
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_module)
set(-D CMAKE_BUILD_TYPE Release -D_GLIBCXX_USE_CXX11_ABI=0)


find_package(catkin REQUIRED COMPONENTS
    cv_bridge
    image_transport
    roscpp
    roborts_msgs
    icra_roboin_msgs
    sensor_msgs
    std_msgs
)
generate_messages(
  DEPENDENCIES
  sensor_msgs  std_msgs
)
catkin_package()

add_executable(roboin_vision_node vision_main.cpp)
include_directories(roboin_vision_node /home/nvidia/robomaster_extra/darknet/include)
include_directories(roboin_vision_node /usr/local/include)
target_link_libraries(roboin_vision_node PUBLIC
        /usr/local/lib/libopencv_world.so
        /usr/local/lib/librealsense2.so
        /usr/local/lib
        /home/nvidia/robomaster_extra/darknet/libdarknet.so
        ${catkin_LIBRARIES}
        )
target_include_directories(
        roboin_vision_node PUBLIC
        ${catkin_INCLUDE_DIRS}
)