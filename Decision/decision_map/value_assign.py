# -*- coding: utf-8 -*-
"""
@author: SHF_W
"""
import random
import numpy as np
import matplotlib.pyplot as plt

class potentialField():
    def __init__(self, size):        
        self.value_matrix = np.zeros(size)
        self.height = self.value_matrix.shape[0]
        self.width = self.value_matrix.shape[1]    
        self.grid = 5000/self.height    
         
    # 정사각형으로 값을 더해줌
    def square_assign(self, x, y, d, value, *args, **kargs):
        setting = kargs.get('mode', None)
        
        x = int(x/self.grid)
        y = int(y/self.grid)
        d = int(d/self.grid)       
        
        left = max(x-d,0)
        right = min(x+d+1, self.width)
        down = max(y-d,0)
        up= min(y+d+1, self.height)    
            
        if setting == 'abs':
            self.value_matrix[down:up, left:right] = value
        else:
            self.value_matrix[down:up, left:right] += value  
    
    # 직사각형으로 값 지정
    def rectangular_assign(self, x1, x2, y1, y2, value, *args, **kargs):
        setting = kargs.get('mode', None)
        
        if x1 < 0:
            x1 = 0
        if x2 > 8000:
            x2 = 8000
        if y1 < 0:
            y1 = 0
        if y2 > 5000:
            y2 = 0      
        
        x1 = int(x1/self.grid)
        x2 = int(x2/self.grid)+1
        y1 = int(y1/self.grid)
        y2 = int(y2/self.grid)+1
        
        if setting == 'abs':
            self.value_matrix[y1:y2, x1:x2] = value             
        else:
            self.value_matrix[y1:y2, x1:x2] += value 
        
    # 원형으로 값 지정
    def circle_assign(self, x, y, r, value, *args, **kargs):
        setting = kargs.get('mode', None)
        
        x = int(x/self.grid)
        y = int(y/self.grid)
        r = int(r/self.grid)        
        m, n = self.value_matrix.shape
        a, b = np.ogrid[-y:m-y, -x:n-x]
        mask = a*a+b*b <= r*r    
        
        if setting == 'abs':
            self.value_matrix[mask] = value
        else:
            self.value_matrix[mask] += value
    

    # 정사각형으로 가운데로 갈수록 값이 커지는 형태로 값 더해줌
    def square_assign_gradient(self, x, y, d, value, gradient):
        x = int(x/self.grid)
        y = int(y/self.grid)
        d = int(d/self.grid)
        
        steps = int(d/gradient+1)
        value= value/steps
        for i in range(steps):        
            left_in = max(x-d+gradient*i,0)
            right_in = min(x+d+1-gradient*i, self.value_matrix.shape[1])
            down_in = max(y-d-1+gradient*i,0)
            up_in= min(y+d-gradient*i, self.value_matrix.shape[0])        
            self.value_matrix[down_in:up_in, left_in:right_in] += value 
            
    # 원형으로 가운데로 갈수록 값이 커지는 형태로 값 더해줌
    def circle_assign_gradient(self, x, y, r, value, gradient):
        x = int(x/self.grid)
        y = int(y/self.grid)
        r = int(r/self.grid)
        
        steps = int(r/gradient+1)
        value = value/steps
        
        for i in range(steps):
            m, n = self.value_matrix.shape
            a, b = np.ogrid[-y:m-y, -x:n-x]
            mask = a*a+b*b <= (gradient*i)*(gradient*i)    
            self.value_matrix[mask] += value
    
    # 현재 위치의 값 보기
    def getValue(self, xy):
        xy[0] = int( xy[0] / self.grid)
        xy[1] = int( xy[1] / self.grid)
        
        return self.value_matrix[xy[0],xy[1]]
       
    # 가장 높은 값과, 그 값의 위치'들'. output이 좀 특이한 형태라 가공 필요
    def getMax(self):
        value = np.max(self.value_matrix)
        return (value, np.where(self.value_matrix >= value))
    
    ## 임시 함수
    def getPoint(self):
        value = np.max(self.value_matrix)
        temp = np.where(self.value_matrix >= value)
        
        index = random.randint(0, len(temp[1])-1)
        
        point = [ temp[1][index], temp[1][index] ]       
        return (value, point )
    
    def out(self):
        return self.value_matrix
    
    def plot(self):
        image = np.flip(self.value_matrix, axis=0)
        plt.imshow(image)
