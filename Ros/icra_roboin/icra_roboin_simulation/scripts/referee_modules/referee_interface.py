import rospy
import roslib
import numpy as np
import rosnode
import rospy_message_converter
from icra_roboin_msgs.srv import SetGoal_2,BehaviorStyleSet,BlackboardGeneralInfo,RefereeBuff,RefereeGameState,RefereeHit,RefereePenalty,RefereeShoot,RefereeTag
from icra_roboin_msgs.msg import GoalDescription
from std_msgs.msg import Header

def SetGoalClient(goal_numpy,robot_name=""):
    goal = GoalDescription()
    goal.header.frame_id=robot_name + "map"
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

def GetInfoClient(robot_name=""):
    rospy.wait_for_service(robot_name + "/behavior_node/blackboard/general_info_service")
    try:
        service = rospy.ServiceProxy(robot_name + "/behavior_node/blackboard/general_info_service",BlackboardGeneralInfo)
        resp = service(rospy.Time.now(),str(rosnode.get_node_names()))
        return rospy_message_converter.convert_ros_message_to_dictionary(resp)
    except rospy.ServiceException, e:
        print "Get Blackboard Info Failed: %s"%e


def RefereeBuffClient(buff_type=0, damage_multiplier = 0.5,robot_name=""):
    rospy.wait_for_service(robot_name + "/referee_buff_service")
    header = Header()
    header.frame_id = "map"
    header.stamp = rospy.Time.now()
    try:
        service = rospy.ServiceProxy(robot_name + "/referee_buff_service",RefereeBuff)
        resp = service(header,buff_type,damage_multiplier)
        return resp
    except rospy.ServiceException, e:
        print "Referee Buff Service Failed: %s"%e    

def RefereeGameStateClient(game_state,robot_name=""):
    rospy.wait_for_service(robot_name + "/referee_game_state_service")
    header = Header()
    header.frame_id = "map"
    header.stamp = rospy.Time.now()
    try:
        service = rospy.ServiceProxy(robot_name + "/referee_game_state_service",RefereeGameState)
        resp = service(header,game_state)
        return resp
    except rospy.ServiceException, e:
        print "Referee Game State Service Failed: %s"%e    

def RefereeHitClient(which_armor,your_hp,damage=50,robot_name=""):
    rospy.wait_for_service(robot_name + "/referee_hit_service")
    header = Header()
    header.frame_id = "map"
    header.stamp = rospy.Time.now()
    try:
        service = rospy.ServiceProxy(robot_name + "/referee_hit_service",RefereeHit)
        resp = service(header,damage,your_hp,which_armor)
        return resp
    except rospy.ServiceException, e:
        print "Referee Hit Service Failed: %s"%e 

def RefereePenaltyClient(penalty=0, damage = 1000,robot_name=""):
    rospy.wait_for_service(robot_name + "/referee_penalty_service")
    header = Header()
    header.frame_id = "map"
    header.stamp = rospy.Time.now()
    try:
        service = rospy.ServiceProxy(robot_name + "/referee_penalty_service",RefereePenalty)
        resp = service(header,penalty,damage)
        return resp
    except rospy.ServiceException, e:
        print "Referee Penalty Service Failed: %s"%e    
