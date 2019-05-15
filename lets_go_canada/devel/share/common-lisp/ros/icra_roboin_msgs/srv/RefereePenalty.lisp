; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude RefereePenalty-request.msg.html

(cl:defclass <RefereePenalty-request> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (penalty
    :reader penalty
    :initarg :penalty
    :type cl:fixnum
    :initform 0)
   (damage
    :reader damage
    :initarg :damage
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RefereePenalty-request (<RefereePenalty-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereePenalty-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereePenalty-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereePenalty-request> is deprecated: use icra_roboin_msgs-srv:RefereePenalty-request instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RefereePenalty-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:header-val is deprecated.  Use icra_roboin_msgs-srv:header instead.")
  (header m))

(cl:ensure-generic-function 'penalty-val :lambda-list '(m))
(cl:defmethod penalty-val ((m <RefereePenalty-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:penalty-val is deprecated.  Use icra_roboin_msgs-srv:penalty instead.")
  (penalty m))

(cl:ensure-generic-function 'damage-val :lambda-list '(m))
(cl:defmethod damage-val ((m <RefereePenalty-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:damage-val is deprecated.  Use icra_roboin_msgs-srv:damage instead.")
  (damage m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereePenalty-request>) ostream)
  "Serializes a message object of type '<RefereePenalty-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'penalty)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'damage)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereePenalty-request>) istream)
  "Deserializes a message object of type '<RefereePenalty-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'penalty)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'damage) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereePenalty-request>)))
  "Returns string type for a service object of type '<RefereePenalty-request>"
  "icra_roboin_msgs/RefereePenaltyRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereePenalty-request)))
  "Returns string type for a service object of type 'RefereePenalty-request"
  "icra_roboin_msgs/RefereePenaltyRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereePenalty-request>)))
  "Returns md5sum for a message object of type '<RefereePenalty-request>"
  "83418028df150acdf30477a936df6b73")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereePenalty-request)))
  "Returns md5sum for a message object of type 'RefereePenalty-request"
  "83418028df150acdf30477a936df6b73")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereePenalty-request>)))
  "Returns full string definition for message of type '<RefereePenalty-request>"
  (cl:format cl:nil "std_msgs/Header header~%uint8 penalty~%int16 damage~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereePenalty-request)))
  "Returns full string definition for message of type 'RefereePenalty-request"
  (cl:format cl:nil "std_msgs/Header header~%uint8 penalty~%int16 damage~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereePenalty-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereePenalty-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereePenalty-request
    (cl:cons ':header (header msg))
    (cl:cons ':penalty (penalty msg))
    (cl:cons ':damage (damage msg))
))
;//! \htmlinclude RefereePenalty-response.msg.html

(cl:defclass <RefereePenalty-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RefereePenalty-response (<RefereePenalty-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereePenalty-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereePenalty-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereePenalty-response> is deprecated: use icra_roboin_msgs-srv:RefereePenalty-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RefereePenalty-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereePenalty-response>) ostream)
  "Serializes a message object of type '<RefereePenalty-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereePenalty-response>) istream)
  "Deserializes a message object of type '<RefereePenalty-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereePenalty-response>)))
  "Returns string type for a service object of type '<RefereePenalty-response>"
  "icra_roboin_msgs/RefereePenaltyResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereePenalty-response)))
  "Returns string type for a service object of type 'RefereePenalty-response"
  "icra_roboin_msgs/RefereePenaltyResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereePenalty-response>)))
  "Returns md5sum for a message object of type '<RefereePenalty-response>"
  "83418028df150acdf30477a936df6b73")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereePenalty-response)))
  "Returns md5sum for a message object of type 'RefereePenalty-response"
  "83418028df150acdf30477a936df6b73")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereePenalty-response>)))
  "Returns full string definition for message of type '<RefereePenalty-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereePenalty-response)))
  "Returns full string definition for message of type 'RefereePenalty-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereePenalty-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereePenalty-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereePenalty-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RefereePenalty)))
  'RefereePenalty-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RefereePenalty)))
  'RefereePenalty-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereePenalty)))
  "Returns string type for a service object of type '<RefereePenalty>"
  "icra_roboin_msgs/RefereePenalty")