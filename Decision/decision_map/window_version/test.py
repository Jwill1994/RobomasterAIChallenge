# -*- coding: utf-8 -*-
"""
Created on Tue Apr 16 20:43:01 2019

@author: SHF_W
"""

import numpy as np
import matplotlib.pyplot as plt
import time
import math

def clip(val, min_, max_):
    return min_ if val < min_ else max_ if val > max_ else val

def sector_assign(x, y, r1, r2, theta, gamma, value):
        m, n = value_matrix.shape
        a, b = np.ogrid[-y:m-y, -x:n-x]        
        
        lower = (theta-gamma/2) % (math.pi*2)
        upper = (theta+gamma/2) % (math.pi*2)

        slope1= math.tan(theta-gamma/2)
        slope2= math.tan(theta+gamma/2)        
        

        mask1 = a*a+b*b <= r2*r2
        mask2 = a*a+b*b >= r1*r1

        if lower < 1.5*math.pi and lower > 0.5*math.pi:
            mask3 = (a) < slope1*(b)
        else:
            mask3 = (a) > slope1*(b)
            
        if upper < 1.5*math.pi and upper > 0.5*math.pi:
            mask4 = (a) > (slope2*b)
        else:
            mask4 = (a) < (slope2*b)             
        
        mask = np.multiply(mask1, mask2)
        mask = np.multiply(mask, mask3)
        mask = np.multiply(mask, mask4)
        

        value_matrix[mask] += value
        return mask1, mask2, mask3, mask4, mask
        
tt=time.time()
value_matrix = np.zeros([200,320])
x=100; y=80; r=60; theta = 0; gamma = math.pi/2
sa=sector_assign(x,y,30, r, theta, gamma, 100)
mask1=sa[0]
mask2=sa[1]
mask3=sa[2]
mask4=sa[3]
mask=sa[4]

ttt = time.time()-tt

print('Processing time : ', ttt)
plt.imshow(np.flip(value_matrix, axis=0))
