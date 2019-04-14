# all heuristic ver0413

# obsVectors
# my pos
# companion pos
# companion status

# enemy pos 1
# enemy pos 2

# health
# bullets
# captian
 

# action : x,y, bullets fire rate

# stance
# robot_status
# aggressive_full
# aggressive_low_ammo
# passive

# behaviour
# 0 (default) : go to start point
# 1 : move to (x,y)
# 2 : patrol
# 3 : flee
# 4 : attack_1 : attack and move
# 5 : attack_2 : attack and just rotate.
# 6 : occupy

####### 

import time
import numpy as np
import cv2
import matplotlib.pyplot as plt

'''
import rospy
import roslib
from icra_roboin_decision_modules.roboin_behavior_service_module import SetBehaviorClient, SetGoalClient, GetInfoClient

rospy.init_node('decision_test')

# my = robot_0
GetInfoClient("robot_0",1)

def initialize():    
    global startTime
    startTime = time.time()
    behav_= 7 # 초기 위치로 이동
    SetBehaviorClient(behav_,"robot_0")
    

'''
# 현재 상태를 받아 stance를 결정
def set_stance(obsVectors):
    if obsVectors['my_health'] > 1000 and obsVectors['ammo'] > 10:
        stance = 'aggressive'
    elif obsVectors['my_health'] > 1000:
        stance = 'aggressive_low_ammo'
    elif obsVectors['ammo'] > 20:
        stance = 'aggreesive_low_health'
    else:
        stance = 'passive'
    return stance

def initialize():    
    global startTime
    startTime = time.time()   
    
    #SetBehaviorClient(behav_,"robot_0")

def now_time(start):    
    return time.time() - start



# 정사각형으로 값을 더해줌
def square_assign(x, y, d, value):
    left = max(x-d,0)
    right = min(x+d+1, value_matrix.shape[1])
    down = max(y-d-1,0)
    up= min(y+d, value_matrix.shape[0])    
        
    value_matrix[left:right, down:up] += value  

# 정사각형으로 값을 지정
def rectangular_assign_abs(x1, x2, y1, y2, value):
    value_matrix[x1:x2, y1:y2] = value    
    
# 원형으로 값을 더해줌
def circle_assign(x, y, r, value):
    m, n = value_matrix.shape
    a, b = np.ogrid[-x:m-x, -y:n-y]
    mask = a*a+b*b <= r*r    
    value_matrix[mask] += value

# 원형으로 값을 지정
def circle_assign_abs(x, y, r, value):
    m, n = value_matrix.shape
    a, b = np.ogrid[-x:m-x, -y:n-y]
    mask = a*a+b*b <= r*r    
    value_matrix[mask] = value

# 도넛형태로 값을 더해줌
def donut_assign(value_matrix, x, y, r1, r2, value):
    m, n = value_matrix.shape
    a, b = np.ogrid[-x:m-x, -y:n-y]      
    mask1 = a*a + b*b <= r1*r1
    mask2 = a*a + b*b <= r2*r2
    value_matrix[mask1] -= value
    value_matrix[mask2] += value

# 벽에 좌표를 지정하지 않도록 값을 0으로 지정 (= 절대로 가면 안되는 곳 값 할당)
# 사실 중간은 rectangular로 지정해야하는데 좌표 지정하기 귀찮아서..... 나중에 서중 예쩡 지금 벽 모양 이상한건 그 때문.
def wall_limit():
       
    # outer wall
    rectangular_assign_abs(0, outer, 0, n, 0)
    rectangular_assign_abs(m-outer, m, 0, n, 0)
    rectangular_assign_abs(outer, m-outer, 0, outer,0)
    rectangular_assign_abs(outer, m-outer, n-outer, n,0 )
    
    # inner wall
    inner_wall_list = ((3750,4000,1200,2200), (1400,2400,1400,1600), (0,1000,3250,3500),(2375,2625,3500,4500),(1000,1250,5800,6800),(2600,3600,6350,6600),(4000,5000,4500,4750))
    
    for item in inner_wall_list:
        y1 = int(item[0]/grid_size)
        y2 = int(item[1]/grid_size)
        x1 = int(item[2]/grid_size)
        x2 = int(item[3]/grid_size)
        #rectangular_assign_abs(int(max(y1-robot_radius/grid_size,0)), int(min(y2+robot_radius/grid_size,n)) , int(max(x1-robot_radius/grid_size,0)), int(min(x2+robot_radius/grid_size,0)),0)
        #rectangular_assign_abs(y1, y2, x1, x2,0)
        circle_assign_abs(y1, x1,robot_radius/grid_size,0)
        circle_assign_abs(y1, x2,robot_radius/grid_size,0)
        circle_assign_abs(y2, x1,robot_radius/grid_size,0)
        circle_assign_abs(y2, x2,robot_radius/grid_size,0)
        circle_assign_abs((y1+y2)/2, x1,robot_radius/grid_size,0)
        circle_assign_abs((y1+y2)/2, x2,robot_radius/grid_size,0)
        circle_assign_abs(y1, (x1+x2)/2,robot_radius/grid_size,0)
        circle_assign_abs(y2, (x1+x2)/2,robot_radius/grid_size,0)

# 정사각형으로 가운데로 갈수록 값이 커지는 형태로 값 더해줌
def square_assign_gradient(x, y, d, value, gradient):
    steps = int(d/gradient)
    value= int(value/(steps+1))
    for i in range(steps+1):        
        left_in = max(x-d+gradient*i,0)
        right_in = min(x+d+1-gradient*i, value_matrix.shape[1])
        down_in = max(y-d-1+gradient*i,0)
        up_in= min(y+d-gradient*i, value_matrix.shape[0])        
        value_matrix[left_in:right_in, down_in:up_in] += value 
        
# 원형으로 가운데로 갈수록 값이 커지는 형태로 값 더해줌
def circle_assign_gradient(x, y, r, value, gradient):
    steps = int(r/gradient)
    value= int(value/(steps+1))
    
    for i in range(steps+1):
        m, n = value_matrix.shape
        a, b = np.ogrid[-x:m-x, -y:n-y]
        mask = a*a+b*b <= (gradient*i)*(gradient*i)    
        value_matrix[mask] += value

# 현재 위치의 값 보기
def get_value(yx):
    yx[0] = int( yx[0] / grid_size)
    yx[1] = int( yx[1] / grid_size)
    
    return value_matrix[yx[0],yx[1]]
   
# 가장 높은 값과, 그 값의 위치'들'. output이 좀 특이한 형태라 가공 필요
def get_maixmum():
    value = np.max(value_matrix)
    return (value, np.where(value_matrix >= value))

# 완전 미완성
def decision(behaviour, my_pos, occupy):
    if (behaviour == 4) or (behaviour == 5):
        thres = 30
    if behaviour == 6:
        thres = 100
        
    if get_value(my_pos) + thres < get_maixmum[0]:
        behaviour = 1
        # 가장 점수가 높은 좌표 중 가장 가까운 곳으로 이동
        #
        # 작성 해야함
    
    
# 점령 보너스 값 지정
# 버프 존 점령 시간 : 5초
def bonus_zone(buff_left, buff_zone_count, has_buff, team, value):
    if team == 'blue':
        yxd = [3250,1700,500]
    else:
        yxd = [1750,6300,500]
    
    for i in range(3):
        yxd[i] = int(yxd[i] / grid_size)
    
    if not has_buff:
        value = value * 2 #버프가 없을 경우 가치가 2배. 단, 정확히 작동한다면 처음 5초 외에 버프가 없는 시간이 거의 없음
        
    if buff_zone_count > 0:
        # 버프 남은 시간이 5초 이하일 경우 매우 높은 value
        if buff_left < 5:
            square_assign(yxd[0], yxd[1], yxd[2], value)
        # 버프 남은 시간이 5~10초일 경우 근처에서 value가 높지만 미리 점령하면 안되므로 점령 지점은 value가 낮음
        elif buff_left < 10:
            square_assign_gradient(yxd[0], yxd[1], yxd[2]*4, value, 2)
            square_assign(yxd[0], yxd[1], yxd[2], -value)
        
        
# 재장전 값 지정        
# 적 위치 값 지정
# 자신의 stance에 따라 적 위치에 따른 최적 위치 계산
            
def enemy_zone(enemy_pos, percentage, stance, distance, value):
    # 확실하게 적을 포착할 수록 작은 구역에 더 높은 가치, 적의 위치를 잘 모를 경우 작아짐
    enemy_pos[0] = enemy_pos[0] / grid_size
    enemy_pos[1] = enemy_pos[1] / grid_size
    
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
        circle_assign_gradient(enemy_pos[0], enemy_pos[1], int(distance*constant), value/constant, constant*3)
        circle_assign(enemy_pos[0], enemy_pos[1], int(distance), -value/constant/2)
    # passive stance일 경우 그냥 적에서 멀어질수록 높은 값을 가짐
    elif stance == 'passive':
       #circle_assign(enemy_pos[0], enemy_pos[1], int(distance*constant*4), value/constant)
       circle_assign_gradient(enemy_pos[0], enemy_pos[1], int(distance*constant*2), -value/constant, constant*3)
       
    

# 부상당한 아군 방어 지정

# 이미지로 값을 한번에 시각화 하기 위한 정규화
def normalize(value_matrix):
    min_value = np.min(value_matrix)
    max_value = np.max(value_matrix)
    d = max_value-min_value
    if d == 0: d = 1
    result = (255 / d) * value_matrix
    return result



global value_matrix
value_matrix = np.ones([200,320])*50
team = 'blue'
m, n = value_matrix.shape
robot_radius = 350
grid_size = 5000/m
outer = int(robot_radius/grid_size)
initialize()

#stance = 'passive'
stance = 'aggressive'

my_pos = [1000,1000]

while now_time(startTime) < 20:       
    
    value_matrix = np.ones([200,320])*50
    bonus_zone(15-now_time(startTime), 2, False, team, 200)
    enemy_zone([4000,7000], 70, stance, 30, 100)   
    enemy_zone([1000,7000], 70, stance, 30, 100)     
    wall_limit()   
        
    value_matrix = value_matrix.clip(min=0)    
    image = normalize(np.flip(value_matrix, axis=0))
    #cv2.imshow('image', image)
    plt.pause(0.5)
    plt.imshow(image)
    

    #key = cv2.waitKey(1) & 0xFF
    #if key == ord('q'):
     #   break    
#cv2.destroyAllWindows()    


















