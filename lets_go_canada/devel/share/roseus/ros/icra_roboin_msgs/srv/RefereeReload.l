;; Auto-generated. Do not edit!


(when (boundp 'icra_roboin_msgs::RefereeReload)
  (if (not (find-package "ICRA_ROBOIN_MSGS"))
    (make-package "ICRA_ROBOIN_MSGS"))
  (shadow 'RefereeReload (find-package "ICRA_ROBOIN_MSGS")))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREERELOAD")
  (make-package "ICRA_ROBOIN_MSGS::REFEREERELOAD"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREERELOADREQUEST")
  (make-package "ICRA_ROBOIN_MSGS::REFEREERELOADREQUEST"))
(unless (find-package "ICRA_ROBOIN_MSGS::REFEREERELOADRESPONSE")
  (make-package "ICRA_ROBOIN_MSGS::REFEREERELOADRESPONSE"))

(in-package "ROS")

(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))




(defclass icra_roboin_msgs::RefereeReloadRequest
  :super ros::object
  :slots (_header ))

(defmethod icra_roboin_msgs::RefereeReloadRequest
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    )
   (send-super :init)
   (setq _header __header)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;;
   self)
  )

(defclass icra_roboin_msgs::RefereeReloadResponse
  :super ros::object
  :slots (_success ))

(defmethod icra_roboin_msgs::RefereeReloadResponse
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

(defclass icra_roboin_msgs::RefereeReload
  :super ros::object
  :slots ())

(setf (get icra_roboin_msgs::RefereeReload :md5sum-) "b6d38dcead6f905c5bce55b773b3d510")
(setf (get icra_roboin_msgs::RefereeReload :datatype-) "icra_roboin_msgs/RefereeReload")
(setf (get icra_roboin_msgs::RefereeReload :request) icra_roboin_msgs::RefereeReloadRequest)
(setf (get icra_roboin_msgs::RefereeReload :response) icra_roboin_msgs::RefereeReloadResponse)

(defmethod icra_roboin_msgs::RefereeReloadRequest
  (:response () (instance icra_roboin_msgs::RefereeReloadResponse :init)))

(setf (get icra_roboin_msgs::RefereeReloadRequest :md5sum-) "b6d38dcead6f905c5bce55b773b3d510")
(setf (get icra_roboin_msgs::RefereeReloadRequest :datatype-) "icra_roboin_msgs/RefereeReloadRequest")
(setf (get icra_roboin_msgs::RefereeReloadRequest :definition-)
      "std_msgs/Header header

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

(setf (get icra_roboin_msgs::RefereeReloadResponse :md5sum-) "b6d38dcead6f905c5bce55b773b3d510")
(setf (get icra_roboin_msgs::RefereeReloadResponse :datatype-) "icra_roboin_msgs/RefereeReloadResponse")
(setf (get icra_roboin_msgs::RefereeReloadResponse :definition-)
      "std_msgs/Header header

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



(provide :icra_roboin_msgs/RefereeReload "b6d38dcead6f905c5bce55b773b3d510")


