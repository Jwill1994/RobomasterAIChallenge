;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::GoalDescription)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'GoalDescription (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::GOALDESCRIPTION")
  (make-package "ICRA_ROBOIN_MSGS::GOALDESCRIPTION"))

(in-package "ROS")
;;//! \htmlinclude GoalDescription.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass icra_roboin_msgs::GoalDescription
  :super ros::object
  :slots (_header _x _y _yaw _xa _ya _yawa _etc ))

(defmethod icra_roboin_msgs::GoalDescription
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:yaw __yaw) 0.0)
    ((:xa __xa) 0.0)
    ((:ya __ya) 0.0)
    ((:yawa __yawa) 0.0)
    ((:etc __etc) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _yaw (float __yaw))
   (setq _xa (float __xa))
   (setq _ya (float __ya))
   (setq _yawa (float __yawa))
   (setq _etc (float __etc))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:xa
   (&optional __xa)
   (if __xa (setq _xa __xa)) _xa)
  (:ya
   (&optional __ya)
   (if __ya (setq _ya __ya)) _ya)
  (:yawa
   (&optional __yawa)
   (if __yawa (setq _yawa __yawa)) _yawa)
  (:etc
   (&optional __etc)
   (if __etc (setq _etc __etc)) _etc)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; float64 _yaw
    8
    ;; float64 _xa
    8
    ;; float64 _ya
    8
    ;; float64 _yawa
    8
    ;; float64 _etc
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _xa
       (sys::poke _xa (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ya
       (sys::poke _ya (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yawa
       (sys::poke _yawa (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _etc
       (sys::poke _etc (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _xa
     (setq _xa (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ya
     (setq _ya (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yawa
     (setq _yawa (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _etc
     (setq _etc (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get icra_roboin_msgs::GoalDescription :md5sum-) "245d250014695050d5f8815bfc401e15")
(setf (get icra_roboin_msgs::GoalDescription :datatype-) "icra_roboin_msgs/GoalDescription")
(setf (get icra_roboin_msgs::GoalDescription :definition-)
      "std_msgs/Header header
float64 x
float64 y
float64 yaw
float64 xa
float64 ya
float64 yawa
float64 etc

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

")



(provide :icra_roboin_msgs/GoalDescription "245d250014695050d5f8815bfc401e15")


