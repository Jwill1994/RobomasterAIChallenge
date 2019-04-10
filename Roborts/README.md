**ROS 명령어 다룰 줄 알면 아래 내용 이해하기 편함. 현재 폴더 안의 ros cheat sheet 참조.**  

## 1. ROS kinetic 설치 (우분투 16.04, ros desketop full 버젼 - ros wiki 참조)

## 2. ROS Third Party Package 설치  
```
sudo apt-get install -y ros-kinetic-opencv3             \
                        ros-kinetic-cv-bridge           \
                        ros-kinetic-image-transport     \
                        ros-kinetic-stage-ros           \
                        ros-kinetic-map-server          \
                        ros-kinetic-laser-geometry      \
                        ros-kinetic-interactive-markers \
                        ros-kinetic-tf                  \
                        ros-kinetic-pcl-*               \
                        ros-kinetic-libg2o              \
                        ros-kinetic-rplidar-ros         \
                        ros-kinetic-rviz                \
                        protobuf-compiler               \
                        libprotobuf-dev                 \
                        libsuitesparse-dev              \
                        libgoogle-glog-dev              \
			ros-kinetic-navigation		\
			ros-kinetic-ros-control 	\
			ros-kinetic-ros-controllers	\
			ros-kinetic-gazebo-ros-control	\
			ros-kinetic-teleop-twist-keyboard
```

## 3. git clone 및 workspace 생성  
```
git clone https://github.com/woong164/RobomasterAIChallenge.git roboin
// 아이디 및 비밀번호 입력

mkdir -p catkin_ws/src

cp roboin/Roborts/* catkin_ws/src
// git repository의 Roborts 내부 폴더 및 파일을 catkin_ws 의 src 폴더로 복사

cd catkin_ws; mv src/roborts_gimbal ./; catkin_make
// roborst_gimbal 패키지는 다른 패키지가 build 되기 이전에는 cmake 에러 발생하는 문제 때문에 빼놓고 빌드 후에 다시 빌드함.
// 아직 에러 해결 못함.

mv roborts_gimbal ./src; catkin_make --only-pkg-with-deps roborts_gimbal
// 다시 roborts_gimbal 패키지 포함시키고 해당 패키지만 빌드

source ~/catkin_ws/devel/setup.bash
// 위 코드는 ros 관련 명령어 실행시 항상 필요하기 때문에 터미널 킬 때 자동으로 실행되는 ~/.bashrc 에 입력해 놓기 바람.
// 아니면 매번 터미널 킬때마다 위 코드를 실행해줘야 함. workspace 가 home 폴더에 있다는 가정하에 실행하는 코드임.
// 입력 방법은 'nano ~/.bashrc' 이후 맨 아래줄에 'source ~/catkin_ws/devel/setup.bash' 추가. 순서대로 ctrl+O, Enter, ctrl+X 입력
```

## 4. launch 파일 실행  
```
roslaunch roborts_navigation spawn_multi.launch
// 현재는 2대만 구현. 4대도 가능
// 실행이 안될때는 ([gazebo-2] process has died 라는 에러가 뜰때) ctrl+C 를 눌러 종료 후 커맨드에 'pkill gzserver' 입력. 이후 다시 실행 
```
  

  
  
<hr></hr>

**아래에 나오는 ROS topic publish 커맨드에서는 직접 타이핑을 모두 다 치지 말고**  
**'source ~/catkin_ws/devel/setup.bash' 이후에 ( ~/.bashrc 에 입력해 놓았다면 필요없음)**  
**rostopic pub 까지 치고 일부만 입력한 뒤 계속해서 tab 키를 누르면 자동완성 되는 기능을 적극 활용할 것을 권장.**  

## 5. Robot naviation control
**CUI control:**  
pose 의 position 에 x, y 좌표와 orietation 값을 변경하여 아래와 같은 형식으로 입력.  
x, y 좌표 축은 양 쪽 빨간색 spawn area가 아래쪽으로 가로로 뻗어있을 때 기준 제일 왼쪽 하단 점이 (0,0).    
주의할 점은 pub 뒤에 붙는 토픽이름의 namespace와 header 의 frame_id 에서 map 앞에 오는 namespace가 같아야함.  
아래의 경우는 roborts_Red_0에 해당. ROS에 대한 이해가 부족할 땐 GUI control 을 이용하는 것을 추천.  
```
rostopic pub -1 /roborts_Red_0/move_base_simple/goal geometry_msgs/PoseStamped "header:
  seq: 0
  stamp:
    secs: 0
    nsecs: 0
  frame_id: 'roborts_Red_0/map'
pose:
  position:
    x: 0.0
    y: 0.0
    z: 0.0
  orientation:
    x: 0.0
    y: 0.0
    z: 0.0
    w: 0.0" 
```
  
**GUI control:**   
Rviz 화면 좌측에서 본인이 원하는 로봇에 맞춰 다음을 수정.  
아래에서 {color}는 Red / Blue, {number} 에는 0 / 1 이 들어갈 것.  
로봇 2대만 있는 환경에서는 Red_0 또는 Blue_1 만 적용됨.  
Error 표시가 뜨는 부분은 무시해도 됨.  
```
Global Options - Fixed Frame 을 robrts_{color}_{number}/map 으로 수정  
Map - Topic 을 /robrts_{color}_{number}/map 으정로 수정  
CostMap - Topic 을 /roborts_{color}_{number}/move_base/local_costmap/costmap 으로 수정  
LaserScan - Topic 을 /roborts_{color}_{number}/scan 으로 수정  
Rviz 툴바의(좌측 상단) Panels - Tool Properties 에서 2D Nav Goal - Topic 을 /roborts_{color}_{number}/move_base_simple/goal 으로 수정.  
```
위 사항들 적용 이후 Rviz 화면 중앙 상단의 2D Nav Goal 클릭. 맵상의 적당한 위치에 로봇의 위치와 자세를 클릭.
( CUI control 과 같은 topic 을 publish 하는 역할임)  

**직접 키보드로 컨트롤**  
'rosrun teleop_twist_keyboard teleop_twist_keyboard.py'    
사용 방법은 코드 실행 후 설명 참조.

  
    
 <hr></hr>

### 아래 내용은 반드시 tab completion 기능 활용할 것.

## 5. Robot gimbal control
```
rosservice call /roborts_{color}_{number}/cmd_fric_wheel "open: true" 
// friction wheel open. 시뮬레이션 환경 상에 변화 없음. 실제 환경과 동일한 작동방식을 구현하기 위함.

rostopic pub -1 /roborts_{color}_{number}/cmd_gimbal_angle roborts_msgs/GimbalAngle "yaw_mode: false
pitch_mode: false
yaw_angle: 0.0
pitch_angle: 0.0
// 각도 범위는 radian으로 -1.57~1.57. 
// true 일땐 현재 각도에 대한 상대 각도로 입력 받고, false 일땐 절대 각도로 각도 명령 받음.  
// PID 계수는 조정 안해서 아직은 control 속도가 느리지만 계수만 바꿔서 조정 가능.  

rosservice call /roborts_{color}_{number}/cmd_shoot "mode: 1
number: 1"
// shooting 명령. 아직 단발 모드 1발 발사만 가능함. 이 부분은 수정 없을 듯.  
// shooting frequency 는 낮게 설정해 놨는데 이후에 속도 및 frequency 는 조정 가능.
```

## 6. 기타
**현재 구현된 기능**
- 상하좌우 아머에 hit scan 기능  

**추가 구현이 필요한 기능**
- 카메라에 yolo 및 vision node 통합
- heat 관련 referee sytem 임의로 구현
