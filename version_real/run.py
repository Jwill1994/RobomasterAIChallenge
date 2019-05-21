#!/usr/bin/env python
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
from roborts_msgs.msg import BonusStatus, GameResult, GameStatus, GameSurvivor, ProjectileSupply, RobotBonus, RobotDamage, RobotHeat, RobotShoot, RobotStatus, SupplierStatus


import rospy
import roslib
from icra_roboin_decision_modules.roboin_behavior_service_module import SetBehaviorClient, SetGoalClient, GetInfoClient
#from geometry_msgs.msg import PoseWithCovarianceStamped

red_bonus = 1
blue_bonus = 1
result = 1
game_status = 1
remaining_time = 1
red3 = 1
red4 = 1
blue3 = 1
blue4 = 1
number = 1
bonus = 1
damage_type = 1
damage_source = 1
chassis_volt = 1
chassis_current = 1
chassis_power = 1
chassis_power_buffer = 1
shooter_heat = 1
frequency = 1
speed = 1
id_ = 1
level = 1
remain_hp = 1
max_hp = 1
heat_cooling_limit = 1
heat_cooling_rate = 1
gimbal_output = 1
chassis_output = 1
shooter_output = 1
status = 1


def buff_control(time):
    global team1_buff_count
    global team2_buff_count
    if 59 < time < 61:
        team1_buff_count = 1
        team2_buff_count = 1
    if 119 < time < 121:
        team1_buff_count = 1
        team2_buff_count = 1
        
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

def robot_setting_1(robot, time, team_pos, e1_pos, e2_pos, ez, mc, eo, wc, cz, my_bonus, enemy_bonus_effect):
    robot.set_stance(robot.health, robot.ammo,time, bonus)
    robot.init()        
    robot.enemy_zone_diff(robot.stance, e1_pos, 100, 2.3, ez, my_bonus, enemy_bonus_effect)
    robot.enemy_zone_diff(robot.stance, e2_pos, 100, 2.3, ez, my_bonus, enemy_bonus_effect)
    robot.move_cost(robot.stance, mc)
    robot.enemy_overlap(e1_pos, e2_pos, eo)
    robot.wall_cover(robot.stance, e1_pos, wc)
    robot.wall_cover(robot.stance, e2_pos, wc)
    robot.enemy_occupy(e1_pos)
    robot.enemy_occupy(e2_pos)
    robot.current_zone(10 , cz)
    
def robot_setting_2(robot, time,team_pos, team_buff_time, team_buff_count, team_has_buff, reload_count, bz, rz, my_bonus, enemy_bonus):
    robot.bonus_zone(team_pos, team_buff_time, team_buff_count, team_has_buff, bz, time, my_bonus, enemy_bonus)
    robot.reload_zone(robot.stance, team_pos, reload_count, robot.ammo, rz) 
    #out = robot.stuck_recovery(10, 300)
    
    robot.first_occupy(team_pos)
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
    
    if score + thres < value[0] and robot_move:
        behav = 1
        goal = np.array([goal_x,goal_y,0,0,0,0,0])   
        SetGoalClient(goal,robots[robot_number]) 
        SetBehaviorClient(behav,robots[robot_number])
    elif 3.8 < goal_x < 4.2 and 4.0 < goal_y < 4.4:
        behav = 8
        goal = np.array([4, 4.25, -math.pi/2,0,0,0,0])
        SetGoalClient(goal,robots[robot_number]) 
        SetBehaviorClient(behav,robots[robot_number])
    else:
        behav = 3
        goal = np.array([0,0,0,0,0,0,0])
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

def BonusStatus_callback(data):
   #uint8 UNOCCUPIED = 0
   #uint8 BEING_OCCUPIED= 1
   #uint8 OCCUPIED = 2
   global red_bonus
   red_bonus = data.red_bonus
   global blue_bonus
   blue_bonus = data.blue_bonus

def GameResult_callback(data):
   #uint8  DRAW=0
   #uint8  RED_WIN=1
   #uint8  BLUE_WIN=2
   global result
   result = data.result

def GameStatus_callback(data):
   #uint8 PRE_MATCH = 0
   #uint8 SETUP = 1
   #uint8 INIT = 2
   #uint8 FIVE_SEC_CD = 3
   #uint8 ROUND = 4
   #uint8 CALCULATION = 5
   global game_status
   game_status = data.game_status
   global remaining_time
   remaining_time = data.remaining_time

def GameSurvivor_callback(data):
   #bool
   global red3
   red3 = data.red3
   global red4
   red4 = data.red4
   global blue3
   blue3 = data.blue3
   global blue4
   blue4 = data.blue4

def ProjectileSupply_callback(data):
   #projectile number
   global number
   number = data.number

def RobotBonus_callback(data):
   #robot bonus
   global bonus
   bonus = data.bonus

def RobotDamage_callback(data):
   #robot damage
   #uint8 ARMOR = 0
   #uint8 OFFLINE = 1
   #uint8 EXCEED_HEAT = 2
   #uint8 EXCEED_POWER = 3
   global damage_type
   damage_type = data.damage_type
   #uint8 FORWARD = 0
   #uint8 BACKWARD = 1
   #uint8 LEFT = 2
   #uint8 RIGHT = 3
   global damage_source
   damage_source = data.damage_source

def RobotHeat_callback(data):
   #robot power and heat data
   global chassis_volt
   chassis_volt = data.chassis_volt
   global chassis_current
   chassis_current = data.chassis_current
   global chassis_power
   chassis_power = data.chassis_power
   global chassis_power_buffer
   chassis_power_buffer = data.chassis_power_buffer
   global shooter_heat
   shooter_heat = data.shooter_heat

def RobotShoot_callback(data):
   #robot shoot data
   global frequency
   frequency = data.frequency
   global speed
   speed = data.speed

def RobotStatus_callback(data):
   #robot status
   global id_
   id_ = data.id
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

def SupplierStatus_callback(data):
   #supplier status
   #uint8 CLOSE = 0
   #uint8 PREPARING = 1
   #uint8 SUPPLYING = 2
   global status
   status = data.status
                
if __name__ == '__main__':
    rospy.init_node('decision_test')
    
   
    # initial setting
    pos_view = False 
    robot_move = True
    update_time = 0.1
    
    
    
    robots = ['empty','', '', '', '']
    #team2 = 'blue'
    team1 = 'blue'
    team = 'blue'
    
    if id_ ==3 or id_==4:
        team = 'red'
    else:
        team = 'blue'

    robot1 = rules.rules([100,160], team1, 1)
    #robot2 = rules.rules([100,160], team1, 2)
    #robot3 = rules.rules([100,160], team2, 3)   
    #robot4 = rules.rules([100,160], team2, 4)

    r1_pos = [.5,0.5]
    r2_pos = [7.5, 0.5]
    r3_pos = [7.5,4.5]
    r4_pos = [0.5, 4.5]
    
    startTime = time.time()   
    now = now_time(startTime)
    
    # referee system initialize      
    team1_buff_count = 1
    team2_buff_count = 1
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
    eo = [5, 5, 5, 5, 5]
    wc = [20, 20, 20, 20, 20]
    bz = [150,150,150,150,150]
    rz = [100,100,100,100,100]
    cz = [50,50,50,50,25]    
    thres = 2
    r1_behav = 3

   

    rospy.Subscriber("/field_bonus_status", BonusStatus, BonusStatus_callback)
    rospy.Subscriber("/game_result", GameResult, GameResult_callback)
    rospy.Subscriber("/game_status", GameStatus, GameStatus_callback)
    rospy.Subscriber("/game_survivor", GameSurvivor, GameSurvivor_callback)
    rospy.Subscriber("/projectile_supply", ProjectileSupply, ProjectileSupply_callback)
    rospy.Subscriber("/robot_bonus", RobotBonus, RobotBonus_callback)
    rospy.Subscriber("/robot_damage", RobotDamage, RobotDamage_callback)
    rospy.Subscriber("/robot_heat", RobotHeat, RobotHeat_callback)
    rospy.Subscriber("/robot_shoot", RobotShoot, RobotShoot_callback)
    rospy.Subscriber("/robot_status", RobotStatus, RobotStatus_callback)
    rospy.Subscriber("/field_supplier_status", SupplierStatus, SupplierStatus_callback)
    
    my_bonus = 0
    enemy_bonus= 0
    enemy_bonus_effect = False
    my_bonus_effect = True
    enemy_bonus_time = -60
    


    #==========================================================
    
    while game_status <4 :
        print('Wait..')
        time.sleep(.2)
        print('Wait...')
        time.sleep(.2)
        

    while remaining_time >0:
        now = 180 - remaining_time
        buff_control(now)  
        reload_control(now)

        enemy_bonus_prev = enemy_bonus
        my_bonus_prev = my_bonus
        status_prev = status
        
        if team == 'blue':
            my_bonus = blue_bonus
            enemy_bonus = red_bonus
        else:
            my_bonus = red_bonus
            enemy_bonus = blue_bonus
            
        if enemy_bonus_prev == 1 and enemy_bonus == 2:
            enemy_bonus_time = now
            team1_buff_count = team1_buff_count - 1
            
        if my_bonus_prev==1 and my_bonus == 2:
            team1_buff_count = team1_buff_count -1
            team1_has_buff = True
            team1_buff_time_start = now
            team1_buff_time = 30.0 # live only th
            
        if status_prev == 1 and status == 2:
            r1_reload_count = r1_reload_count - 1
            robot1.ammo = robot1.ammo + 50
            
            
        if bonus:
            team1_has_buff = True
        else:
            team1_has_buff = False
            
        if enemy_bonus_time + 30 > now:
            enemy_bonus_effect = True
        else:
            enemy_bonus_effect = False
        
          
        r1_state = GetInfoClient(robots[1],1)
        r1_pos = [r1_state['my_pose']['pose']['position']['x'], r1_state['my_pose']['pose']['position']['y']] 
        r1_rotation = r1_state['my_pose']['pose']['orientation']['w']
        e1_pos = [r1_state['enemy_pose1']['pose']['position']['x'], r1_state['enemy_pose1']['pose']['position']['y']] 
        e2_pos = [r1_state['enemy_pose2']['pose']['position']['x'], r1_state['enemy_pose2']['pose']['position']['y']] 
        try:
            r2_pos = [r1_state['ally_pose']['pose']['position']['x'], r1_state['ally_pose']['pose']['position']['y']] 
        except:
            pass
        robot1.pos = r1_pos
        e1_detected = r1_state['is_enemy_1_detected']
        e2_detected = r1_state['is_enemy_2_detected']
        locked_on = r1_state['locked_on_enemy']
        robot1.pos = r1_pos
        
        robot1.health = remain_hp
        
        
        # game info ==========================================================================

                  
        getinfotime = round(now_time(startTime) - now,5)
        # ===================================================================================================================================
        #r1
        robot_setting_1(robot1, now, r2_pos, e1_pos, e1_pos, ez[1], mc[1], eo[1], wc[1], cz[1], bonus, enemy_bonus_effect)
        r1_report = robot_setting_2(robot1, now, r2_pos, team1_buff_time, team1_buff_count, team1_has_buff, r1_reload_count, bz[1], rz[1], my_bonus, enemy_bonus)                 
        r1_behav, r1_score, r1_value = robot_set_goal(robot1, robot_move)           
          
        #r3
        #robot3.enemy_random(20)
        #robot_setting_1(robot3, now, r4_pos, r1_pos, r2_pos, ez[3], mc[3], eo[3], wc[3], cz[3])        
        #r3_report = robot_setting_2(robot3, now, r4_pos, team2_buff_time, team2_buff_count, team2_has_buff, r3_reload_count, bz[3], rz[3])         
        #r3_behav, r3_score, r3_value = robot_set_goal(robot3, robot_move)           
       
        
        decisiontime = round(now_time(startTime) - now,5)          
        #================ referee system ========================================================================================                
        
        
            
        
        # bonus zone th.
        if robot1.isIn(r1_pos, r1_pos, team1, 'bonus'):
            if now - team1_bonus_active_counter > 5 and team1_buff_count > 0 and my_bonus == 2:
                team1_buff_count = team1_buff_count -1
                team1_has_buff = True
                team1_buff_time_start = now
                team1_buff_time = 30.0 # live only th
                team1_bonus_active_counter = now
            elif my_bonus == 0:
                behav = 1
                goal = np.array([robot1.pos[0]-1,robot1.pos[1],0,0,0,0,0])   
                SetGoalClient(goal,robots[1]) 
                SetBehaviorClient(behav,robots[1])                   
        else:
            team1_bonus_active_counter = now 
            
        if team1_buff_time < 1:
            team1_has_buff = False
              
        # reload zone th.
        if robot1.isIn(r1_pos, r1_pos, team1, 'reload'):
            if now - r1_reload_active_counter > 5 and r1_reload_count > 0 and r1_behav == 8 and (status == 2 or status == 1):                
                r1_reload_count = r1_reload_count - 1
                robot1.ammo = robot1.ammo + 50
                r1_reload_active_counter = now
            elif status == 0:
                behav = 1
                goal = np.array([robot1.pos[0]+1,robot1.pos[1]+1,0,0,0,0,0])   
                SetGoalClient(goal,robots[1]) 
                SetBehaviorClient(behav,robots[1])                
        else:
            r1_reload_active_counter = now
        
 
        
        refereetime = round(now_time(startTime) - now,5)
        #================ matplot view ========================================================================================            
                                
        plt.pause(0.5)
        #out = robot1.out()        
        #image = np.flip(out, axis=0)
        #plt.imshow(image, 'hot')
        print('=====================================================================')
        print('ammo', status)
        print('brb', bonus, red_bonus, blue_bonus)
        print(enemy_bonus, enemy_bonus_effect, enemy_bonus_time, my_bonus_effect)
        print('a')
        visualizetime = round(now_time(startTime) - now,5)  
        print('time:', now, 'buff_left:', team1_buff_time, team2_buff_time)        
        print('bonus', team1_buff_count, team2_buff_count, 'reload', r1_reload_count)
        print('r1_behav', r1_behav, 'pos : ', round(r1_score,2), np.round(robot1.pos,2), 'Max :' , round(r1_value[0],2), np.round(r1_value[1],2), 'ammo', robot1.ammo)
        print('ori', r1_rotation)
        print('enemy_detected', e1_detected, e2_detected)
        print('enemy_pose', e1_pos, e2_pos)
        print('team', r2_pos)

        if 45 < now < 47 or 105 < now < 108:
            robot1.ammo = 0
        
    behav = 1
    goal = np.array([robot1.pos[0],robot1.pos[1],0,0,0,0,0])   
    SetGoalClient(goal,robots[1]) 
    SetBehaviorClient(behav,robots[1])

      







