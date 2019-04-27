# -*- coding: utf-8 -*-
"""
Created on Tue Apr 16 22:31:28 2019

@author: SHF_W
"""

import numpy as np
import matplotlib.pyplot as plt
import cv2
import rules
import time


def initialize():    
    global startTime
    startTime = time.time()   
    
    #SetBehaviorClient(behav_,"robot_0")

def now_time(start):    
    return time.time() - start

attack_hold_value = 31
attack_hold_degre = 10 # 초당 value 10씩 감소, 최대 3번, 한 자리에서 계속 공격하지 않게 하는 값. value가 
occupy_hold_value = 200


if __name__ == '__main__':
    
    
    team1 = 'blue'
    team2 = 'red'
    robot1 = rules.rules([200,320], team1)
    robot3 = rules.rules([200,320], team2)
    
    '''
    ==================================================
    Get Value from Black Board
    ==================================================
    '''
    initialize()
    #stance = 'passive'
    stance = 'aggressive'
    
    r1_pos = [0.500, 4.500]
    r3_pos = [7.5, 4]
    #r4_pos = [7.0, .5]
        
    buff_time = 0
    ammo_left = False
    
    while now_time(startTime) < 20:      
        f1 = now_time(startTime)
                
        robot1.init()
        robot1.bonus_zone(buff_time, 2, False, 200)
        robot1.enemy_zone(stance, r3_pos, 90, 1.5, 50)   
        robot1.enemy_zone(stance, r3_pos, 90, 1.5, 50)           
        robot1.reload_zone(stance, now_time(startTime), ammo_left, 10, 100)    
        robot1.move_cost(stance, r1_pos, -2)
        #robot1.enemy_overlap(r3_pos, r4_pos, 25)        
        robot1.first_occupy(r1_pos)
        robot1.wall_limit()
        
        if int(now_time(startTime))%30 == 0 and now_time(startTime) > 2:
            ammo_left = True
        
        '''
        ==================================================
        test variable change
        ==================================================
        '''
        flags = np.zeros([10])
        if now_time(startTime) >= 5 and now_time(startTime) < 35:
            buff_time = 35-now_time(startTime)
        if now_time(startTime) >= 5:
            buff_time = 65-now_time(startTime)
                
        r1_score =  robot1.raw().getValue(r1_pos)
        r1_goal = robot1.raw().getPoint()                
        pt = now_time(startTime) - f1
        print('my_pos : ', r1_score, r1_pos, 'Max :' , r1_goal)
        print('Process Time : ', pt , 'FPS:', int(10/pt)/10 )      
        
        
        
        ''' enemy'''
        robot3.init()
        robot3.bonus_zone(buff_time, 2, False, 200)
        robot3.enemy_zone(stance, r1_pos, 100,  1.5, 50)          
        robot3.reload_zone(stance, now_time(startTime), ammo_left, 10, 100)    
        robot3.move_cost(stance, r3_pos, -2)
        robot3.wall_limit()
        robot1.first_occupy(r3_pos)
        robot1.enemy_occupy(r3_pos)
        
        r3_score =  robot3.raw().getValue(r3_pos)
        r3_goal = robot3.raw().getPoint()  
        
        
        ''' teleport move'''
        if r1_score+50+10 < r1_goal[0] :
            r1_pos = r1_goal[1] 
        
        if r3_score+50+10 < r3_goal[0] :
            r3_pos = r3_goal[1] 
        
        robot1.plot()
        plt.pause(1)
        
        