# -*- coding: utf-8 -*-
"""
Created on Tue Apr 16 22:31:28 2019

@author: SHF_W
"""

import numpy as np
import matplotlib.pyplot as plt
import rules
import time
from referee import *

import rospy
import roslib
from icra_roboin_decision_modules.roboin_behavior_service_module import SetBehaviorClient, SetGoalClient
from icra_roboin_decision_modules.roboin_behavior_service_module import GetInfoClient, RefereeGameStateClient
from roborts_msgs.msg import BonusStatus, GameResult, GameStatus, GameSurvivor, ProjectileSupply, RobotBonus, RobotDamage, RobotHeat, RobotShoot, RobotStatus, SupplierStatus

from std_msgs.msg import Bool
#from geometry_msgs.msg import PoseWithCovarianceStamped

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
    
    out = 1
    robot.first_occupy(team_pos)
    robot.wall_limit()
    if out == 1:
        out = 'Good'
    
    return out
        
def robot_set_goal(robot, robot_move):    
    score = robot.raw().getValue(robot.pos)
    value = robot.raw().getPoint()
    robot_number = robot.robot_num
    
    if score + thres < value[0] and robot_move:
        behav = 1
        goal = np.array([value[1][0],value[1][1],0,0,0,0,0])   
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

def callback(data):
    global game_status_info
    game_status_info = data.data
                
if __name__ == '__main__':
    rospy.init_node('decision_test')
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

    print("start gogo")
    # initial setting
    pos_view = False 
    robot_move = True
    update_time = 0.1
    robots = ['empty','robot_0', 'robot_1', 'robot_2', 'robot_3']
    team2 = 'blue'
    team1 = 'red'
    robot1 = rules.rules([100,160], team1, 1)
    robot2 = rules.rules([100,160], team1, 2)
    robot3 = rules.rules([100,160], team2, 3)   
    robot4 = rules.rules([100,160], team2, 4)

    r1_pos = [.5,4.5]
    r2_pos = [7.5, 4.5]
    r3_pos = [7.5,.5]
    r4_pos = [0.5, 0.5]
    
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
    eo = [25, 25, 25, 25, 25]
    wc = [20, 20, 20, 20, 20]
    bz = [150,150,150,150,150]
    rz = [100,100,100,100,100]
    cz = [25,25,25,25,25]    
    thres = 10   

    # game_status_info
    game_status_info = False
    
    while True:
        gamestatusreceiver = rospy.Subscriber("/game_cycle", Bool, callback)
        if now >= 180:
            team_1 = robot1.health+robot2.health
            team_2 = robot3.health+robot4.health
            RefereeGameStateClient(3,"robot_0")
            RefereeGameStateClient(3,"robot_1")
            RefereeGameStateClient(3,"robot_2")
            RefereeGameStateClient(3,"robot_3")
            if team_1 > team_2:
                print("red_team win")
            elif team_2 > team_1:
                print("blue_team win")
            else:
                print("draw")



        startTime = time.time()
        now = now_time(startTime)


        while now < 180 and game_status_info:
           # print("game_status : "+str(game_status_info))
            '''print("red_bonus : "+str(red_bonus))
            print("blue_bonus : "+str(blue_bonus))
            print("result : "+str(result))
            print("blue_bonus : "+str(blue_bonus))
            print("game_status : "+str(game_status))
            print("remaining_time : "+str(remaining_time))
            print("red3 : "+str(red3))
            print("red4 : "+str(red4))
            print("blue3 : "+str(blue3))
            print("blue4 : "+str(blue4))
            print("number : "+str(number))
            print("bonus : "+str(bonus))
            print("damage_type : "+str(damage_type))
            print("damage_source : "+str(damage_source))
            print("chassis_volt : "+str(chassis_volt))
            print("chassis_current : "+str(chassis_current))
            print("chassis_power : "+str(chassis_power))
            print("chassis_power_buffer : "+str(chassis_power_buffer))
            print("shooter_heat : "+str(shooter_heat))
            print("frequency : "+str(frequency))
            print("speed : "+str(speed))
            print("id_ : "+str(id_))
            print("level : "+str(level))
            print("remain_hp : "+str(remain_hp))
            print("max_hp : "+str(max_hp))
            print("heat_cooling_limit : "+str(heat_cooling_limit))
            print("heat_cooling_rate : "+str(heat_cooling_rate))
            print("gimbal_output : "+str(gimbal_output))
            print("chassis_output : "+str(chassis_output))
            print("shooter_output : "+str(shooter_output))
            print("status : "+str(status))'''
            now = now_time(startTime)
            buff_control(now)
            reload_control(now)


            r1_state = GetInfoClient("robot_0",1)
            r1_pos = [r1_state['my_pose']['pose']['position']['x'], r1_state['my_pose']['pose']['position']['y']]
            robot1.ammo = r1_state['ammo']
            robot1.health = r1_state['my_health']
            robot1.pos = r1_pos
            r2_state = GetInfoClient("robot_1",1)
            r2_pos = [r2_state['my_pose']['pose']['position']['x'], r2_state['my_pose']['pose']['position']['y']]
            robot2.ammo = r2_state['ammo']
            robot2.health = r2_state['my_health']
            r3_state = GetInfoClient("robot_2",1)
            r3_pos = [r3_state['my_pose']['pose']['position']['x'], r3_state['my_pose']['pose']['position']['y']]
            robot3.ammo = r3_state['ammo']
            robot3.health = r3_state['my_health']
            r4_state = GetInfoClient("robot_3",1)
            r4_pos = [r4_state['my_pose']['pose']['position']['x'], r4_state['my_pose']['pose']['position']['y']]
            robot4.ammo = r4_state['ammo']
            robot4.health = r4_state['my_health']

            robot1.pos = r1_pos
            robot2.pos = r2_pos
            robot3.pos = r3_pos
            robot4.pos = r4_pos

            getinfotime = round(now_time(startTime) - now,5)
            # ===================================================================================================================================
            #r1
            if decision_order(robot1, robot2):
                robot_setting_1(robot1, now, r2_pos, r3_pos, r4_pos, ez[1], mc[1], eo[1], wc[1], cz[1])
                r1_report = robot_setting_2(robot1, now, r2_pos, team1_buff_time, team1_buff_count, team1_has_buff, r1_reload_count, bz[1], rz[1])
                r1_behav, r1_score, r1_value = robot_set_goal(robot1, robot_move)
            #r2
            robot_setting_1(robot2, now, r1_pos, r3_pos, r4_pos, ez[2], mc[2], eo[2], wc[2], cz[2])
            r2_report = robot_setting_2(robot2, now, r1_pos, team1_buff_time, team1_buff_count, team1_has_buff, r2_reload_count, bz[2], rz[2])
            r2_behav, r2_score, r2_value = robot_set_goal(robot2, robot_move)
            #r1 - reverse order
            if not decision_order(robot1, robot2):
                robot_setting_1(robot1, now, r2_pos, r3_pos, r4_pos, ez[1], mc[1], eo[1], wc[1], cz[1])
                r1_report = robot_setting_2(robot1, now, r2_pos, team1_buff_time, team1_buff_count, team1_has_buff, r1_reload_count, bz[1], rz[1])
                r1_behav, r1_score, r1_value = robot_set_goal(robot1, robot_move)
            #r3
            if decision_order(robot3, robot4):
                robot3.enemy_random(20)
                robot_setting_1(robot3, now, r4_pos, r1_pos, r2_pos, ez[3], mc[3], eo[3], wc[3], cz[3])
                r3_report = robot_setting_2(robot3, now, r4_pos, team2_buff_time, team2_buff_count, team2_has_buff, r3_reload_count, bz[3], rz[3])
                r3_behav, r3_score, r3_value = robot_set_goal(robot3, robot_move)
            #r4
            robot4.enemy_random(20)
            robot_setting_1(robot4, now, r3_pos, r1_pos, r2_pos, ez[4], mc[4], eo[4], wc[4], cz[4])
            r4_report = robot_setting_2(robot4, now, r3_pos, team2_buff_time, team2_buff_count, team2_has_buff, r4_reload_count, bz[4], rz[4])
            r4_behav, r4_score, r4_value = robot_set_goal(robot4, robot_move)
            #r3 - reverse order
            if not decision_order(robot3, robot4):
                robot3.enemy_random(20)
                robot_setting_1(robot3, now, r4_pos, r1_pos, r2_pos, ez[3], mc[3], eo[3], wc[3], cz[3])
                r3_report = robot_setting_2(robot3, now, r4_pos, team2_buff_time, team2_buff_count, team2_has_buff, r3_reload_count, bz[3], rz[3])
                r3_behav, r3_score, r3_value = robot_set_goal(robot3, robot_move)


            decisiontime = round(now_time(startTime) - now,5)
            #================ referee system ========================================================================================

            if robot1.isIn(r1_pos, r2_pos, team1, 'bonus'):
                if now - team1_bonus_active_counter > 6 and team1_buff_count > 0:
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
                if now - r1_reload_active_counter > 6 and r1_reload_count > 0:
                    r1_reload_count = r1_reload_count - 1
                    r1_reload_active_counter = now
            else:
                r1_reload_active_counter = now

            if robot2.isIn(r2_pos, r2_pos, team1, 'reload'):
                if now - r2_reload_active_counter > 6 and r2_reload_count > 0:
                    r2_reload_count = r2_reload_count - 1
                    r2_reload_active_counter = now
            else:
                r2_reload_active_counter = now

            if robot3.isIn(r3_pos, r4_pos, team2, 'bonus'):
                if now - team2_bonus_active_counter > 6 and team2_buff_count > 0:
                    team2_buff_count = team2_buff_count -1
                    team2_has_buff = True
                    team2_buff_time_start = now
                    team2_buff_time = 30.0
                    team2_bonus_active_counter = now
            else:
                team2_bonus_active_counter = now

            if team2_has_buff and team2_buff_time > -1:
                team2_buff_time = 30.0-(now - team2_buff_time_start)

            if team2_buff_time < 1:
                team2_has_buff = False

            if robot3.isIn(r3_pos, r3_pos, team2, 'reload'):
                if now - r3_reload_active_counter > 6 and r3_reload_count > 0:
                    r3_reload_count = r3_reload_count -1
                    r3_reload_active_counter = now
            else:
                r3_reload_active_counter = now

            if robot4.isIn(r4_pos, r4_pos, team2, 'reload'):
                if now - r4_reload_active_counter > 6 and r4_reload_count > 0:
                    r4_reload_count = r4_reload_count -1
                    r4_reload_active_counter = now
            else:
                r4_reload_active_counter = now

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

            plt.pause(update_time)


            out1 = np.hstack((robot1.out(),robot2.out()))
            out2 = np.hstack((robot3.out(),robot4.out()))
            out = np.vstack((out2, out1))
            x, y = np.shape(out)
            bar = 300*np.ones(y)
            out = np.vstack((out, bar))

            ##image = np.flip(out, axis=0)
            ##plt.imshow(image, 'hot')

            visualizetime = round(now_time(startTime) - now,5)
            print('=====================================================================')
            print('time:', now, 'buff_left:', team1_buff_time, team2_buff_time)
            print('bonus', team1_buff_count, team2_buff_count, 'reload', r1_reload_count)
            print('r1_behav', r1_behav, 'pos', round(r1_score,2), np.round(r1_pos,2), 'Max' , round(r1_value[0],2), np.round(r1_value[1],2), 'ammo', robot1.ammo, robot1.stance, robot1.health)
            print('r2_behav', r2_behav, 'pos', round(r2_score,2), np.round(r2_pos,2), 'Max' , round(r2_value[0],2), np.round(r2_value[1],2), 'ammo', robot2.ammo, robot2.stance, robot2.health)
            print('r3_behav', r3_behav, 'pos', round(r3_score,2), np.round(r3_pos,2), 'Max' , round(r3_value[0],2), np.round(r3_value[1],2), 'ammo', robot3.ammo, robot3.stance, robot3.health)
            print('r4_behav', r4_behav, 'pos', round(r4_score,2), np.round(r4_pos,2), 'Max' , round(r4_value[0],2), np.round(r4_value[1],2), 'ammo', robot4.ammo, robot4.stance, robot4.health )
            #print(getinfotime, decisiontime, refereetime, visualizetime)

            # force reload - no attack
            if 45 < now < 47:
                robot1.ammo = 5
                robot2.ammo = 5
                robot3.ammo = 5
                robot4.ammo = 5
