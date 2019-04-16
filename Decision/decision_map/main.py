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


if __name__ == '__main__':
    
    
    team = 'blue'
    robot1 = rules.rules([200,320], team)
    
    '''
    ==================================================
    Get Value from Black Board
    ==================================================
    '''
    initialize()
    #stance = 'passive'
    stance = 'aggressive'
    
    my_position = [500, 4500]
    e1 = [7500, 500]
    e2 = [500, 500]
        
    buff_time = 0
    ammo_left = False
    
    while now_time(startTime) < 40:      
        
        robot1.init()
        robot1.bonus_zone(buff_time, 2, False, 200)
        robot1.enemy_zone(stance, e1, 90,  700, 50)   
        robot1.enemy_zone(stance, e2, 90,  700, 50)   
        
        robot1.reload_zone(stance, now_time(startTime), ammo_left, 10, 100)    
        robot1.move_cost(my_position, stance, -2)
        robot1.wall_limit() #   
              
        
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
                
        b = robot1.raw().getPoint()        
        print('my_pos : ', robot1.raw().getValue(my_position), my_position, 'Max :' , b)
        
        
        robot1.plot()
        plt.pause(1)
        
        