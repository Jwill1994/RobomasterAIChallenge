; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude RefereeShoot-request.msg.html

(cl:defclass <RefereeShoot-request> (roslisp-msg-protocol:ros-message)
  ((x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0))
)

(cl:defclass RefereeShoot-request (<RefereeShoot-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeShoot-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeShoot-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeShoot-request> is deprecated: use icra_roboin_msgs-srv:RefereeShoot-request instead.")))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <RefereeShoot-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:x-val is deprecated.  Use icra_roboin_msgs-srv:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <RefereeShoot-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:y-val is deprecated.  Use icra_roboin_msgs-srv:y instead.")
  (y m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeShoot-request>) ostream)
  "Serializes a message object of type '<RefereeShoot-request>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeShoot-request>) istream)
  "Deserializes a message object of type '<RefereeShoot-request>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeShoot-request>)))
  "Returns string type for a service object of type '<RefereeShoot-request>"
  "icra_roboin_msgs/RefereeShootRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeShoot-request)))
  "Returns string type for a service object of type 'RefereeShoot-request"
  "icra_roboin_msgs/RefereeShootRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeShoot-request>)))
  "Returns md5sum for a message object of type '<RefereeShoot-request>"
  "e5d6900e0dd94f9bda0c89e5f1af2cd8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeShoot-request)))
  "Returns md5sum for a message object of type 'RefereeShoot-request"
  "e5d6900e0dd94f9bda0c89e5f1af2cd8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeShoot-request>)))
  "Returns full string definition for message of type '<RefereeShoot-request>"
  (cl:format cl:nil "float64 x~%float64 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeShoot-request)))
  "Returns full string definition for message of type 'RefereeShoot-request"
  (cl:format cl:nil "float64 x~%float64 y~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeShoot-request>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeShoot-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeShoot-request
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
))
;//! \htmlinclude RefereeShoot-response.msg.html

(cl:defclass <RefereeShoot-response> (roslisp-msg-protocol:ros-message)
  ((judgement
    :reader judgement
    :initarg :judgement
    :type cl:fixnum
    :initform 0)
   (success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RefereeShoot-response (<RefereeShoot-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeShoot-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeShoot-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeShoot-response> is deprecated: use icra_roboin_msgs-srv:RefereeShoot-response instead.")))

(cl:ensure-generic-function 'judgement-val :lambda-list '(m))
(cl:defmethod judgement-val ((m <RefereeShoot-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:judgement-val is deprecated.  Use icra_roboin_msgs-srv:judgement instead.")
  (judgement m))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RefereeShoot-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeShoot-response>) ostream)
  "Serializes a message object of type '<RefereeShoot-response>"
  (cl:let* ((signed (cl:slot-value msg 'judgement)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeShoot-response>) istream)
  "Deserializes a message object of type '<RefereeShoot-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'judgement) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeShoot-response>)))
  "Returns string type for a service object of type '<RefereeShoot-response>"
  "icra_roboin_msgs/RefereeShootResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeShoot-response)))
  "Returns string type for a service object of type 'RefereeShoot-response"
  "icra_roboin_msgs/RefereeShootResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeShoot-response>)))
  "Returns md5sum for a message object of type '<RefereeShoot-response>"
  "e5d6900e0dd94f9bda0c89e5f1af2cd8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeShoot-response)))
  "Returns md5sum for a message object of type 'RefereeShoot-response"
  "e5d6900e0dd94f9bda0c89e5f1af2cd8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeShoot-response>)))
  "Returns full string definition for message of type '<RefereeShoot-response>"
  (cl:format cl:nil "~%int16 judgement~%bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeShoot-response)))
  "Returns full string definition for message of type 'RefereeShoot-response"
  (cl:format cl:nil "~%int16 judgement~%bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeShoot-response>))
  (cl:+ 0
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeShoot-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeShoot-response
    (cl:cons ':judgement (judgement msg))
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RefereeShoot)))
  'RefereeShoot-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RefereeShoot)))
  'RefereeShoot-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeShoot)))
  "Returns string type for a service object of type '<RefereeShoot>"
  "icra_roboin_msgs/RefereeShoot")