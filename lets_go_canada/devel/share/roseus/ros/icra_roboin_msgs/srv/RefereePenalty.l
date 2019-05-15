;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::RefereePenalty)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'RefereePenalty (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEPENALTY")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEPENALTY"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEPENALTYREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEPENALTYREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREEPENALTYRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREEPENALTYRESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass icra_roboin_msgs::RefereePenaltyRequest
  :super ros::object
  :slots (_header _penalty _damage ))

(defmethod icra_roboin_msgs::RefereePenaltyRequest
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:penalty __penalty) 0)
    ((:damage __damage) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _penalty (round __penalty))
   (setq _damage (round __damage))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:penalty
   (&optional __penalty)
   (if __penalty (setq _penalty __penalty)) _penalty)
  (:damage
   (&optional __damage)
   (if __damage (setq _damage __damage)) _damage)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint8 _penalty
    1
    ;; int16 _damage
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint8 _penalty
       (write-byte _penalty s)
     ;; int16 _damage
       (write-word _damage s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint8 _penalty
     (setq _penalty (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; int16 _damage
     (setq _damage (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereePenaltyResponse
  :super ros::object
  :slots (_success ))

(defmethod icra_roboin_msgs::RefereePenaltyResponse
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

(defclass icra_roboin_msgs::RefereePenalty
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::RefereePenalty :md5sum-) "83418028df150acdf30477a936df6b73")
(setf (get icra_roboin_msgs::RefereePenalty :datatype-) "icra_roboin_msgs/RefereePenalty")
(setf (get icra_roboin_msgs::RefereePenalty :request) icra_roboin_msgs::RefereePenaltyRequest)
(setf (get icra_roboin_msgs::RefereePenalty :response) icra_roboin_msgs::RefereePenaltyResponse)

(defmethod icra_roboin_msgs::RefereePenaltyRequest
  (:response () (instance icra_roboin_msgs::RefereePenaltyResponse :init)))

(setf (get icra_roboin_msgs::RefereePenaltyRequest :md5sum-) "83418028df150acdf30477a936df6b73")
(setf (get icra_roboin_msgs::RefereePenaltyRequest :datatype-) "icra_roboin_msgs/RefereePenaltyRequest")
(setf (get icra_roboin_msgs::RefereePenaltyRequest :definition-)
      "std_msgs/Header header
uint8 penalty
int16 damage

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

(setf (get icra_roboin_msgs::RefereePenaltyResponse :md5sum-) "83418028df150acdf30477a936df6b73")
(setf (get icra_roboin_msgs::RefereePenaltyResponse :datatype-) "icra_roboin_msgs/RefereePenaltyResponse")
(setf (get icra_roboin_msgs::RefereePenaltyResponse :definition-)
      "std_msgs/Header header
uint8 penalty
int16 damage

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



(provide :icra_roboin_msgs/RefereePenalty "83418028df150acdf30477a936df6b73")


