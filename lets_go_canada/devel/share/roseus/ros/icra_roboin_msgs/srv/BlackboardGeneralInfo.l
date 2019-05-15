;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::BlackboardGeneralInfo)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'BlackboardGeneralInfo (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::BLACKBOARDGENERALINFO")
  (make-package "ICRA_ROBOIN_MSGS::BLACKBOARDGENERALINFO"))
(unless (find-package "ICRA_ROBOIN_MSGS::BLACKBOARDGENERALINFOREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::BLACKBOARDGENERALINFOREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::BLACKBOARDGENERALINFORESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::BLACKBOARDGENERALINFORESPONSE"))

(in-package "ROS")



(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass icra_roboin_msgs::BlackboardGeneralInfoRequest
  :super ros::object
  :slots (_stamp _request_sender _confirm ))

(defmethod icra_roboin_msgs::BlackboardGeneralInfoRequest
  (:init
   (&key
    ((:stamp __stamp) (instance ros::time :init))
    ((:request_sender __request_sender) "")
    ((:confirm __confirm) nil)
    )
   (send-super :init)
   (setq _stamp __stamp)
   (setq _request_sender (string __request_sender))
   (setq _confirm __confirm)
   self)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:request_sender
   (&optional __request_sender)
   (if __request_sender (setq _request_sender __request_sender)) _request_sender)
  (:confirm
   (&optional __confirm)
   (if __confirm (setq _confirm __confirm)) _confirm)
  (:serialization-length
   ()
   (+
    ;; time _stamp
    8
    ;; string _request_sender
    4 (length _request_sender)
    ;; bool _confirm
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _stamp
       (write-long (send _stamp :sec) s) (write-long (send _stamp :nsec) s)
     ;; string _request_sender
       (write-long (length _request_sender) s) (princ _request_sender s)
     ;; bool _confirm
       (if _confirm (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _stamp
     (send _stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _request_sender
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _request_sender (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; bool _confirm
     (setq _confirm (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::BlackboardGeneralInfoResponse
  :super ros::object
  :slots (_stamp _time_passed_from_start _game_state _buff_zone_cooltime _reload_zone_cooltime _my_health _is_hit _which_armor_hit _last_hit_time _has_buff _buff_left _ammo _my_pose _enemy_pose1 _enemy_pose2 _how_many_enemies_detected _is_enemy_1_detected _is_enemy_2_detected _locked_on_enemy _enemy_priority _goal _current_behavior_style _current_behavior_process ))

(defmethod icra_roboin_msgs::BlackboardGeneralInfoResponse
  (:init
   (&key
    ((:stamp __stamp) (instance ros::time :init))
    ((:time_passed_from_start __time_passed_from_start) 0)
    ((:game_state __game_state) 0)
    ((:buff_zone_cooltime __buff_zone_cooltime) 0)
    ((:reload_zone_cooltime __reload_zone_cooltime) 0)
    ((:my_health __my_health) 0)
    ((:is_hit __is_hit) nil)
    ((:which_armor_hit __which_armor_hit) 0)
    ((:last_hit_time __last_hit_time) 0)
    ((:has_buff __has_buff) nil)
    ((:buff_left __buff_left) 0)
    ((:ammo __ammo) 0)
    ((:my_pose __my_pose) (instance geometry_msgs::PoseStamped :init))
    ((:enemy_pose1 __enemy_pose1) (instance geometry_msgs::PoseStamped :init))
    ((:enemy_pose2 __enemy_pose2) (instance geometry_msgs::PoseStamped :init))
    ((:how_many_enemies_detected __how_many_enemies_detected) 0)
    ((:is_enemy_1_detected __is_enemy_1_detected) nil)
    ((:is_enemy_2_detected __is_enemy_2_detected) nil)
    ((:locked_on_enemy __locked_on_enemy) 0)
    ((:enemy_priority __enemy_priority) 0)
    ((:goal __goal) (instance icra_roboin_msgs::GoalDescription :init))
    ((:current_behavior_style __current_behavior_style) 0)
    ((:current_behavior_process __current_behavior_process) 0)
    )
   (send-super :init)
   (setq _stamp __stamp)
   (setq _time_passed_from_start (round __time_passed_from_start))
   (setq _game_state (round __game_state))
   (setq _buff_zone_cooltime (round __buff_zone_cooltime))
   (setq _reload_zone_cooltime (round __reload_zone_cooltime))
   (setq _my_health (round __my_health))
   (setq _is_hit __is_hit)
   (setq _which_armor_hit (round __which_armor_hit))
   (setq _last_hit_time (round __last_hit_time))
   (setq _has_buff __has_buff)
   (setq _buff_left (round __buff_left))
   (setq _ammo (round __ammo))
   (setq _my_pose __my_pose)
   (setq _enemy_pose1 __enemy_pose1)
   (setq _enemy_pose2 __enemy_pose2)
   (setq _how_many_enemies_detected (round __how_many_enemies_detected))
   (setq _is_enemy_1_detected __is_enemy_1_detected)
   (setq _is_enemy_2_detected __is_enemy_2_detected)
   (setq _locked_on_enemy (round __locked_on_enemy))
   (setq _enemy_priority (round __enemy_priority))
   (setq _goal __goal)
   (setq _current_behavior_style (round __current_behavior_style))
   (setq _current_behavior_process (round __current_behavior_process))
   self)
  (:stamp
   (&optional __stamp)
   (if __stamp (setq _stamp __stamp)) _stamp)
  (:time_passed_from_start
   (&optional __time_passed_from_start)
   (if __time_passed_from_start (setq _time_passed_from_start __time_passed_from_start)) _time_passed_from_start)
  (:game_state
   (&optional __game_state)
   (if __game_state (setq _game_state __game_state)) _game_state)
  (:buff_zone_cooltime
   (&optional __buff_zone_cooltime)
   (if __buff_zone_cooltime (setq _buff_zone_cooltime __buff_zone_cooltime)) _buff_zone_cooltime)
  (:reload_zone_cooltime
   (&optional __reload_zone_cooltime)
   (if __reload_zone_cooltime (setq _reload_zone_cooltime __reload_zone_cooltime)) _reload_zone_cooltime)
  (:my_health
   (&optional __my_health)
   (if __my_health (setq _my_health __my_health)) _my_health)
  (:is_hit
   (&optional __is_hit)
   (if __is_hit (setq _is_hit __is_hit)) _is_hit)
  (:which_armor_hit
   (&optional __which_armor_hit)
   (if __which_armor_hit (setq _which_armor_hit __which_armor_hit)) _which_armor_hit)
  (:last_hit_time
   (&optional __last_hit_time)
   (if __last_hit_time (setq _last_hit_time __last_hit_time)) _last_hit_time)
  (:has_buff
   (&optional __has_buff)
   (if __has_buff (setq _has_buff __has_buff)) _has_buff)
  (:buff_left
   (&optional __buff_left)
   (if __buff_left (setq _buff_left __buff_left)) _buff_left)
  (:ammo
   (&optional __ammo)
   (if __ammo (setq _ammo __ammo)) _ammo)
  (:my_pose
   (&rest __my_pose)
   (if (keywordp (car __my_pose))
       (send* _my_pose __my_pose)
     (progn
       (if __my_pose (setq _my_pose (car __my_pose)))
       _my_pose)))
  (:enemy_pose1
   (&rest __enemy_pose1)
   (if (keywordp (car __enemy_pose1))
       (send* _enemy_pose1 __enemy_pose1)
     (progn
       (if __enemy_pose1 (setq _enemy_pose1 (car __enemy_pose1)))
       _enemy_pose1)))
  (:enemy_pose2
   (&rest __enemy_pose2)
   (if (keywordp (car __enemy_pose2))
       (send* _enemy_pose2 __enemy_pose2)
     (progn
       (if __enemy_pose2 (setq _enemy_pose2 (car __enemy_pose2)))
       _enemy_pose2)))
  (:how_many_enemies_detected
   (&optional __how_many_enemies_detected)
   (if __how_many_enemies_detected (setq _how_many_enemies_detected __how_many_enemies_detected)) _how_many_enemies_detected)
  (:is_enemy_1_detected
   (&optional __is_enemy_1_detected)
   (if __is_enemy_1_detected (setq _is_enemy_1_detected __is_enemy_1_detected)) _is_enemy_1_detected)
  (:is_enemy_2_detected
   (&optional __is_enemy_2_detected)
   (if __is_enemy_2_detected (setq _is_enemy_2_detected __is_enemy_2_detected)) _is_enemy_2_detected)
  (:locked_on_enemy
   (&optional __locked_on_enemy)
   (if __locked_on_enemy (setq _locked_on_enemy __locked_on_enemy)) _locked_on_enemy)
  (:enemy_priority
   (&optional __enemy_priority)
   (if __enemy_priority (setq _enemy_priority __enemy_priority)) _enemy_priority)
  (:goal
   (&rest __goal)
   (if (keywordp (car __goal))
       (send* _goal __goal)
     (progn
       (if __goal (setq _goal (car __goal)))
       _goal)))
  (:current_behavior_style
   (&optional __current_behavior_style)
   (if __current_behavior_style (setq _current_behavior_style __current_behavior_style)) _current_behavior_style)
  (:current_behavior_process
   (&optional __current_behavior_process)
   (if __current_behavior_process (setq _current_behavior_process __current_behavior_process)) _current_behavior_process)
  (:serialization-length
   ()
   (+
    ;; time _stamp
    8
    ;; int32 _time_passed_from_start
    4
    ;; uint8 _game_state
    1
    ;; int32 _buff_zone_cooltime
    4
    ;; int32 _reload_zone_cooltime
    4
    ;; int16 _my_health
    2
    ;; bool _is_hit
    1
    ;; uint8 _which_armor_hit
    1
    ;; int32 _last_hit_time
    4
    ;; bool _has_buff
    1
    ;; int32 _buff_left
    4
    ;; int16 _ammo
    2
    ;; geometry_msgs/PoseStamped _my_pose
    (send _my_pose :serialization-length)
    ;; geometry_msgs/PoseStamped _enemy_pose1
    (send _enemy_pose1 :serialization-length)
    ;; geometry_msgs/PoseStamped _enemy_pose2
    (send _enemy_pose2 :serialization-length)
    ;; uint8 _how_many_enemies_detected
    1
    ;; bool _is_enemy_1_detected
    1
    ;; bool _is_enemy_2_detected
    1
    ;; uint8 _locked_on_enemy
    1
    ;; uint8 _enemy_priority
    1
    ;; icra_roboin_msgs/GoalDescription _goal
    (send _goal :serialization-length)
    ;; uint8 _current_behavior_style
    1
    ;; uint8 _current_behavior_process
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; time _stamp
       (write-long (send _stamp :sec) s) (write-long (send _stamp :nsec) s)
     ;; int32 _time_passed_from_start
       (write-long _time_passed_from_start s)
     ;; uint8 _game_state
       (write-byte _game_state s)
     ;; int32 _buff_zone_cooltime
       (write-long _buff_zone_cooltime s)
     ;; int32 _reload_zone_cooltime
       (write-long _reload_zone_cooltime s)
     ;; int16 _my_health
       (write-word _my_health s)
     ;; bool _is_hit
       (if _is_hit (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _which_armor_hit
       (write-byte _which_armor_hit s)
     ;; int32 _last_hit_time
       (write-long _last_hit_time s)
     ;; bool _has_buff
       (if _has_buff (write-byte -1 s) (write-byte 0 s))
     ;; int32 _buff_left
       (write-long _buff_left s)
     ;; int16 _ammo
       (write-word _ammo s)
     ;; geometry_msgs/PoseStamped _my_pose
       (send _my_pose :serialize s)
     ;; geometry_msgs/PoseStamped _enemy_pose1
       (send _enemy_pose1 :serialize s)
     ;; geometry_msgs/PoseStamped _enemy_pose2
       (send _enemy_pose2 :serialize s)
     ;; uint8 _how_many_enemies_detected
       (write-byte _how_many_enemies_detected s)
     ;; bool _is_enemy_1_detected
       (if _is_enemy_1_detected (write-byte -1 s) (write-byte 0 s))
     ;; bool _is_enemy_2_detected
       (if _is_enemy_2_detected (write-byte -1 s) (write-byte 0 s))
     ;; uint8 _locked_on_enemy
       (write-byte _locked_on_enemy s)
     ;; uint8 _enemy_priority
       (write-byte _enemy_priority s)
     ;; icra_roboin_msgs/GoalDescription _goal
       (send _goal :serialize s)
     ;; uint8 _current_behavior_style
       (write-byte _current_behavior_style s)
     ;; uint8 _current_behavior_process
       (write-byte _current_behavior_process s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; time _stamp
     (send _stamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _stamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _time_passed_from_start
     (setq _time_passed_from_start (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint8 _game_state
     (setq _game_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int32 _buff_zone_cooltime
     (setq _buff_zone_cooltime (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _reload_zone_cooltime
     (setq _reload_zone_cooltime (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _my_health
     (setq _my_health (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _is_hit
     (setq _is_hit (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _which_armor_hit
     (setq _which_armor_hit (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int32 _last_hit_time
     (setq _last_hit_time (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _has_buff
     (setq _has_buff (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _buff_left
     (setq _buff_left (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _ammo
     (setq _ammo (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; geometry_msgs/PoseStamped _my_pose
     (send _my_pose :deserialize buf ptr-) (incf ptr- (send _my_pose :serialization-length))
   ;; geometry_msgs/PoseStamped _enemy_pose1
     (send _enemy_pose1 :deserialize buf ptr-) (incf ptr- (send _enemy_pose1 :serialization-length))
   ;; geometry_msgs/PoseStamped _enemy_pose2
     (send _enemy_pose2 :deserialize buf ptr-) (incf ptr- (send _enemy_pose2 :serialization-length))
   ;; uint8 _how_many_enemies_detected
     (setq _how_many_enemies_detected (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; bool _is_enemy_1_detected
     (setq _is_enemy_1_detected (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _is_enemy_2_detected
     (setq _is_enemy_2_detected (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; uint8 _locked_on_enemy
     (setq _locked_on_enemy (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _enemy_priority
     (setq _enemy_priority (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; icra_roboin_msgs/GoalDescription _goal
     (send _goal :deserialize buf ptr-) (incf ptr- (send _goal :serialization-length))
   ;; uint8 _current_behavior_style
     (setq _current_behavior_style (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _current_behavior_process
     (setq _current_behavior_process (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::BlackboardGeneralInfo
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::BlackboardGeneralInfo :md5sum-) "194169ae9786a8ee22311fb734602f60")
(setf (get icra_roboin_msgs::BlackboardGeneralInfo :datatype-) "icra_roboin_msgs/BlackboardGeneralInfo")
(setf (get icra_roboin_msgs::BlackboardGeneralInfo :request) icra_roboin_msgs::BlackboardGeneralInfoRequest)
(setf (get icra_roboin_msgs::BlackboardGeneralInfo :response) icra_roboin_msgs::BlackboardGeneralInfoResponse)

(defmethod icra_roboin_msgs::BlackboardGeneralInfoRequest
  (:response () (instance icra_roboin_msgs::BlackboardGeneralInfoResponse :init)))

(setf (get icra_roboin_msgs::BlackboardGeneralInfoRequest :md5sum-) "194169ae9786a8ee22311fb734602f60")
(setf (get icra_roboin_msgs::BlackboardGeneralInfoRequest :datatype-) "icra_roboin_msgs/BlackboardGeneralInfoRequest")
(setf (get icra_roboin_msgs::BlackboardGeneralInfoRequest :definition-)
      "time stamp
string request_sender
bool confirm
---
time stamp
int32 time_passed_from_start

uint8 game_state
int32 buff_zone_cooltime
int32 reload_zone_cooltime
int16 my_health
bool is_hit
uint8 which_armor_hit
int32 last_hit_time
bool has_buff
int32 buff_left
int16 ammo
geometry_msgs/PoseStamped my_pose
geometry_msgs/PoseStamped enemy_pose1
geometry_msgs/PoseStamped enemy_pose2
uint8 how_many_enemies_detected
bool is_enemy_1_detected
bool is_enemy_2_detected
uint8 locked_on_enemy
uint8 enemy_priority
icra_roboin_msgs/GoalDescription goal
uint8 current_behavior_style
uint8 current_behavior_process


================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: icra_roboin_msgs/GoalDescription
std_msgs/Header header
float64 x
float64 y
float64 yaw
float64 xa
float64 ya
float64 yawa
float64 etc
")

(setf (get icra_roboin_msgs::BlackboardGeneralInfoResponse :md5sum-) "194169ae9786a8ee22311fb734602f60")
(setf (get icra_roboin_msgs::BlackboardGeneralInfoResponse :datatype-) "icra_roboin_msgs/BlackboardGeneralInfoResponse")
(setf (get icra_roboin_msgs::BlackboardGeneralInfoResponse :definition-)
      "time stamp
string request_sender
bool confirm
---
time stamp
int32 time_passed_from_start

uint8 game_state
int32 buff_zone_cooltime
int32 reload_zone_cooltime
int16 my_health
bool is_hit
uint8 which_armor_hit
int32 last_hit_time
bool has_buff
int32 buff_left
int16 ammo
geometry_msgs/PoseStamped my_pose
geometry_msgs/PoseStamped enemy_pose1
geometry_msgs/PoseStamped enemy_pose2
uint8 how_many_enemies_detected
bool is_enemy_1_detected
bool is_enemy_2_detected
uint8 locked_on_enemy
uint8 enemy_priority
icra_roboin_msgs/GoalDescription goal
uint8 current_behavior_style
uint8 current_behavior_process


================================================================================
MSG: geometry_msgs/PoseStamped
# A Pose with reference coordinate frame and timestamp
Header header
Pose pose

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: icra_roboin_msgs/GoalDescription
std_msgs/Header header
float64 x
float64 y
float64 yaw
float64 xa
float64 ya
float64 yawa
float64 etc
")



(provide :icra_roboin_msgs/BlackboardGeneralInfo "194169ae9786a8ee22311fb734602f60")


