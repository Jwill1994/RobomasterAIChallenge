;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::SetGoal_2)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'SetGoal_2 (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::SETGOAL_2")
  (make-package "ICRA_ROBOIN_MSGS::SETGOAL_2"))
(unless (find-package "ICRA_ROBOIN_MSGS::SETGOAL_2REQUEST")
  (make-package "ICRA_ROBOIN_MSGS::SETGOAL_2REQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::SETGOAL_2RESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::SETGOAL_2RESPONSE"))

(in-package "ROS")





(defclass icra_roboin_msgs::SetGoal_2Request
  :super ros::object
  :slots (_goal ))

(defmethod icra_roboin_msgs::SetGoal_2Request
  (:init
   (&key
    ((:goal __goal) (instance icra_roboin_msgs::GoalDescription :init))
    )
   (send-super :init)
   (setq _goal __goal)
   self)
  (:goal
   (&rest __goal)
   (if (keywordp (car __goal))
       (send* _goal __goal)
     (progn
       (if __goal (setq _goal (car __goal)))
       _goal)))
  (:serialization-length
   ()
   (+
    ;; icra_roboin_msgs/GoalDescription _goal
    (send _goal :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; icra_roboin_msgs/GoalDescription _goal
       (send _goal :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; icra_roboin_msgs/GoalDescription _goal
     (send _goal :deserialize buf ptr-) (incf ptr- (send _goal :serialization-length))
   ;;
   self)
  )

(defclass icra_roboin_msgs::SetGoal_2Response
  :super ros::object
  :slots (_success _info ))

(defmethod icra_roboin_msgs::SetGoal_2Response
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

(defclass icra_roboin_msgs::SetGoal_2
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::SetGoal_2 :md5sum-) "3adb4c2d2dfadd29c140f6e5796b855e")
(setf (get icra_roboin_msgs::SetGoal_2 :datatype-) "icra_roboin_msgs/SetGoal_2")
(setf (get icra_roboin_msgs::SetGoal_2 :request) icra_roboin_msgs::SetGoal_2Request)
(setf (get icra_roboin_msgs::SetGoal_2 :response) icra_roboin_msgs::SetGoal_2Response)

(defmethod icra_roboin_msgs::SetGoal_2Request
  (:response () (instance icra_roboin_msgs::SetGoal_2Response :init)))

(setf (get icra_roboin_msgs::SetGoal_2Request :md5sum-) "3adb4c2d2dfadd29c140f6e5796b855e")
(setf (get icra_roboin_msgs::SetGoal_2Request :datatype-) "icra_roboin_msgs/SetGoal_2Request")
(setf (get icra_roboin_msgs::SetGoal_2Request :definition-)
      "icra_roboin_msgs/GoalDescription goal

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

(setf (get icra_roboin_msgs::SetGoal_2Response :md5sum-) "3adb4c2d2dfadd29c140f6e5796b855e")
(setf (get icra_roboin_msgs::SetGoal_2Response :datatype-) "icra_roboin_msgs/SetGoal_2Response")
(setf (get icra_roboin_msgs::SetGoal_2Response :definition-)
      "icra_roboin_msgs/GoalDescription goal

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



(provide :icra_roboin_msgs/SetGoal_2 "3adb4c2d2dfadd29c140f6e5796b855e")


