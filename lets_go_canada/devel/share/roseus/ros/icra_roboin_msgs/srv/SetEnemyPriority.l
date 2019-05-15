;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::SetEnemyPriority)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'SetEnemyPriority (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::SETENEMYPRIORITY")
  (make-package "ICRA_ROBOIN_MSGS::SETENEMYPRIORITY"))
(unless (find-package "ICRA_ROBOIN_MSGS::SETENEMYPRIORITYREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::SETENEMYPRIORITYREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::SETENEMYPRIORITYRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::SETENEMYPRIORITYRESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass icra_roboin_msgs::SetEnemyPriorityRequest
  :super ros::object
  :slots (_header _enemy_priority ))

(defmethod icra_roboin_msgs::SetEnemyPriorityRequest
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:enemy_priority __enemy_priority) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _enemy_priority (round __enemy_priority))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:enemy_priority
   (&optional __enemy_priority)
   (if __enemy_priority (setq _enemy_priority __enemy_priority)) _enemy_priority)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int16 _enemy_priority
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int16 _enemy_priority
       (write-word _enemy_priority s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int16 _enemy_priority
     (setq _enemy_priority (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(defclass icra_roboin_msgs::SetEnemyPriorityResponse
  :super ros::object
  :slots (_success _info ))

(defmethod icra_roboin_msgs::SetEnemyPriorityResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:info __info) 0)
    )
   (send-super :init)
   (setq _success __success)
   (setq _info (round __info))
   self)
  (:success
   (&optional __success)
   (if __success (setq _success __success)) _success)
  (:info
   (&optional __info)
   (if __info (setq _info __info)) _info)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; int64 _info
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; int64 _info
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _info (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _info) (= (length (_info . bv)) 2)) ;; bignum
              (write-long (ash (elt (_info . bv) 0) 0) s)
              (write-long (ash (elt (_info . bv) 1) -1) s))
             ((and (class _info) (= (length (_info . bv)) 1)) ;; big1
              (write-long (elt (_info . bv) 0) s)
              (write-long (if (>= _info 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _info s)(write-long (if (>= _info 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int64 _info
#+(or :alpha :irix6 :x86_64)
      (setf _info (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _info (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass icra_roboin_msgs::SetEnemyPriority
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::SetEnemyPriority :md5sum-) "72dd0dc38964fd2f75bf39766434fbe2")
(setf (get icra_roboin_msgs::SetEnemyPriority :datatype-) "icra_roboin_msgs/SetEnemyPriority")
(setf (get icra_roboin_msgs::SetEnemyPriority :request) icra_roboin_msgs::SetEnemyPriorityRequest)
(setf (get icra_roboin_msgs::SetEnemyPriority :response) icra_roboin_msgs::SetEnemyPriorityResponse)

(defmethod icra_roboin_msgs::SetEnemyPriorityRequest
  (:response () (instance icra_roboin_msgs::SetEnemyPriorityResponse :init)))

(setf (get icra_roboin_msgs::SetEnemyPriorityRequest :md5sum-) "72dd0dc38964fd2f75bf39766434fbe2")
(setf (get icra_roboin_msgs::SetEnemyPriorityRequest :datatype-) "icra_roboin_msgs/SetEnemyPriorityRequest")
(setf (get icra_roboin_msgs::SetEnemyPriorityRequest :definition-)
      "std_msgs/Header header
int16 enemy_priority

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
int64 info

")

(setf (get icra_roboin_msgs::SetEnemyPriorityResponse :md5sum-) "72dd0dc38964fd2f75bf39766434fbe2")
(setf (get icra_roboin_msgs::SetEnemyPriorityResponse :datatype-) "icra_roboin_msgs/SetEnemyPriorityResponse")
(setf (get icra_roboin_msgs::SetEnemyPriorityResponse :definition-)
      "std_msgs/Header header
int16 enemy_priority

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
int64 info

")



(provide :icra_roboin_msgs/SetEnemyPriority "72dd0dc38964fd2f75bf39766434fbe2")


