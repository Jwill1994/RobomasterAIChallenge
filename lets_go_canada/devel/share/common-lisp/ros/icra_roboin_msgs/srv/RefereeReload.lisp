; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude RefereeReload-request.msg.html

(cl:defclass <RefereeReload-request> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header)))
)

(cl:defclass RefereeReload-request (<RefereeReload-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeReload-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeReload-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeReload-request> is deprecated: use icra_roboin_msgs-srv:RefereeReload-request instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RefereeReload-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:header-val is deprecated.  Use icra_roboin_msgs-srv:header instead.")
  (header m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeReload-request>) ostream)
  "Serializes a message object of type '<RefereeReload-request>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeReload-request>) istream)
  "Deserializes a message object of type '<RefereeReload-request>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeReload-request>)))
  "Returns string type for a service object of type '<RefereeReload-request>"
  "icra_roboin_msgs/RefereeReloadRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeReload-request)))
  "Returns string type for a service object of type 'RefereeReload-request"
  "icra_roboin_msgs/RefereeReloadRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeReload-request>)))
  "Returns md5sum for a message object of type '<RefereeReload-request>"
  "b6d38dcead6f905c5bce55b773b3d510")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeReload-request)))
  "Returns md5sum for a message object of type 'RefereeReload-request"
  "b6d38dcead6f905c5bce55b773b3d510")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeReload-request>)))
  "Returns full string definition for message of type '<RefereeReload-request>"
  (cl:format cl:nil "std_msgs/Header header~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeReload-request)))
  "Returns full string definition for message of type 'RefereeReload-request"
  (cl:format cl:nil "std_msgs/Header header~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeReload-request>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeReload-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeReload-request
    (cl:cons ':header (header msg))
))
;//! \htmlinclude RefereeReload-response.msg.html

(cl:defclass <RefereeReload-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RefereeReload-response (<RefereeReload-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeReload-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeReload-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeReload-response> is deprecated: use icra_roboin_msgs-srv:RefereeReload-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RefereeReload-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeReload-response>) ostream)
  "Serializes a message object of type '<RefereeReload-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeReload-response>) istream)
  "Deserializes a message object of type '<RefereeReload-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeReload-response>)))
  "Returns string type for a service object of type '<RefereeReload-response>"
  "icra_roboin_msgs/RefereeReloadResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeReload-response)))
  "Returns string type for a service object of type 'RefereeReload-response"
  "icra_roboin_msgs/RefereeReloadResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeReload-response>)))
  "Returns md5sum for a message object of type '<RefereeReload-response>"
  "b6d38dcead6f905c5bce55b773b3d510")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeReload-response)))
  "Returns md5sum for a message object of type 'RefereeReload-response"
  "b6d38dcead6f905c5bce55b773b3d510")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeReload-response>)))
  "Returns full string definition for message of type '<RefereeReload-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeReload-response)))
  "Returns full string definition for message of type 'RefereeReload-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeReload-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeReload-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeReload-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RefereeReload)))
  'RefereeReload-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RefereeReload)))
  'RefereeReload-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeReload)))
  "Returns string type for a service object of type '<RefereeReload>"
  "icra_roboin_msgs/RefereeReload")