cmake_minimum_required(VERSION 2.8.3)
project(roborts_setting)

add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        icra_roboin_msgs
        )

catkin_package(
        DEPENDS
        roscpp
        icra_roboin_msgs
)

include_directories(
        ${catkin_INCLUDE_DIRS}
)


# include_directories(${catkin_INCLUDE_DIRS})
add_executable(set_pitch_gain_node set_pitch_gain.cpp)
target_link_libraries(set_pitch_gain_node
        ${catkin_LIBRARIES}
        )


add_executable(set_yaw_gain_node set_yaw_gain.cpp)
target_link_libraries(set_yaw_gain_node
        ${catkin_LIBRARIES})
#add_dependencies(set_pitch_gain_node roborts_msgs_generate_messages)
#add_dependencies(set_yaw_gain_node roborts_msgs_generate_messages)

add_executable(set_offset_node set_xy_offset.cpp)
target_link_libraries(set_offset_node
        ${catkin_LIBRARIES})



# ### INSTALL ###

# install(TARGETS look_to_point
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )
