; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude AmmoConsume-request.msg.html

(cl:defclass <AmmoConsume-request> (roslisp-msg-protocol:ros-message)
  ((shots
    :reader shots
    :initarg :shots
    :type cl:fixnum
    :initform 0))
)

(cl:defclass AmmoConsume-request (<AmmoConsume-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AmmoConsume-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AmmoConsume-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<AmmoConsume-request> is deprecated: use icra_roboin_msgs-srv:AmmoConsume-request instead.")))

(cl:ensure-generic-function 'shots-val :lambda-list '(m))
(cl:defmethod shots-val ((m <AmmoConsume-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:shots-val is deprecated.  Use icra_roboin_msgs-srv:shots instead.")
  (shots m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AmmoConsume-request>) ostream)
  "Serializes a message object of type '<AmmoConsume-request>"
  (cl:let* ((signed (cl:slot-value msg 'shots)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AmmoConsume-request>) istream)
  "Deserializes a message object of type '<AmmoConsume-request>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'shots) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AmmoConsume-request>)))
  "Returns string type for a service object of type '<AmmoConsume-request>"
  "icra_roboin_msgs/AmmoConsumeRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AmmoConsume-request)))
  "Returns string type for a service object of type 'AmmoConsume-request"
  "icra_roboin_msgs/AmmoConsumeRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AmmoConsume-request>)))
  "Returns md5sum for a message object of type '<AmmoConsume-request>"
  "5a21dae1d703fd52723eaf9cba0ba9be")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AmmoConsume-request)))
  "Returns md5sum for a message object of type 'AmmoConsume-request"
  "5a21dae1d703fd52723eaf9cba0ba9be")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AmmoConsume-request>)))
  "Returns full string definition for message of type '<AmmoConsume-request>"
  (cl:format cl:nil "int16 shots~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AmmoConsume-request)))
  "Returns full string definition for message of type 'AmmoConsume-request"
  (cl:format cl:nil "int16 shots~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AmmoConsume-request>))
  (cl:+ 0
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AmmoConsume-request>))
  "Converts a ROS message object to a list"
  (cl:list 'AmmoConsume-request
    (cl:cons ':shots (shots msg))
))
;//! \htmlinclude AmmoConsume-response.msg.html

(cl:defclass <AmmoConsume-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass AmmoConsume-response (<AmmoConsume-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AmmoConsume-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AmmoConsume-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<AmmoConsume-response> is deprecated: use icra_roboin_msgs-srv:AmmoConsume-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <AmmoConsume-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AmmoConsume-response>) ostream)
  "Serializes a message object of type '<AmmoConsume-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AmmoConsume-response>) istream)
  "Deserializes a message object of type '<AmmoConsume-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AmmoConsume-response>)))
  "Returns string type for a service object of type '<AmmoConsume-response>"
  "icra_roboin_msgs/AmmoConsumeResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AmmoConsume-response)))
  "Returns string type for a service object of type 'AmmoConsume-response"
  "icra_roboin_msgs/AmmoConsumeResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AmmoConsume-response>)))
  "Returns md5sum for a message object of type '<AmmoConsume-response>"
  "5a21dae1d703fd52723eaf9cba0ba9be")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AmmoConsume-response)))
  "Returns md5sum for a message object of type 'AmmoConsume-response"
  "5a21dae1d703fd52723eaf9cba0ba9be")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AmmoConsume-response>)))
  "Returns full string definition for message of type '<AmmoConsume-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AmmoConsume-response)))
  "Returns full string definition for message of type 'AmmoConsume-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AmmoConsume-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AmmoConsume-response>))
  "Converts a ROS message object to a list"
  (cl:list 'AmmoConsume-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'AmmoConsume)))
  'AmmoConsume-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'AmmoConsume)))
  'AmmoConsume-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AmmoConsume)))
  "Returns string type for a service object of type '<AmmoConsume>"
  "icra_roboin_msgs/AmmoConsume")