; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude SetEnemyPriority-request.msg.html

(cl:defclass <SetEnemyPriority-request> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (enemy_priority
    :reader enemy_priority
    :initarg :enemy_priority
    :type cl:fixnum
    :initform 0))
)

(cl:defclass SetEnemyPriority-request (<SetEnemyPriority-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetEnemyPriority-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetEnemyPriority-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<SetEnemyPriority-request> is deprecated: use icra_roboin_msgs-srv:SetEnemyPriority-request instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <SetEnemyPriority-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:header-val is deprecated.  Use icra_roboin_msgs-srv:header instead.")
  (header m))

(cl:ensure-generic-function 'enemy_priority-val :lambda-list '(m))
(cl:defmethod enemy_priority-val ((m <SetEnemyPriority-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:enemy_priority-val is deprecated.  Use icra_roboin_msgs-srv:enemy_priority instead.")
  (enemy_priority m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetEnemyPriority-request>) ostream)
  "Serializes a message object of type '<SetEnemyPriority-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'enemy_priority)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetEnemyPriority-request>) istream)
  "Deserializes a message object of type '<SetEnemyPriority-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'enemy_priority) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetEnemyPriority-request>)))
  "Returns string type for a service object of type '<SetEnemyPriority-request>"
  "icra_roboin_msgs/SetEnemyPriorityRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetEnemyPriority-request)))
  "Returns string type for a service object of type 'SetEnemyPriority-request"
  "icra_roboin_msgs/SetEnemyPriorityRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetEnemyPriority-request>)))
  "Returns md5sum for a message object of type '<SetEnemyPriority-request>"
  "72dd0dc38964fd2f75bf39766434fbe2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetEnemyPriority-request)))
  "Returns md5sum for a message object of type 'SetEnemyPriority-request"
  "72dd0dc38964fd2f75bf39766434fbe2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetEnemyPriority-request>)))
  "Returns full string definition for message of type '<SetEnemyPriority-request>"
  (cl:format cl:nil "std_msgs/Header header~%int16 enemy_priority~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetEnemyPriority-request)))
  "Returns full string definition for message of type 'SetEnemyPriority-request"
  (cl:format cl:nil "std_msgs/Header header~%int16 enemy_priority~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetEnemyPriority-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetEnemyPriority-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SetEnemyPriority-request
    (cl:cons ':header (header msg))
    (cl:cons ':enemy_priority (enemy_priority msg))
))
;//! \htmlinclude SetEnemyPriority-response.msg.html

(cl:defclass <SetEnemyPriority-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass SetEnemyPriority-response (<SetEnemyPriority-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SetEnemyPriority-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SetEnemyPriority-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<SetEnemyPriority-response> is deprecated: use icra_roboin_msgs-srv:SetEnemyPriority-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <SetEnemyPriority-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'info-val :lambda-list '(m))
(cl:defmethod info-val ((m <SetEnemyPriority-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:info-val is deprecated.  Use icra_roboin_msgs-srv:info instead.")
  (info m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SetEnemyPriority-response>) ostream)
  "Serializes a message object of type '<SetEnemyPriority-response>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SetEnemyPriority-response>) istream)
  "Deserializes a message object of type '<SetEnemyPriority-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SetEnemyPriority-response>)))
  "Returns string type for a service object of type '<SetEnemyPriority-response>"
  "icra_roboin_msgs/SetEnemyPriorityResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetEnemyPriority-response)))
  "Returns string type for a service object of type 'SetEnemyPriority-response"
  "icra_roboin_msgs/SetEnemyPriorityResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SetEnemyPriority-response>)))
  "Returns md5sum for a message object of type '<SetEnemyPriority-response>"
  "72dd0dc38964fd2f75bf39766434fbe2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SetEnemyPriority-response)))
  "Returns md5sum for a message object of type 'SetEnemyPriority-response"
  "72dd0dc38964fd2f75bf39766434fbe2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SetEnemyPriority-response>)))
  "Returns full string definition for message of type '<SetEnemyPriority-response>"
  (cl:format cl:nil "bool success~%int64 info~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SetEnemyPriority-response)))
  "Returns full string definition for message of type 'SetEnemyPriority-response"
  (cl:format cl:nil "bool success~%int64 info~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SetEnemyPriority-response>))
  (cl:+ 0
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SetEnemyPriority-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SetEnemyPriority-response
    (cl:cons ':success (success msg))
    (cl:cons ':info (info msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SetEnemyPriority)))
  'SetEnemyPriority-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SetEnemyPriority)))
  'SetEnemyPriority-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SetEnemyPriority)))
  "Returns string type for a service object of type '<SetEnemyPriority>"
  "icra_roboin_msgs/SetEnemyPriority")