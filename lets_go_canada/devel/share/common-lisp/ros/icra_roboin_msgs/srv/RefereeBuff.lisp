; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude RefereeBuff-request.msg.html

(cl:defclass <RefereeBuff-request> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (buff_type
    :reader buff_type
    :initarg :buff_type
    :type cl:fixnum
    :initform 0)
   (damage_multiplier
    :reader damage_multiplier
    :initarg :damage_multiplier
    :type cl:float
    :initform 0.0))
)

(cl:defclass RefereeBuff-request (<RefereeBuff-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeBuff-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeBuff-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeBuff-request> is deprecated: use icra_roboin_msgs-srv:RefereeBuff-request instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RefereeBuff-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:header-val is deprecated.  Use icra_roboin_msgs-srv:header instead.")
  (header m))

(cl:ensure-generic-function 'buff_type-val :lambda-list '(m))
(cl:defmethod buff_type-val ((m <RefereeBuff-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:buff_type-val is deprecated.  Use icra_roboin_msgs-srv:buff_type instead.")
  (buff_type m))

(cl:ensure-generic-function 'damage_multiplier-val :lambda-list '(m))
(cl:defmethod damage_multiplier-val ((m <RefereeBuff-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:damage_multiplier-val is deprecated.  Use icra_roboin_msgs-srv:damage_multiplier instead.")
  (damage_multiplier m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeBuff-request>) ostream)
  "Serializes a message object of type '<RefereeBuff-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buff_type)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'damage_multiplier))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeBuff-request>) istream)
  "Deserializes a message object of type '<RefereeBuff-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'buff_type)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'damage_multiplier) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeBuff-request>)))
  "Returns string type for a service object of type '<RefereeBuff-request>"
  "icra_roboin_msgs/RefereeBuffRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeBuff-request)))
  "Returns string type for a service object of type 'RefereeBuff-request"
  "icra_roboin_msgs/RefereeBuffRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeBuff-request>)))
  "Returns md5sum for a message object of type '<RefereeBuff-request>"
  "226c3dd35a73ae10b2dbbb7a86e3381b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeBuff-request)))
  "Returns md5sum for a message object of type 'RefereeBuff-request"
  "226c3dd35a73ae10b2dbbb7a86e3381b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeBuff-request>)))
  "Returns full string definition for message of type '<RefereeBuff-request>"
  (cl:format cl:nil "std_msgs/Header header~%~%~%uint8 buff_type~%float64 damage_multiplier~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeBuff-request)))
  "Returns full string definition for message of type 'RefereeBuff-request"
  (cl:format cl:nil "std_msgs/Header header~%~%~%uint8 buff_type~%float64 damage_multiplier~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeBuff-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeBuff-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeBuff-request
    (cl:cons ':header (header msg))
    (cl:cons ':buff_type (buff_type msg))
    (cl:cons ':damage_multiplier (damage_multiplier msg))
))
;//! \htmlinclude RefereeBuff-response.msg.html

(cl:defclass <RefereeBuff-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RefereeBuff-response (<RefereeBuff-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeBuff-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeBuff-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeBuff-response> is deprecated: use icra_roboin_msgs-srv:RefereeBuff-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RefereeBuff-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeBuff-response>) ostream)
  "Serializes a message object of type '<RefereeBuff-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeBuff-response>) istream)
  "Deserializes a message object of type '<RefereeBuff-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeBuff-response>)))
  "Returns string type for a service object of type '<RefereeBuff-response>"
  "icra_roboin_msgs/RefereeBuffResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeBuff-response)))
  "Returns string type for a service object of type 'RefereeBuff-response"
  "icra_roboin_msgs/RefereeBuffResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeBuff-response>)))
  "Returns md5sum for a message object of type '<RefereeBuff-response>"
  "226c3dd35a73ae10b2dbbb7a86e3381b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeBuff-response)))
  "Returns md5sum for a message object of type 'RefereeBuff-response"
  "226c3dd35a73ae10b2dbbb7a86e3381b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeBuff-response>)))
  "Returns full string definition for message of type '<RefereeBuff-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeBuff-response)))
  "Returns full string definition for message of type 'RefereeBuff-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeBuff-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeBuff-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeBuff-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RefereeBuff)))
  'RefereeBuff-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RefereeBuff)))
  'RefereeBuff-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeBuff)))
  "Returns string type for a service object of type '<RefereeBuff>"
  "icra_roboin_msgs/RefereeBuff")