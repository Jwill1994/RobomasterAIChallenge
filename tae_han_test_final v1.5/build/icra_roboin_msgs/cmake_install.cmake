# Install script for directory: /home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/nvidia/Desktop/tae_han_test_final/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/msg" TYPE FILE FILES
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg"
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/msg/SegmentObstacle.msg"
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/msg/CircleObstacle.msg"
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/msg/Obstacles.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/srv" TYPE FILE FILES
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv"
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/srv/XYOffset.srv"
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/srv/YawGain.srv"
    "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/srv/PitchGain.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/action" TYPE FILE FILES "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/action/YoloDetection.action")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/msg" TYPE FILE FILES
    "/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg"
    "/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg"
    "/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg"
    "/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg"
    "/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
    "/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg"
    "/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/cmake" TYPE FILE FILES "/home/nvidia/Desktop/tae_han_test_final/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/nvidia/Desktop/tae_han_test_final/devel/include/icra_roboin_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/nvidia/Desktop/tae_han_test_final/devel/share/roseus/ros/icra_roboin_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/nvidia/Desktop/tae_han_test_final/devel/share/common-lisp/ros/icra_roboin_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/nvidia/Desktop/tae_han_test_final/devel/share/gennodejs/ros/icra_roboin_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/nvidia/Desktop/tae_han_test_final/devel/lib/python2.7/dist-packages/icra_roboin_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/nvidia/Desktop/tae_han_test_final/devel/lib/python2.7/dist-packages/icra_roboin_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/nvidia/Desktop/tae_han_test_final/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/cmake" TYPE FILE FILES "/home/nvidia/Desktop/tae_han_test_final/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/cmake" TYPE FILE FILES
    "/home/nvidia/Desktop/tae_han_test_final/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgsConfig.cmake"
    "/home/nvidia/Desktop/tae_han_test_final/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs" TYPE FILE FILES "/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/package.xml")
endif()

