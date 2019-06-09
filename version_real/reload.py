# -*- coding: utf-8 -*-
"""
Created on Tue Apr 16 22:31:28 2019

@author: SHF_W
"""

import numpy as np
import matplotlib.pyplot as plt
import rules
import time
import math

import rospy
import roslib
from icra_roboin_decision_modules.roboin_behavior_service_module import SetBehaviorClient, SetGoalClient, GetInfoClient
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

def robot_setting_1(robot, time, team_pos, e1_pos, e2_pos, ez, mc, eo, wc, cz):
    robot.set_stance(robot.health, robot.ammo, time)
    robot.init()        
    robot.enemy_zone_diff(robot.stance, e1_pos, 100, 1.7, ez)
    robot.enemy_zone_diff(robot.stance, e2_pos, 100, 1.7, ez)
    robot.move_cost(robot.stance, mc)
    robot.enemy_overlap(e1_pos, e2_pos, eo)
    robot.wall_cover(robot.stance, e1_pos, wc)
    robot.wall_cover(robot.stance, e2_pos, wc)
    robot.enemy_occupy(e1_pos)
    robot.enemy_occupy(e2_pos)
    robot.current_zone(10 , cz)
    
def robot_setting_2(robot, time,team_pos, team_buff_time, team_buff_count, team_has_buff, reload_count, bz, rz):
    robot.bonus_zone(team_pos, team_buff_time, team_buff_count, team_has_buff, bz)
    robot.reload_zone(robot.stance, team_pos, reload_count, robot.ammo, rz) 
    #out = robot.stuck_recovery(10, 300)
    
    #robot.first_occupy(team_pos)
    robot.wall_limit()
    #if out == 1:
    out = 'Good'
    
    return out
        
def robot_set_goal(robot, robot_move):    
    score = robot.raw().getValue(robot.pos)
    value = robot.raw().getPoint()
    robot_number = robot.robot_num

    goal_x = value[1][0]
    goal_y = value[1][1]
    
    behav = 8
    goal = np.array([4, 0.6, math.pi/2,0,0,0,0])
    SetGoalClient(goal,robots[robot_number]) 
    SetBehaviorClient(behav,robots[robot_number])
 
    
    return behav, score, value
            
def decision_order(_robot1, _robot2):
    team = _robot1.team
    if team == 'blue':
        p = [1.700,3.250]
    else:
        p = [6.300,1.750]

    r1 = _robot1.raw().p2pRelation(_robot1.pos, p)[0]
    r2 = _robot2.raw().p2pRelation(_robot2.pos, p)[0]
    if r1 > r2:        
        return False
    else:
        return True       
                
if __name__ == '__main__':
    # initial setting
    pos_view = False 
    robot_move = True
    update_time = 0.1
    rospy.init_node('decision_test')
    robots = ['empty','', '', '', '']
    #team2 = 'blue'
    team1 = 'blue'
    robot1 = rules.rules([100,160], team1, 1)
    #robot2 = rules.rules([100,160], team1, 2)
    #robot3 = rules.rules([100,160], team2, 3)   
    #robot4 = rules.rules([100,160], team2, 4)

    r1_pos = [.5,0.5]
    r2_pos = [7.5, 4.5]
    r3_pos = [7.5,.5]
    r4_pos = [0.5, 0.5]
    
    startTime = time.time()   
    now = now_time(startTime)
    
    # referee system initialize      
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
        
    # parameter
    ez = [50, 50, 50, 50, 50]
    mc = [20, 20, 20, 20, 20]
    eo = [25, 25, 25, 25, 25]
    wc = [20, 20, 20, 20, 20]
    bz = [150,150,150,150,150]
    rz = [100,100,100,100,100]
    cz = [50,50,50,50,25]    
    thres = 2
    
    print(robot1.team)

    
    while now < 180:      
        now = now_time(startTime)
        buff_control(now)  
        reload_control(now)
        
        r1_state = GetInfoClient(robots[1],1)
        r1_pos = [r1_state['my_pose']['pose']['position']['x'], r1_state['my_pose']['pose']['position']['y']] 
        r1_rotation = r1_state['my_pose']['pose']['orientation']['w']
	e1_pos = [r1_state['enemy_pose1']['pose']['position']['x'], r1_state['enemy_pose1']['pose']['position']['y']] 
        e2_pos = [r1_state['enemy_pose2']['pose']['position']['x'], r1_state['enemy_pose2']['pose']['position']['y']] 
        robot1.pos = r1_pos
        e1_detected = r1_state['is_enemy_1_detected']
        e2_detected = r1_state['is_enemy_2_detected']
        locked_on = r1_state['locked_on_enemy']
        



        #r3_state = GetInfoClient(robots[3],1)
        #r3_pos = [r3_state['my_pose']['pose']['position']['x'], r3_state['my_pose']['pose']['position']['y']]      
        
        robot1.pos = r1_pos

        #robot3.pos = [8-r3_pos[0], 5-r3_pos[1]]
           
                  
        getinfotime = round(now_time(startTime) - now,5)
        # ===================================================================================================================================
        #r1
        robot_setting_1(robot1, now, r2_pos, e1_pos, e1_pos, ez[1], mc[1], eo[1], wc[1], cz[1])
        r1_report = robot_setting_2(robot1, now, r2_pos, team1_buff_time, team1_buff_count, team1_has_buff, r1_reload_count, bz[1], rz[1])                 
        r1_behav, r1_score, r1_value = robot_set_goal(robot1, robot_move)           
          
        #r3
        #robot3.enemy_random(20)
        #robot_setting_1(robot3, now, r4_pos, r1_pos, r2_pos, ez[3], mc[3], eo[3], wc[3], cz[3])        
        #r3_report = robot_setting_2(robot3, now, r4_pos, team2_buff_time, team2_buff_count, team2_has_buff, r3_reload_count, bz[3], rz[3])         
        #r3_behav, r3_score, r3_value = robot_set_goal(robot3, robot_move)           
       
        
        decisiontime = round(now_time(startTime) - now,5)          
        #================ referee system ========================================================================================                
        
        if robot1.isIn(r1_pos, r1_pos, team1, 'bonus'):
            if now - team1_bonus_active_counter > 5 and team1_buff_count > 0:
                team1_buff_count = team1_buff_count -1
                team1_has_buff = True
                team1_buff_time_start = now
                team1_buff_time = 30.0
                team1_bonus_active_counter = now
        else:
            team1_bonus_active_counter = now 

        if team1_has_buff and team1_buff_time > -1:
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
        
 
        
        refereetime = round(now_time(startTime) - now,5)
        #================ matplot view ========================================================================================            
        if pos_view:
            robot1.pos_view(r1_pos)
            robot1.pos_view(r2_pos)
            robot1.pos_view(r3_pos)
            robot1.pos_view(r4_pos)
            robot1.robot_diff(r2_pos)
            robot1.enemy_occupy(r3_pos)
            robot1.enemy_occupy(r4_pos)
            25
            robot3.pos_view(r1_pos)
            robot3.pos_view(r2_pos)
            robot3.pos_view(r3_pos)
            robot3.pos_view(r4_pos)
            robot3.robot_diff(r4_pos)
            robot3.enemy_occupy(r1_pos)
            robot3.enemy_occupy(r2_pos)
                        
        #plt.pause(update_time)
        
        
        
        #out = robot1.out()
        
        #image = np.flip(out, axis=0)
        #plt.imshow(image, 'hot')
        
        visualizetime = round(now_time(startTime) - now,5) 
        print('=====================================================================')
        print('time:', now, 'buff_left:', team1_buff_time, team2_buff_time)        
        print('bonus', team1_buff_count, team2_buff_count, 'reload', r1_reload_count)
        print('r1_behav', r1_behav, 'pos : ', round(r1_score,2), np.round(robot1.pos,2), 'Max :' , round(r1_value[0],2), np.round(r1_value[1],2), 'ammo', robot1.ammo)
        print('ori', r1_rotation)
        print('enemy_detected', e1_detected, e2_detected)
        print('enemy_pose', e1_pos, e2_pos)
        print('lockedon', locked_on)

 
        
        # force reload - no attack 
        if 45 < now < 47:
            robot1.ammo = 5



{'current_behavior_style': 4, 
'current_behavior_process': 1, 
'my_pose': 
{'header': 
{'stamp': 
{'secs': 1558029607, 'nsecs': 861191283}, 
'frame_id': '/map', 'seq': 0}, 
'pose': 
{'position': 
{'y': 3.196442656626007, 'x': 1.7302472321562106, 'z': 0.0}, 
'orientation': 
{'y': 0.0, 'x': 0.0, 'z': -0.18683142862779048, 'w': 0.982391987587897}
}
}, 
'last_hit_time': 
{'secs': 180, 'nsecs': 0}, 
'goal': 
{'etc': 0.0, 'ya': 0.0, 'yaw': 0.0, 'xa': 0.0, 
'header': 
{'stamp': 
{'secs': 1558029606, 'nsecs': 449084997}, 'frame_id': '/map', 'seq': 0}, 'y': 0.0, 'x': 0.0, 'yawa': 0.0}, 'stamp': {'secs': 1558029607, 'nsecs': 868204934}, 
'which_armor_hit': 0, 
'reload_zone_cooltime': {'secs': 60, 'nsecs': 0}, 
'my_health': 2000, 
'how_many_enemies_detected': 0, 
'has_buff': False, 
'enemy_priority': 3, 
'game_state': 1, 
'game_start_time': {'secs': 0, 'nsecs': 0}, 
'is_enemy_1_detected': False, 
'buff_left': {'secs': 210, 'nsecs': 0}, 
'enemy_pose2': {'header': {'stamp': {'secs': 0, 'nsecs': 0}, 'frame_id': '', 'seq': 0}, 
'pose': {'position': {'y': 0.0, 'x': 0.0, 'z': 0.0}, 'orientation': {'y': 0.0, 'x': 0.0, 'z': 0.0, 'w': 0.0}}}, 
'enemy_pose1': {'header': {'stamp': {'secs': 0, 'nsecs': 0}, 'frame_id': '', 'seq': 0}, 'pose': {'position': {'y': 0.0, 'x': 0.0, 'z': 0.0}, 'orientation': {'y': 0.0, 'x': 0.0, 'z': 0.0, 'w': 0.0}}}, 
'is_hit': False, 
'is_enemy_2_detected': False, 
'buff_zone_cooltime': {'secs': 0, 'nsecs': 0}, 
'locked_on_enemy': 0, 
'time_passed_from_start': {'secs': 180, 'nsecs': 0}, 
'ammo': 50}

