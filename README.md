# RobomasterAIChallenge
#### 1. please change initial pose in icra_roboin_bringup/launch/yonsei_with_vision.launch 
- robot#1: 0.5,0.5,0.7; robot#2: 7.5, 0.5, 2.5
#### 2. please change ammo in version_real/run.py (40 or 0. default: 0 for robot#1 and 40 for robot#2)
#### 3. <del> the caliabration is currently for robot#1. A calibrated version for robot#2 will be uploaded soon </del>
- calibration parameters are same for both robots
#### 4. publish topic /game_status with state 4 and remaining time 180 to start the game sequence
