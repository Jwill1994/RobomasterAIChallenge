;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::RefereeHit)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'RefereeHit (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEHIT")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEHIT"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEHITREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEHITREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEHITRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEHITRESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass icra_roboin_msgs::RefereeHitRequest
  :super ros::object
  :slots (_header _damage _your_hp _which_armor ))

(defmethod icra_roboin_msgs::RefereeHitRequest
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:damage __damage) 0)
    ((:your_hp __your_hp) 0)
    ((:which_armor __which_armor) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _damage (round __damage))
   (setq _your_hp (round __your_hp))
   (setq _which_armor (round __which_armor))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:damage
   (&optional __damage)
   (if __damage (setq _damage __damage)) _damage)
  (:your_hp
   (&optional __your_hp)
   (if __your_hp (setq _your_hp __your_hp)) _your_hp)
  (:which_armor
   (&optional __which_armor)
   (if __which_armor (setq _which_armor __which_armor)) _which_armor)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _damage
    2
    ;; int16 _your_hp
    2
    ;; uint8 _which_armor
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _damage
       (write-word _damage s)
     ;; int16 _your_hp
       (write-word _your_hp s)
     ;; uint8 _which_armor
       (write-byte _which_armor s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _damage
     (setq _damage (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _your_hp
     (setq _your_hp (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint8 _which_armor
     (setq _which_armor (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeHitResponse
  :super ros::object
  :slots (_success ))

(defmethod icra_roboin_msgs::RefereeHitResponse
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

(defclass icra_roboin_msgs::RefereeHit
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::RefereeHit :md5sum-) "f2c65d4bc3ae1c76b3e2a29cb052e810")
(setf (get icra_roboin_msgs::RefereeHit :datatype-) "icra_roboin_msgs/RefereeHit")
(setf (get icra_roboin_msgs::RefereeHit :request) icra_roboin_msgs::RefereeHitRequest)
(setf (get icra_roboin_msgs::RefereeHit :response) icra_roboin_msgs::RefereeHitResponse)

(defmethod icra_roboin_msgs::RefereeHitRequest
  (:response () (instance icra_roboin_msgs::RefereeHitResponse :init)))

(setf (get icra_roboin_msgs::RefereeHitRequest :md5sum-) "f2c65d4bc3ae1c76b3e2a29cb052e810")
(setf (get icra_roboin_msgs::RefereeHitRequest :datatype-) "icra_roboin_msgs/RefereeHitRequest")
(setf (get icra_roboin_msgs::RefereeHitRequest :definition-)
      "std_msgs/Header header
int16 damage
int16 your_hp

uint8 which_armor

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

(setf (get icra_roboin_msgs::RefereeHitResponse :md5sum-) "f2c65d4bc3ae1c76b3e2a29cb052e810")
(setf (get icra_roboin_msgs::RefereeHitResponse :datatype-) "icra_roboin_msgs/RefereeHitResponse")
(setf (get icra_roboin_msgs::RefereeHitResponse :definition-)
      "std_msgs/Header header
int16 damage
int16 your_hp

uint8 which_armor

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



(provide :icra_roboin_msgs/RefereeHit "f2c65d4bc3ae1c76b3e2a29cb052e810")


