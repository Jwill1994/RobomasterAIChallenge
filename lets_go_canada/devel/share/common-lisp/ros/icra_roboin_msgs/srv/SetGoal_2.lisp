; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude SetGoal_2-request.msg.html

(cl:defclass <SetGoal_2-request> (roslisp-msg-protocol:ros-message)
  ((goal
    :reader goal
    :initarg :goal
    :type icra_roboin_msgs-msg:GoalDescription
    :initform (cl:make-instance 'icra_roboin_msgs-msg:GoalDescription)))
)

(cl:defclass SetGoal_2-request (<SetGoal_2-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetGoal_2-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetGoal_2-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<SetGoal_2-request> is deprecated: use icra_roboin_msgs-srv:SetGoal_2-request instead.")))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <SetGoal_2-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:goal-val is deprecated.  Use icra_roboin_msgs-srv:goal instead.")
  (goal m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetGoal_2-request>) ostream)
  "Serializes a message object of type '<SetGoal_2-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetGoal_2-request>) istream)
  "Deserializes a message object of type '<SetGoal_2-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetGoal_2-request>)))
  "Returns string type for a service object of type '<SetGoal_2-request>"
  "icra_roboin_msgs/SetGoal_2Request")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetGoal_2-request)))
  "Returns string type for a service object of type 'SetGoal_2-request"
  "icra_roboin_msgs/SetGoal_2Request")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetGoal_2-request>)))
  "Returns md5sum for a message object of type '<SetGoal_2-request>"
  "3adb4c2d2dfadd29c140f6e5796b855e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetGoal_2-request)))
  "Returns md5sum for a message object of type 'SetGoal_2-request"
  "3adb4c2d2dfadd29c140f6e5796b855e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetGoal_2-request>)))
  "Returns full string definition for message of type '<SetGoal_2-request>"
  (cl:format cl:nil "icra_roboin_msgs/GoalDescription goal~%~%================================================================================~%MSG: icra_roboin_msgs/GoalDescription~%std_msgs/Header header~%float64 x~%float64 y~%float64 yaw~%float64 xa~%float64 ya~%float64 yawa~%float64 etc~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetGoal_2-request)))
  "Returns full string definition for message of type 'SetGoal_2-request"
  (cl:format cl:nil "icra_roboin_msgs/GoalDescription goal~%~%================================================================================~%MSG: icra_roboin_msgs/GoalDescription~%std_msgs/Header header~%float64 x~%float64 y~%float64 yaw~%float64 xa~%float64 ya~%float64 yawa~%float64 etc~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetGoal_2-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetGoal_2-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetGoal_2-request
    (cl:cons ':goal (goal msg))
))
;//! \htmlinclude SetGoal_2-response.msg.html

(cl:defclass <SetGoal_2-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (info
    :reader info
    :initarg :info
    :type cl:integer
    :initform 0))
)

(cl:defclass SetGoal_2-response (<SetGoal_2-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetGoal_2-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetGoal_2-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<SetGoal_2-response> is deprecated: use icra_roboin_msgs-srv:SetGoal_2-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetGoal_2-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'info-val :lambda-list '(m))
(cl:defmethod info-val ((m <SetGoal_2-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:info-val is deprecated.  Use icra_roboin_msgs-srv:info instead.")
  (info m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetGoal_2-response>) ostream)
  "Serializes a message object of type '<SetGoal_2-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'info)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetGoal_2-response>) istream)
  "Deserializes a message object of type '<SetGoal_2-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'info) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetGoal_2-response>)))
  "Returns string type for a service object of type '<SetGoal_2-response>"
  "icra_roboin_msgs/SetGoal_2Response")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetGoal_2-response)))
  "Returns string type for a service object of type 'SetGoal_2-response"
  "icra_roboin_msgs/SetGoal_2Response")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetGoal_2-response>)))
  "Returns md5sum for a message object of type '<SetGoal_2-response>"
  "3adb4c2d2dfadd29c140f6e5796b855e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetGoal_2-response)))
  "Returns md5sum for a message object of type 'SetGoal_2-response"
  "3adb4c2d2dfadd29c140f6e5796b855e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetGoal_2-response>)))
  "Returns full string definition for message of type '<SetGoal_2-response>"
  (cl:format cl:nil "bool success~%int64 info~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetGoal_2-response)))
  "Returns full string definition for message of type 'SetGoal_2-response"
  (cl:format cl:nil "bool success~%int64 info~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetGoal_2-response>))
  (cl:+ 0
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetGoal_2-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetGoal_2-response
    (cl:cons ':success (success msg))
    (cl:cons ':info (info msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetGoal_2)))
  'SetGoal_2-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetGoal_2)))
  'SetGoal_2-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetGoal_2)))
  "Returns string type for a service object of type '<SetGoal_2>"
  "icra_roboin_msgs/SetGoal_2")