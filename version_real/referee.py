#!/usr/bin/env python

import rospy
from roborts_msgs.msg import BonusStatus, GameResult, GameStatus, GameSurvivor, ProjectileSupply, RobotBonus, RobotDamage, RobotHeat, RobotShoot, RobotStatus, SupplierStatus

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
   

