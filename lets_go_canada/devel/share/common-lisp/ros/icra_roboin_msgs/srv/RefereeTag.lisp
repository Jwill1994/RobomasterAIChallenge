; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude RefereeTag-request.msg.html

(cl:defclass <RefereeTag-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass RefereeTag-request (<RefereeTag-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeTag-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeTag-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeTag-request> is deprecated: use icra_roboin_msgs-srv:RefereeTag-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeTag-request>) ostream)
  "Serializes a message object of type '<RefereeTag-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeTag-request>) istream)
  "Deserializes a message object of type '<RefereeTag-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeTag-request>)))
  "Returns string type for a service object of type '<RefereeTag-request>"
  "icra_roboin_msgs/RefereeTagRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeTag-request)))
  "Returns string type for a service object of type 'RefereeTag-request"
  "icra_roboin_msgs/RefereeTagRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeTag-request>)))
  "Returns md5sum for a message object of type '<RefereeTag-request>"
  "e156420e06769c10db65b694db7ee8bc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeTag-request)))
  "Returns md5sum for a message object of type 'RefereeTag-request"
  "e156420e06769c10db65b694db7ee8bc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeTag-request>)))
  "Returns full string definition for message of type '<RefereeTag-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeTag-request)))
  "Returns full string definition for message of type 'RefereeTag-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeTag-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeTag-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeTag-request
))
;//! \htmlinclude RefereeTag-response.msg.html

(cl:defclass <RefereeTag-response> (roslisp-msg-protocol:ros-message)
  ((info
    :reader info
    :initarg :info
    :type cl:fixnum
    :initform 0)
   (success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass RefereeTag-response (<RefereeTag-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RefereeTag-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RefereeTag-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<RefereeTag-response> is deprecated: use icra_roboin_msgs-srv:RefereeTag-response instead.")))

(cl:ensure-generic-function 'info-val :lambda-list '(m))
(cl:defmethod info-val ((m <RefereeTag-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:info-val is deprecated.  Use icra_roboin_msgs-srv:info instead.")
  (info m))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RefereeTag-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RefereeTag-response>) ostream)
  "Serializes a message object of type '<RefereeTag-response>"
  (cl:let* ((signed (cl:slot-value msg 'info)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RefereeTag-response>) istream)
  "Deserializes a message object of type '<RefereeTag-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'info) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RefereeTag-response>)))
  "Returns string type for a service object of type '<RefereeTag-response>"
  "icra_roboin_msgs/RefereeTagResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeTag-response)))
  "Returns string type for a service object of type 'RefereeTag-response"
  "icra_roboin_msgs/RefereeTagResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RefereeTag-response>)))
  "Returns md5sum for a message object of type '<RefereeTag-response>"
  "e156420e06769c10db65b694db7ee8bc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RefereeTag-response)))
  "Returns md5sum for a message object of type 'RefereeTag-response"
  "e156420e06769c10db65b694db7ee8bc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RefereeTag-response>)))
  "Returns full string definition for message of type '<RefereeTag-response>"
  (cl:format cl:nil "~%int16 info~%bool success~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RefereeTag-response)))
  "Returns full string definition for message of type 'RefereeTag-response"
  (cl:format cl:nil "~%int16 info~%bool success~%~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RefereeTag-response>))
  (cl:+ 0
     2
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RefereeTag-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RefereeTag-response
    (cl:cons ':info (info msg))
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RefereeTag)))
  'RefereeTag-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RefereeTag)))
  'RefereeTag-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RefereeTag)))
  "Returns string type for a service object of type '<RefereeTag>"
  "icra_roboin_msgs/RefereeTag")