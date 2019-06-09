import rospy
import roslib
import numpy as np
import rosnode
import rospy_message_converter
from icra_roboin_msgs.srv import SetGoal_2,BehaviorStyleSet,BlackboardGeneralInfo,RefereeShoot,RefereeTag,ConfirmHit
from icra_roboin_msgs.msg import GoalDescription
from std_msgs.msg import Header

def SetGoalClient(goal_numpy,robot_name=""):
    goal = GoalDescription()
    goal.header.frame_id=robot_name + "/map"
    goal.header.stamp=rospy.Time.now()
    goal.x=goal_numpy[0]
    goal.y=goal_numpy[1]
    goal.yaw=goal_numpy[2]
    goal.xa=goal_numpy[3]
    goal.ya=goal_numpy[4]
    goal.yawa=goal_numpy[5]
    goal.etc=goal_numpy[6]
    rospy.wait_for_service(robot_name + "/behavior_node/goal_select_service")
    try:
        service = rospy.ServiceProxy(robot_name + "/behavior_node/goal_select_service",SetGoal_2)
        resp = service(goal)
        return resp
    except rospy.ServiceException, e:
        print "Set Goal Failed: %s"%e

def SetBehaviorClient(behavior,robot_name=""):
    rospy.wait_for_service(robot_name + "/behavior_node/behavior_select_service")
    try:
        service = rospy.ServiceProxy(robot_name + "/behavior_node/behavior_select_service",BehaviorStyleSet)
        resp = service(behavior)
        return resp
    except rospy.ServiceException, e:
        print "Set Behavior Failed: %s"%e

def GetInfoClient(robot_name="",confirm=1):
    rospy.wait_for_service(robot_name + "/behavior_node/blackboard/general_info_service")
    try:
        service = rospy.ServiceProxy(robot_name + "/behavior_node/blackboard/general_info_service",BlackboardGeneralInfo)
        resp = service(rospy.Time.now(),str(rosnode.get_node_names()),confirm)
        return rospy_message_converter.convert_ros_message_to_dictionary(resp)
    except rospy.ServiceException, e:
        print "Get Blackboard Info Failed: %s"%e


