# Install script for directory: /home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/kimtaehan/Desktop/lets_go_canada/install")
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

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/msg" TYPE FILE FILES
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/YoloDetectionInfo.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/GoalDescription.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg/LockonSpeedControl.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/srv" TYPE FILE FILES
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BlackboardGeneralInfo.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/BehaviorStyleSet.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetGoal_2.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/SetEnemyPriority.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeHit.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeGameState.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeShoot.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeTag.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeBuff.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereePenalty.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/RefereeReload.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/ConfirmHit.srv"
    "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/srv/AmmoConsume.srv"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/action" TYPE FILE FILES "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/action/YoloDetection.action")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/msg" TYPE FILE FILES
    "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionAction.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionGoal.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionResult.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionActionFeedback.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionGoal.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionResult.msg"
    "/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg/YoloDetectionFeedback.msg"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/cmake" TYPE FILE FILES "/home/kimtaehan/Desktop/lets_go_canada/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgs-msg-paths.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/kimtaehan/Desktop/lets_go_canada/devel/include/icra_roboin_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/kimtaehan/Desktop/lets_go_canada/devel/share/roseus/ros/icra_roboin_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/kimtaehan/Desktop/lets_go_canada/devel/share/common-lisp/ros/icra_roboin_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/kimtaehan/Desktop/lets_go_canada/devel/share/gennodejs/ros/icra_roboin_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  execute_process(COMMAND "/usr/bin/python" -m compileall "/home/kimtaehan/Desktop/lets_go_canada/devel/lib/python2.7/dist-packages/icra_roboin_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/kimtaehan/Desktop/lets_go_canada/devel/lib/python2.7/dist-packages/icra_roboin_msgs")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/kimtaehan/Desktop/lets_go_canada/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgs.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/cmake" TYPE FILE FILES "/home/kimtaehan/Desktop/lets_go_canada/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgs-msg-extras.cmake")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs/cmake" TYPE FILE FILES
    "/home/kimtaehan/Desktop/lets_go_canada/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgsConfig.cmake"
    "/home/kimtaehan/Desktop/lets_go_canada/build/icra_roboin_msgs/catkin_generated/installspace/icra_roboin_msgsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icra_roboin_msgs" TYPE FILE FILES "/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/package.xml")
endif()

