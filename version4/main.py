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
from geometry_msgs.msg import PoseWithCovarianceStamped

rospy.init_node('decision_test')

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
    robot.wall_cover(robot.stance, e1_pos, robot.pos, wc)
    robot.wall_cover(robot.stance, e2_pos, robot.pos, wc)
    robot.enemy_occupy(e1_pos)
    robot.enemy_occupy(e2_pos)
    robot.current_zone(my_pos, 10 , cz)
    
def robot_setting_2(robot, time, my_pos, team_pos, team_buff_time, team_buff_count, team_has_buff, reload_count, bz, rz):
    robot.bonus_zone(team_buff_time, team_buff_count, team_has_buff, bz)
    robot.reload_zone(robot.stance, time, reload_count, robot.ammo, rz) 
    robot.first_occupy(team_pos)
    robot.wall_limit() 

attack_hold_value = 31
attack_hold_degre = 10 # 초당 value 10씩 감소, 최대 3번, 한 자리에서 계속 공격하지 않게 하는 값. value가 
occupy_hold_value = 200

if __name__ == '__main__':
    team1 = 'blue'
    team2 = 'red'
    robot1 = rules.rules([100,160], team1)
    robot2 = rules.rules([100,160], team1)
    robot3 = rules.rules([100,160], team2)   
    robot4 = rules.rules([100,160], team2)
    #r1_stance = 'passive'
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
    r1_ammo = 40
    r2_ammo = 40
    r3_ammo = 40
    r4_ammo = 40
    
    ez = 50
    mc = 20
    eo = 25
    wc = 20
    bz = 150
    rz = 10
    cz = 5
    
    
    while now < 90:      
        now = now_time(startTime)
        buff_control(now)  
        reload_control(now)
        
        r1_state = GetInfoClient("robot_0",1)
        r1_pos = [r1_state ['my_pose']['pose']['position']['x'], r1_state ['my_pose']['pose']['position']['y']]        
        r2_state = GetInfoClient("robot_1",1)
        r2_pos = [r2_state ['my_pose']['pose']['position']['x'], r2_state ['my_pose']['pose']['position']['y']]      
        r3_state = GetInfoClient("robot_2",1)
        r3_pos = [r3_state ['my_pose']['pose']['position']['x'], r3_state ['my_pose']['pose']['position']['y']]      
        r4_state = GetInfoClient("robot_3",1)
        r4_pos = [r4_state ['my_pose']['pose']['position']['x'], r4_state ['my_pose']['pose']['position']['y']]      
                        
        robot_setting_1(robot1, now, r1_pos, r2_pos, r3_pos, r4_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot1, now, r1_pos, r2_pos, team1_buff_time, team1_buff_count, team1_has_buff, r1_reload_count, bz, rz)          
        
                
        r1_score =  robot1.raw().getValue(r1_pos)
        r1_goal = robot1.raw().getPoint()                
        pt = now_time(startTime) - now 
        
        '''move'''
        if r1_score+5 < r1_goal[0] :
            behav = 2            
            goal = np.array([r1_goal[1][0],r1_goal[1][1],0,0,0,0,0])   
            SetGoalClient(goal, "robot_0")   
            SetBehaviorClient(behav,"robot_0")   
        else:
            behav = 1
            goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(goal,"robot_0") 
            SetBehaviorClient(behav,"robot_0")
                    
        robot_setting_1(robot2, now, r2_pos, r1_pos, r3_pos, r4_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot2, now, r2_pos, r1_pos, team1_buff_time, team1_buff_count, team1_has_buff, r2_reload_count, bz, rz)  
                          
                        
        r2_score =  robot2.raw().getValue(r2_pos)
        r2_goal = robot2.raw().getPoint()
        
        '''move'''
        if r2_score+5 < r2_goal[0] :
            behav = 2            
            goal = np.array([r2_goal[1][0],r2_goal[1][1],0,0,0,0,0])   
            SetGoalClient(goal, "robot_1")   
            SetBehaviorClient(behav,"robot_1")   
        else:
            behav = 1
            goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(goal,"robot_1") 
            SetBehaviorClient(behav,"robot_1")
            
            
            
        
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
                r1_ammo = r1_ammo + 50
                r1_reload_active_counter = now
        else:
            r1_reload_active_counter = now
        
        if robot2.isIn(r2_pos, r2_pos, team1, 'reload'):
            if now - r2_reload_active_counter > 5 and r2_reload_count > 0:
                r2_reload_count = r2_reload_count - 1
                r2_ammo = r2_ammo + 50
                r2_reload_active_counter = now
        else:
            r2_reload_active_counter = now
        
        robot1.pos_view(r1_pos) # 위치 확인용
        robot1.pos_view(r2_pos)
        robot1.robot_diff(r2_pos)
        robot1.pos_view(r3_pos)
        robot1.pos_view(r4_pos)
        robot1.enemy_occupy(r3_pos)
        robot1.enemy_occupy(r4_pos)
        
        robot1.plot()  
        plt.pause(0.5) 
        
        ''' enemy'''
        robot3.enemy_random(20)
        robot_setting_1(robot3, now, r3_pos, r4_pos, r1_pos, r2_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot3, now, r3_pos, r4_pos, team2_buff_time, team2_buff_count, team2_has_buff, r3_reload_count, bz, rz) 
        
        r3_score =  robot3.raw().getValue(r3_pos)
        r3_goal = robot3.raw().getPoint()  
        
        '''move'''
        if r3_score+5 < r3_goal[0] :
            behav = 2            
            goal = np.array([r3_goal[1][0],r3_goal[1][1],0,0,0,0,0])   
            SetGoalClient(goal, "robot_2")   
            SetBehaviorClient(behav,"robot_2")   
        else:
            behav = 1
            goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(goal,"robot_2") 
            SetBehaviorClient(behav,"robot_2")
            
        robot4.enemy_random(20)
        robot_setting_1(robot4, now, r4_pos, r3_pos, r1_pos, r2_pos, ez, mc, eo, wc, cz)
        robot_setting_2(robot4, now, r4_pos, r3_pos, team2_buff_time, team2_buff_count, team2_has_buff, r4_reload_count, bz, rz) 
        robot4.first_occupy(r3_pos) 
        
        r4_score =  robot4.raw().getValue(r4_pos)
        r4_goal = robot4.raw().getPoint()
        
        '''move'''
        if r4_score+5 < r4_goal[0] :
            behav = 2            
            goal = np.array([r4_goal[1][0],r4_goal[1][1],0,0,0,0,0])   
            SetGoalClient(goal, "robot_3")   
            SetBehaviorClient(behav,"robot_3")   
        else:
            behav = 1
            goal = np.array([5,3,1,0,0,0,0])
            SetGoalClient(goal,"robot_3") 
            SetBehaviorClient(behav,"robot_3")
        
        
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
                r3_ammo = r3_ammo + 50
                r3_reload_active_counter = now
        else:
            r3_reload_active_counter = now
        
        if robot4.isIn(r4_pos, r4_pos, team2, 'reload'):
            if now - r4_reload_active_counter > 5 and r4_reload_count > 0:
                r4_reload_count = r4_reload_count -1
                r4_ammo = r4_ammo + 50
                r4_reload_active_counter = now
        else:
            r4_reload_active_counter = now        
        
        #robot1.first_occupy(r4_pos)
        #robot1.enemy_occupy(r4_pos)
        robot3.pos_view(r3_pos)
        robot3.pos_view(r1_pos)
        robot3.pos_view(r2_pos)
    
        #robot3.plot()
        plt.pause(0.5)
        
        robot3.plot() 
        print('=====================================================================')
        print('time:', now, 'buff_left:', team1_buff_time, team2_buff_time)        
        print('bonus', team1_buff_count, team2_buff_count, 'reload', r1_reload_count)
        print('r1_pos : ', round(r1_score,2), np.round(r1_pos,2), 'Max :' , round(r1_goal[0],2), np.round(r1_goal[1],2))
        print('r2_pos : ', round(r2_score,2), np.round(r2_pos,2), 'Max :' , round(r2_goal[0],2), np.round(r2_goal[1],2))
        print('r3_pos : ', round(r3_score,2), np.round(r3_pos,2), 'Max :' , np.round(r3_goal[0],2), np.round(r3_goal[1],2))
        print('r4_pos : ', round(r4_score,2), np.round(r4_pos,2), 'Max :' , np.round(r4_goal[0],2), np.round(r4_goal[1],2))
        print('Process Time : ', pt , 'FPS:', int(10/pt)/10 )   