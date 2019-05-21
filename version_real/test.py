#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from roborts_msgs.msg import RobotStatus
id_=1
listened = [0]
loopstop = False
def callback(data):
      rospy.loginfo("I heard %s",data.data)

def RobotStatus_callback(data):
   #robot status
      global id_
      id_= data.id
      global level
      level = data.level
      global remain_hp
      remain_hp = data.remain_hp
      global max_hp
      max_hp = data.max_hp
      global heat_cooling_limit
      heat_cooling_limit = data.heat_cooling_limit
      global heat_cooling_rate
      heat_cooling_rate = data.heat_cooling_rate
      global gimbal_output
      gimbal_output = data.gimbal_output
      global chassis_output
      chassis_output = data.chassis_output
      global shooter_output
      shooter_output = data.shooter_output
      listened[0] = 1
      print("hi~")
      print(id_)




if __name__=='__main__':
      rospy.init_node('node_name')
      rospy.Subscriber("/robot_status", RobotStatus, RobotStatus_callback)
      while True :
            print(id_)
      


      
