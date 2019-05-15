; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude RefereeGameState-request.msg.html

(cl:defclass <RefereeGameState-request> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (game_state
    :reader game_state
    :initarg :game_state
    :type cl:fixnum
    :initform 0))
)

(cl:defclass RefereeGameState-request (<RefereeGameState-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeGameState-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeGameState-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeGameState-request> is deprecated: use icra_roboin_msgs-srv:RefereeGameState-request instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RefereeGameState-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:header-val is deprecated.  Use icra_roboin_msgs-srv:header instead.")
  (header m))

(cl:ensure-generic-function 'game_state-val :lambda-list '(m))
(cl:defmethod game_state-val ((m <RefereeGameState-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:game_state-val is deprecated.  Use icra_roboin_msgs-srv:game_state instead.")
  (game_state m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeGameState-request>) ostream)
  "Serializes a message object of type '<RefereeGameState-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'game_state)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeGameState-request>) istream)
  "Deserializes a message object of type '<RefereeGameState-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'game_state)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeGameState-request>)))
  "Returns string type for a service object of type '<RefereeGameState-request>"
  "icra_roboin_msgs/RefereeGameStateRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeGameState-request)))
  "Returns string type for a service object of type 'RefereeGameState-request"
  "icra_roboin_msgs/RefereeGameStateRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeGameState-request>)))
  "Returns md5sum for a message object of type '<RefereeGameState-request>"
  "191c705e7422e4ba0c6776ad9b5cd57f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeGameState-request)))
  "Returns md5sum for a message object of type 'RefereeGameState-request"
  "191c705e7422e4ba0c6776ad9b5cd57f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeGameState-request>)))
  "Returns full string definition for message of type '<RefereeGameState-request>"
  (cl:format cl:nil "std_msgs/Header header~%~%uint8 game_state~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeGameState-request)))
  "Returns full string definition for message of type 'RefereeGameState-request"
  (cl:format cl:nil "std_msgs/Header header~%~%uint8 game_state~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeGameState-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeGameState-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeGameState-request
    (cl:cons ':header (header msg))
    (cl:cons ':game_state (game_state msg))
))
;//! \htmlinclude RefereeGameState-response.msg.html

(cl:defclass <RefereeGameState-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RefereeGameState-response (<RefereeGameState-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeGameState-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeGameState-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeGameState-response> is deprecated: use icra_roboin_msgs-srv:RefereeGameState-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RefereeGameState-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeGameState-response>) ostream)
  "Serializes a message object of type '<RefereeGameState-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeGameState-response>) istream)
  "Deserializes a message object of type '<RefereeGameState-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeGameState-response>)))
  "Returns string type for a service object of type '<RefereeGameState-response>"
  "icra_roboin_msgs/RefereeGameStateResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeGameState-response)))
  "Returns string type for a service object of type 'RefereeGameState-response"
  "icra_roboin_msgs/RefereeGameStateResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeGameState-response>)))
  "Returns md5sum for a message object of type '<RefereeGameState-response>"
  "191c705e7422e4ba0c6776ad9b5cd57f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeGameState-response)))
  "Returns md5sum for a message object of type 'RefereeGameState-response"
  "191c705e7422e4ba0c6776ad9b5cd57f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeGameState-response>)))
  "Returns full string definition for message of type '<RefereeGameState-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeGameState-response)))
  "Returns full string definition for message of type 'RefereeGameState-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeGameState-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeGameState-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeGameState-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RefereeGameState)))
  'RefereeGameState-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RefereeGameState)))
  'RefereeGameState-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeGameState)))
  "Returns string type for a service object of type '<RefereeGameState>"
  "icra_roboin_msgs/RefereeGameState")