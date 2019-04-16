# -*- coding: utf-8 -*-
"""
@author: SHF_W
"""

import value_assign as va


class rules():
    def __init__(self, size, team):
        self.pm = va.potentialField(size) # pm : potential mplot        
        self.pm.rectangular_assign(0, 8000, 0, 5000, 50)
        self.robot_radius = 350
        self.team = team
    
    def out(self):
        return self.pm.out()
        
    def plot(self):
        self.pm.plot()
        
    def init(self):
        self.pm.rectangular_assign(0, 8000, 0, 5000, 50, mode='abs')
    
    def wall_limit(self): 
        r = self.robot_radius
        self.pm.rectangular_assign(0, r, 0, 5000, 0, mode='abs')
        self.pm.rectangular_assign(8000-r, 8000, 0, 5000 , 0, mode='abs')
        self.pm.rectangular_assign(r, 8000-r, 0, r, 0, mode='abs')
        self.pm.rectangular_assign(r, 8000-r, 5000-r, 5000, 0, mode='abs')
        
        inner_wall_tuple = ((1200,2200, 3750,4000), (1400,1600,1400,2400), (3250,3500,0,1000),(3500,4500,2375,2625),(5800,6800,1000,1250),(6350,6600,2600,3600),(4500,4750,4000,5000))
                
        for item in inner_wall_tuple:
            x1, x2, y1, y2 = item
            r = self.robot_radius
            self.pm.circle_assign(x1, y1, r, 0, mode='abs')
            self.pm.circle_assign(x2, y1, r, 0, mode='abs')
            self.pm.circle_assign(x1, y2, r, 0, mode='abs')
            self.pm.circle_assign(x2, y2, r, 0, mode='abs')
            
            if x2-x1 > y2-y1:
                self.pm.rectangular_assign(x1, x2, y1-r, y2+r, 0, mode='abs')
            else:
                self.pm.rectangular_assign(x1-r, x2+r, y1, y2, 0, mode='abs')
                
                
    def bonus_zone(self, buff_left, buff_zone_count, has_buff, team, value):
        if team == 'blue':
            p = [1700,3250,500]
        else:
            p = [6300,1750,500]        
        
        if not has_buff:
            value = value * 2 #버프가 없을 경우 가치가 2배. 단, 정확히 작동한다면 처음 5초 외에 버프가 없는 시간이 거의 없음
            
        if buff_zone_count > 0:
            # 버프 남은 시간이 5초 이하일 경우 매우 높은 value
            if buff_left < 5:
               self.pm.square_assign(p[0], p[1], p[2], value)
            # 버프 남은 시간이 5~10초일 경우 근처에서 value가 높지만 미리 점령하면 안되므로 점령 지점은 value가 낮음
            elif buff_left < 10:
               self.pm.square_assign_gradient(p[0], p[1], p[2]*4, value,2)               
               self.pm.square_assign(p[0], p[1], p[2], 0, mode='abs')
               
    def enemy_zone(self, enemy_pos, percentage, stance, distance, value):
        # 확실하게 적을 포착할 수록 작은 구역에 더 높은 가치, 적의 위치를 잘 모를 경우 작아짐 
        if percentage > 90:
            constant = 2
        elif percentage > 70:
            constant = 3
        elif percentage > 50:
            constant = 4
        else:
            constant = 5
        
        # aggressive stance일 경우 최적 거리 distance에서 가장 높은 값을 가지고, 거기서 멀어지면 값이 작아짐.
        if stance == 'aggressive':
            self.pm.circle_assign_gradient(enemy_pos[0], enemy_pos[1], distance*constant, value/constant, constant)
            
            if percentage > 75:
                self.pm.circle_assign(enemy_pos[0], enemy_pos[1], distance, -value/constant*2)
                self.pm.circle_assign(enemy_pos[0], enemy_pos[1], self.robot_radius, 0, mode='abs')
        # passive stance일 경우 그냥 적에서 멀어질수록 높은 값을 가짐
        elif stance == 'passive':
           #circle_assign(enemy_pos[0], enemy_pos[1], int(distance*constant*4), value/constant)
           self.pm.circle_assign_gradient(enemy_pos[0], enemy_pos[1], distance*constant*2, -value/constant, constant)
               
    