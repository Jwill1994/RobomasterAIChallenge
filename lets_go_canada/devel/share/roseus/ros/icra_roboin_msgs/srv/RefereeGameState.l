;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::RefereeGameState)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'RefereeGameState (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEGAMESTATE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEGAMESTATE"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEGAMESTATEREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEGAMESTATEREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEGAMESTATERESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEGAMESTATERESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass icra_roboin_msgs::RefereeGameStateRequest
  :super ros::object
  :slots (_header _game_state ))

(defmethod icra_roboin_msgs::RefereeGameStateRequest
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:game_state __game_state) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _game_state (round __game_state))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:game_state
   (&optional __game_state)
   (if __game_state (setq _game_state __game_state)) _game_state)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _game_state
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _game_state
       (write-byte _game_state s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _game_state
     (setq _game_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeGameStateResponse
  :super ros::object
  :slots (_success ))

(defmethod icra_roboin_msgs::RefereeGameStateResponse
  (:init
   (&key
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _success __success)
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeGameState
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::RefereeGameState :md5sum-) "191c705e7422e4ba0c6776ad9b5cd57f")
(setf (get icra_roboin_msgs::RefereeGameState :datatype-) "icra_roboin_msgs/RefereeGameState")
(setf (get icra_roboin_msgs::RefereeGameState :request) icra_roboin_msgs::RefereeGameStateRequest)
(setf (get icra_roboin_msgs::RefereeGameState :response) icra_roboin_msgs::RefereeGameStateResponse)

(defmethod icra_roboin_msgs::RefereeGameStateRequest
  (:response () (instance icra_roboin_msgs::RefereeGameStateResponse :init)))

(setf (get icra_roboin_msgs::RefereeGameStateRequest :md5sum-) "191c705e7422e4ba0c6776ad9b5cd57f")
(setf (get icra_roboin_msgs::RefereeGameStateRequest :datatype-) "icra_roboin_msgs/RefereeGameStateRequest")
(setf (get icra_roboin_msgs::RefereeGameStateRequest :definition-)
      "std_msgs/Header header

uint8 game_state

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
---
bool success

")

(setf (get icra_roboin_msgs::RefereeGameStateResponse :md5sum-) "191c705e7422e4ba0c6776ad9b5cd57f")
(setf (get icra_roboin_msgs::RefereeGameStateResponse :datatype-) "icra_roboin_msgs/RefereeGameStateResponse")
(setf (get icra_roboin_msgs::RefereeGameStateResponse :definition-)
      "std_msgs/Header header

uint8 game_state

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
---
bool success

")



(provide :icra_roboin_msgs/RefereeGameState "191c705e7422e4ba0c6776ad9b5cd57f")


