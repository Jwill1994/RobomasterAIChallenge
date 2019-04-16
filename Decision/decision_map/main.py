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
    initialize()
    
    team = 'blue'
    
    #stance = 'passive'
    stance = 'aggressive'
    
    my_pos = [1000,1000]
    e1 = [7000, 4000]
    e2 = [7000, 1000]
    
    robot1 = rules.rules([200,320], 'blue')
    
    
    while now_time(startTime) < 20:      
        
        robot1.init()
        robot1.bonus_zone(15-now_time(startTime), 2, False, team, 200)
        robot1.enemy_zone(e1, 90, stance, 700, 100)   
        robot1.enemy_zone(e2, 90-now_time(startTime)*10, stance, 700, 100)     
        robot1.wall_limit()   
              
        robot1.plot()
        plt.pause(0.5)
        
        