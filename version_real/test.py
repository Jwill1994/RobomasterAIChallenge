import time
import rospy
import roslib
import numpy as np
from icra_roboin_decision_modules.roboin_behavior_service_module import SetBehaviorClient, SetGoalClient
from icra_roboin_decision_modules.roboin_behavior_service_module import GetInfoClient
from geometry_msgs.msg import PoseWithCovarianceStamped
from collections import deque
import itertools
'''
rospy.init_node('decision_test')
while True:           
    r1_state = GetInfoClient("robot_0",1)
    r1_pos = [r1_state ['my_pose']['pose']['position']['x'], r1_state ['my_pose']['pose']['position']['y']]        
    r2_state = GetInfoClient("robot_1",1)
    r2_pos = [r2_state ['my_pose']['pose']['position']['x'], r2_state ['my_pose']['pose']['position']['y']]      
    r3_state = GetInfoClient("robot_2",1)
    r3_pos = [r3_state ['my_pose']['pose']['position']['x'], r3_state ['my_pose']['pose']['position']['y']]      
    r4_state = GetInfoClient("robot_3",1)
    r4_pos = [r4_state ['my_pose']['pose']['position']['x'], r4_state ['my_pose']['pose']['position']['y']]   
    
    print(np.round(r1_pos,2), np.round(r2_pos,2),np.round(r3_pos,2),np.round(r4_pos,2))
    time.sleep(1)'''
    
pos_set = deque([], 16) 
for i in range(12):
    pos_set.appendleft(np.round([1,2], 2))
    target = list(itertools.islice(pos_set, 0, 10))
    if np.sum(np.var(target, axis=0)) == 0 and len(target)> 10-1:
        print( 'recovery', pos_set[0])