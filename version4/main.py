# -*- coding: utf-8 -*-
"""
Created on Tue Apr 16 22:31:28 2019

@author: SHF_W
"""

import numpy as np
import matplotlib.pyplot as plt
import rules
import time

import rospy
import roslib
from icra_roboin_decision_modules.roboin_behavior_service_module import SetBehaviorClient, SetGoalClient
from icra_roboin_decision_modules.roboin_behavior_service_module import GetInfoClient
#from geometry_msgs.msg import PoseWithCovarianceStamped

def buff_control(time):
    global team1_buff_count
    global team2_buff_count
    if 59 < time < 61:
        team1_buff_count = 2
        team2_buff_count = 2
    if 119 < time < 121:
        team1_buff_count = 2
        team2_buff_count = 2
        
def reload_control(time):
    global r1_reload_count
    global r2_reload_count
    global r3_reload_count
    global r4_reload_count
    if 59 < time < 61 or 119 < time < 121:
        r1_reload_count = 1
        r2_reload_count = 1
        r3_reload_count = 1
        r4_reload_count = 1

def now_time(start):    
    return time.time() - start

def robot_setting_1(robot, time, my_pos, team_pos, e1_pos, e2_pos, ez, mc, eo, wc, cz):
    robot.init(my_pos)        
    robot.enemy_zone_diff(robot.stance, e1_pos, 100, 1.7, ez)
    robot.enemy_zone_diff(robot.stance, e2_pos, 100, 1.7, ez)
    robot.move_cost(robot.stance, my_pos, mc)
    robot.enemy_overlap(e1_pos, e2_pos, eo)
    robot.wall_cover(robot.stance, e1_pos, robot.pos, wc)
    robot.wall_cover(robot.stance, e2_pos, robot.pos, wc)
    robot.enemy_occupy(e1_pos)
    robot.enemy_occupy(e2_pos)
    robot.current_zone(my_pos, 10 , cz)
    
def robot_setting_2(robot, time, my_pos, team_pos, team_buff_time, team_buff_count, team_has_buff, reload_count, bz, rz):
    robot.bonus_zone(team_buff_time, team_buff_count, team_has_buff, bz)
    robot.reload_zone(robot.stance, reload_count, robot.ammo, rz) 
    robot.first_occupy(team_pos)
    robot.wall_limit()
        
def robot_set_goal(robot, my_pos, robot_number):
    score = robot.raw().getValue(my_pos)
    value = robot.raw().getPoint()
    
    if score + thres < value[0]:
        behav = 2
        goal = np.array([value[1][0],value[1][1],0,0,0,0,0])   
        SetGoalClient(goal,robots[robot_number]) 
        SetBehaviorClient(behav,robots[robot_number])
    else:
        behav = 1
        goal = np.array([0,0,0,0,0,0,0])
        SetGoalClient(r2_goal,robots[robot_number]) 
        SetBehaviorClient(r2_behav,robots[robot_number])
    
    return behav, score, value
            
                
if __name__ == '__main__':
    pos_view = False      
    
    rospy.init_node('decision_test')
    team2 = 'blue'
    team1 = 'red'
    robots = ['empty','robot_0', 'robot_1', 'robot_2', 'robot_3']
    robot1 = rules.rules([100,160], team1)
    robot2 = rules.rules([100,160], team1)
    robot3 = rules.rules([100,160], team2)   
    robot4 = rules.rules([100,160], team2)
    
    r1_stance = 'aggressive'
    r2_stance = 'aggressive'
    r3_stance = 'aggressive'
    r4_stance = 'aggressive'
    
    r1_pos = [.5,4.5]
    r2_pos = [7.5, 4.5]
    r3_pos = [7.5,.5]
    r4_pos = [0.5, 0.5]
        
    startTime = time.time()   
    now = now_time(startTime)
    
    team1_buff_count = 2
    team2_buff_count = 2 
    r1_reload_count = 0
    r2_reload_count = 0
    r3_reload_count = 0
    r4_reload_count = 0
    
    team1_bonus_active_counter = now
    team1_has_buff = False  
    team1_buff_time = 0       
   
    team2_bonus_active_counter = now
    team2_has_buff = False  
    team2_buff_time = 0    
    
    r1_reload_active_counter = now
    r2_reload_active_counter = now
    r3_reload_active_counter = now
    r4_reload_active_counter = now
        
    ez = 50
    mc = 35
    eo = 25
    wc = 20
    bz = 150
    rz = 100
    cz = 25
    
    thres = 20
    
    update_time = 0.25
    
    while now < 180:      
        now = now_time(startTime)
        buff_control(now)  
        reload_control(now)
        
        r1_state = GetInfoClient("robot_0",1)
        r1_pos = [r1_state['my_pose']['pose']['position']['x'], r1_state['my_pose']['pose']['position']['y']]        
        r2_state = GetInfoClient("robot_1",1)
        r2_pos = [r2_state['my_pose']['pose']['position']['x'], r2_state['my_pose']['pose']['position']['y']]      
        r3_state = GetInfoClient("robot_2",1)
        r3_pos = [r3_state['my_pose']['pose']['position']['x'], r3_state['my_pose']['pose']['position']['y']]      
        r4_state = GetInfoClient("robot_3",1)
        r4_pos = [r4_state['my_pose']['pose']['position']['x'], r4_state['my_pose']['pose']['position']['y']]                          
                  
        # ===================================================================================================================================
        # R1
        robot_setting_1(robot1, now, r1_pos, r2_pos, r3_pos, r4_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot1, now, r1_pos, r2_pos, team1_buff_time, team1_buff_count, team1_has_buff, r1_reload_count, bz, rz)         
        
        r1_behav, r1_score, r1_value = robot_set_goal(robot1, r1_pos, 1)
        
        pt = now_time(startTime) - now
        '''   
        r1_score =  robot1.raw().getValue(r1_pos)
        r1_value = robot1.raw().getPoint()                
         
        
        #move
        if r1_score+thres < r1_value[0] :
            r1_behav = 2            
            r1_goal = np.array([r1_value[1][0],r1_value[1][1],0,0,0,0,0])   
            SetGoalClient(r1_goal, "robot_0")   
            SetBehaviorClient(r1_behav,"robot_0")   
        else:
            r1_behav = 1
            r1_goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(r1_goal,"robot_0") 
            SetBehaviorClient(r1_behav,"robot_0")'''
                    
        robot_setting_1(robot2, now, r2_pos, r1_pos, r3_pos, r4_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot2, now, r2_pos, r1_pos, team1_buff_time, team1_buff_count, team1_has_buff, r2_reload_count, bz, rz)


        r2_score = robot2.raw().getValue(r2_pos)
        r2_value = robot2.raw().getPoint()
        
        #move
        if r2_score+thres < r2_value[0] :
            r2_behav = 2            
            r2_goal = np.array([r2_value[1][0],r2_value[1][1],0,0,0,0,0])   
            SetGoalClient(r2_goal, "robot_1")   
            SetBehaviorClient(r2_behav,"robot_1")   
        else:
            r2_behav = 1
            r2_goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(r2_goal,"robot_1") 
            SetBehaviorClient(r2_behav,"robot_1")     
        
        if robot1.isIn(r1_pos, r2_pos, team1, 'bonus'):
            if now - team1_bonus_active_counter > 5 and team1_buff_count > 0:
                team1_buff_count = team1_buff_count -1
                team1_has_buff = True
                team1_buff_time_start = now
                team1_buff_time = 30.0
                team1_bonus_active_counter = now
        else:
            team1_bonus_active_counter = now 

        if team1_has_buff and team1_buff_time > 0:
            team1_buff_time = 30.0-(now - team1_buff_time_start)
            
        if team1_buff_time < 1:
            team1_has_buff = False
              
        if robot1.isIn(r1_pos, r1_pos, team1, 'reload'):
            if now - r1_reload_active_counter > 5 and r1_reload_count > 0:
                r1_reload_count = r1_reload_count - 1
                robot1.ammo = robot1.ammo + 50
                r1_reload_active_counter = now
        else:
            r1_reload_active_counter = now
        
        if robot2.isIn(r2_pos, r2_pos, team1, 'reload'):
            if now - r2_reload_active_counter > 5 and r2_reload_count > 0:
                r2_reload_count = r2_reload_count - 1
                robot2.ammo = robot2.ammo + 50
                r2_reload_active_counter = now
        else:
            r2_reload_active_counter = now
        
        if pos_view:
            robot1.pos_view(r1_pos)
            robot1.pos_view(r2_pos)
            robot1.robot_diff(r2_pos)
            robot1.pos_view(r3_pos)
            robot1.pos_view(r4_pos)
            robot1.enemy_occupy(r3_pos)
            robot1.enemy_occupy(r4_pos)
        
         
        plt.pause(update_time) 
        
        #enemy
        robot3.enemy_random(20)
        robot_setting_1(robot3, now, r3_pos, r4_pos, r1_pos, r2_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot3, now, r3_pos, r4_pos, team2_buff_time, team2_buff_count, team2_has_buff, r3_reload_count, bz, rz) 
        
        r3_score =  robot3.raw().getValue(r3_pos)
        r3_value = robot3.raw().getPoint()  
        
        #move
        if r3_score+thres < r3_value[0] :
            r3_behav = 2            
            r3_goal = np.array([r3_value[1][0],r3_value[1][1],0,0,0,0,0])   
            SetGoalClient(r3_goal, "robot_2")   
            SetBehaviorClient(r3_behav,"robot_2")   
        else:
            r3_behav = 1
            r3_goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(r3_goal,"robot_2") 
            SetBehaviorClient(r3_behav,"robot_2")
            
        robot4.enemy_random(20)
        robot_setting_1(robot4, now, r4_pos, r3_pos, r1_pos, r2_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot4, now, r4_pos, r3_pos, team2_buff_time, team2_buff_count, team2_has_buff, r4_reload_count, bz, rz) 
        robot4.first_occupy(r3_pos) 
        
        r4_score =  robot4.raw().getValue(r4_pos)
        r4_value = robot4.raw().getPoint()
        
        #move
        if r4_score+thres < r4_value[0] :
            r4_behav = 2            
            r4_goal = np.array([r4_value[1][0],r4_value[1][1],0,0,0,0,0])   
            SetGoalClient(r4_goal, "robot_3")   
            SetBehaviorClient(r4_behav,"robot_3")   
        else:
            r4_behav = 1
            r4_goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(r4_goal,"robot_3") 
            SetBehaviorClient(r4_behav,"robot_3")
        
        
        if robot3.isIn(r3_pos, r4_pos, team2, 'bonus'):
            if now - team2_bonus_active_counter > 5 and team2_buff_count > 0:
                team2_buff_count = team2_buff_count -1
                team2_has_buff = True
                team2_buff_time_start = now
                team2_buff_time = 30.0
                team2_bonus_active_counter = now
        else:
            team2_bonus_active_counter = now 

        if team2_has_buff and team2_buff_time > 0:
            team2_buff_time = 30.0-(now - team2_buff_time_start)
            
        if team2_buff_time < 1:
            team2_has_buff = False
              
        if robot3.isIn(r3_pos, r3_pos, team2, 'reload'):
            if now - r3_reload_active_counter > 5 and r3_reload_count > 0:
                r3_reload_count = r3_reload_count -1
                robot3.ammo = robot3.ammo + 50
                r3_reload_active_counter = now
        else:
            r3_reload_active_counter = now
        
        if robot4.isIn(r4_pos, r4_pos, team2, 'reload'):
            if now - r4_reload_active_counter > 5 and r4_reload_count > 0:
                r4_reload_count = r4_reload_count -1
                robot4.ammo = robot4.ammo + 50
                r4_reload_active_counter = now
        else:
            r4_reload_active_counter = now        
        
        if pos_view:
            robot3.pos_view(r3_pos)
            robot3.pos_view(r1_pos)
            robot3.pos_view(r2_pos)
    
        #robot3.plot()
        plt.pause(update_time)
        
        out = np.vstack((robot3.out(),robot1.out()))
        image = np.flip(out, axis=0)
        plt.imshow(image, 'hot')
        print(robot1.pos_set)
        print(robot1.current_zone(r1_pos, 10 , cz))
        print('=====================================================================')
        print('time:', now, 'buff_left:', team1_buff_time, team2_buff_time)        
        print('bonus', team1_buff_count, team2_buff_count, 'reload', r1_reload_count)
        print('r1_behav', r1_behav, 'pos : ', round(r1_score,2), np.round(r1_pos,2), 'Max :' , round(r1_value[0],2), np.round(r1_value[1],2), 'ammo', robot1.ammo)
        print('r2_behav', r2_behav, 'pos : ', round(r2_score,2), np.round(r2_pos,2), 'Max :' , round(r2_value[0],2), np.round(r2_value[1],2), 'ammo', robot2.ammo)
        print('r3_behav', r3_behav, 'pos : ', round(r3_score,2), np.round(r3_pos,2), 'Max :' , round(r3_value[0],2), np.round(r3_value[1],2), 'ammo', robot3.ammo)
        print('r4_behav', r4_behav, 'pos : ', round(r4_score,2), np.round(r4_pos,2), 'Max :' , round(r4_value[0],2), np.round(r4_value[1],2), 'ammo', robot4.ammo)
        print('Process Time : ', pt , 'FPS:', int(10/pt)/10 )   
        
        if 45 < now < 47:
            robot1.ammo = 5
            robot2.ammo = 5
            robot3.ammo = 5
            robot4.ammo = 5