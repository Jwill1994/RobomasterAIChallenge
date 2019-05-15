;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::RefereeBuff)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'RefereeBuff (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEBUFF")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEBUFF"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEBUFFREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEBUFFREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEBUFFRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEBUFFRESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass icra_roboin_msgs::RefereeBuffRequest
  :super ros::object
  :slots (_header _buff_type _damage_multiplier ))

(defmethod icra_roboin_msgs::RefereeBuffRequest
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:buff_type __buff_type) 0)
    ((:damage_multiplier __damage_multiplier) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _buff_type (round __buff_type))
   (setq _damage_multiplier (float __damage_multiplier))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:buff_type
   (&optional __buff_type)
   (if __buff_type (setq _buff_type __buff_type)) _buff_type)
  (:damage_multiplier
   (&optional __damage_multiplier)
   (if __damage_multiplier (setq _damage_multiplier __damage_multiplier)) _damage_multiplier)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _buff_type
    1
    ;; float64 _damage_multiplier
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _buff_type
       (write-byte _buff_type s)
     ;; float64 _damage_multiplier
       (sys::poke _damage_multiplier (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _buff_type
     (setq _buff_type (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _damage_multiplier
     (setq _damage_multiplier (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeBuffResponse
  :super ros::object
  :slots (_success ))

(defmethod icra_roboin_msgs::RefereeBuffResponse
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

(defclass icra_roboin_msgs::RefereeBuff
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::RefereeBuff :md5sum-) "226c3dd35a73ae10b2dbbb7a86e3381b")
(setf (get icra_roboin_msgs::RefereeBuff :datatype-) "icra_roboin_msgs/RefereeBuff")
(setf (get icra_roboin_msgs::RefereeBuff :request) icra_roboin_msgs::RefereeBuffRequest)
(setf (get icra_roboin_msgs::RefereeBuff :response) icra_roboin_msgs::RefereeBuffResponse)

(defmethod icra_roboin_msgs::RefereeBuffRequest
  (:response () (instance icra_roboin_msgs::RefereeBuffResponse :init)))

(setf (get icra_roboin_msgs::RefereeBuffRequest :md5sum-) "226c3dd35a73ae10b2dbbb7a86e3381b")
(setf (get icra_roboin_msgs::RefereeBuffRequest :datatype-) "icra_roboin_msgs/RefereeBuffRequest")
(setf (get icra_roboin_msgs::RefereeBuffRequest :definition-)
      "std_msgs/Header header


uint8 buff_type
float64 damage_multiplier

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

(setf (get icra_roboin_msgs::RefereeBuffResponse :md5sum-) "226c3dd35a73ae10b2dbbb7a86e3381b")
(setf (get icra_roboin_msgs::RefereeBuffResponse :datatype-) "icra_roboin_msgs/RefereeBuffResponse")
(setf (get icra_roboin_msgs::RefereeBuffResponse :definition-)
      "std_msgs/Header header


uint8 buff_type
float64 damage_multiplier

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



(provide :icra_roboin_msgs/RefereeBuff "226c3dd35a73ae10b2dbbb7a86e3381b")


