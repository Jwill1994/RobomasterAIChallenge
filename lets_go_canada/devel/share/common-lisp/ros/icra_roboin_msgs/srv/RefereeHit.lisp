; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude RefereeHit-request.msg.html

(cl:defclass <RefereeHit-request> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (damage
    :reader damage
    :initarg :damage
    :type cl:fixnum
    :initform 0)
   (your_hp
    :reader your_hp
    :initarg :your_hp
    :type cl:fixnum
    :initform 0)
   (which_armor
    :reader which_armor
    :initarg :which_armor
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RefereeHit-request (<RefereeHit-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeHit-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeHit-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeHit-request> is deprecated: use icra_roboin_msgs-srv:RefereeHit-request instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RefereeHit-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:header-val is deprecated.  Use icra_roboin_msgs-srv:header instead.")
  (header m))

(cl:ensure-generic-function 'damage-val :lambda-list '(m))
(cl:defmethod damage-val ((m <RefereeHit-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:damage-val is deprecated.  Use icra_roboin_msgs-srv:damage instead.")
  (damage m))

(cl:ensure-generic-function 'your_hp-val :lambda-list '(m))
(cl:defmethod your_hp-val ((m <RefereeHit-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:your_hp-val is deprecated.  Use icra_roboin_msgs-srv:your_hp instead.")
  (your_hp m))

(cl:ensure-generic-function 'which_armor-val :lambda-list '(m))
(cl:defmethod which_armor-val ((m <RefereeHit-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:which_armor-val is deprecated.  Use icra_roboin_msgs-srv:which_armor instead.")
  (which_armor m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeHit-request>) ostream)
  "Serializes a message object of type '<RefereeHit-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let* ((signed (cl:slot-value msg 'damage)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'your_hp)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'which_armor)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeHit-request>) istream)
  "Deserializes a message object of type '<RefereeHit-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'damage) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'your_hp) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'which_armor)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeHit-request>)))
  "Returns string type for a service object of type '<RefereeHit-request>"
  "icra_roboin_msgs/RefereeHitRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeHit-request)))
  "Returns string type for a service object of type 'RefereeHit-request"
  "icra_roboin_msgs/RefereeHitRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeHit-request>)))
  "Returns md5sum for a message object of type '<RefereeHit-request>"
  "f2c65d4bc3ae1c76b3e2a29cb052e810")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeHit-request)))
  "Returns md5sum for a message object of type 'RefereeHit-request"
  "f2c65d4bc3ae1c76b3e2a29cb052e810")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeHit-request>)))
  "Returns full string definition for message of type '<RefereeHit-request>"
  (cl:format cl:nil "std_msgs/Header header~%int16 damage~%int16 your_hp~%~%uint8 which_armor~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeHit-request)))
  "Returns full string definition for message of type 'RefereeHit-request"
  (cl:format cl:nil "std_msgs/Header header~%int16 damage~%int16 your_hp~%~%uint8 which_armor~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeHit-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     2
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeHit-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeHit-request
    (cl:cons ':header (header msg))
    (cl:cons ':damage (damage msg))
    (cl:cons ':your_hp (your_hp msg))
    (cl:cons ':which_armor (which_armor msg))
))
;//! \htmlinclude RefereeHit-response.msg.html

(cl:defclass <RefereeHit-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RefereeHit-response (<RefereeHit-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeHit-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeHit-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeHit-response> is deprecated: use icra_roboin_msgs-srv:RefereeHit-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RefereeHit-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeHit-response>) ostream)
  "Serializes a message object of type '<RefereeHit-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeHit-response>) istream)
  "Deserializes a message object of type '<RefereeHit-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeHit-response>)))
  "Returns string type for a service object of type '<RefereeHit-response>"
  "icra_roboin_msgs/RefereeHitResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeHit-response)))
  "Returns string type for a service object of type 'RefereeHit-response"
  "icra_roboin_msgs/RefereeHitResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeHit-response>)))
  "Returns md5sum for a message object of type '<RefereeHit-response>"
  "f2c65d4bc3ae1c76b3e2a29cb052e810")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeHit-response)))
  "Returns md5sum for a message object of type 'RefereeHit-response"
  "f2c65d4bc3ae1c76b3e2a29cb052e810")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeHit-response>)))
  "Returns full string definition for message of type '<RefereeHit-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeHit-response)))
  "Returns full string definition for message of type 'RefereeHit-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeHit-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeHit-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeHit-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RefereeHit)))
  'RefereeHit-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RefereeHit)))
  'RefereeHit-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeHit)))
  "Returns string type for a service object of type '<RefereeHit>"
  "icra_roboin_msgs/RefereeHit")