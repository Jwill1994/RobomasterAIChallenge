; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude BehaviorStyleSet-request.msg.html

(cl:defclass <BehaviorStyleSet-request> (roslisp-msg-protocol:ros-message)
  ((behavior
    :reader behavior
    :initarg :behavior
    :type cl:fixnum
    :initform 0))
)

(cl:defclass BehaviorStyleSet-request (<BehaviorStyleSet-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BehaviorStyleSet-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BehaviorStyleSet-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<BehaviorStyleSet-request> is deprecated: use icra_roboin_msgs-srv:BehaviorStyleSet-request instead.")))

(cl:ensure-generic-function 'behavior-val :lambda-list '(m))
(cl:defmethod behavior-val ((m <BehaviorStyleSet-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:behavior-val is deprecated.  Use icra_roboin_msgs-srv:behavior instead.")
  (behavior m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BehaviorStyleSet-request>) ostream)
  "Serializes a message object of type '<BehaviorStyleSet-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behavior)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BehaviorStyleSet-request>) istream)
  "Deserializes a message object of type '<BehaviorStyleSet-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'behavior)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BehaviorStyleSet-request>)))
  "Returns string type for a service object of type '<BehaviorStyleSet-request>"
  "icra_roboin_msgs/BehaviorStyleSetRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BehaviorStyleSet-request)))
  "Returns string type for a service object of type 'BehaviorStyleSet-request"
  "icra_roboin_msgs/BehaviorStyleSetRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BehaviorStyleSet-request>)))
  "Returns md5sum for a message object of type '<BehaviorStyleSet-request>"
  "55497cc3dd55c5632392e3da32c9b591")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BehaviorStyleSet-request)))
  "Returns md5sum for a message object of type 'BehaviorStyleSet-request"
  "55497cc3dd55c5632392e3da32c9b591")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BehaviorStyleSet-request>)))
  "Returns full string definition for message of type '<BehaviorStyleSet-request>"
  (cl:format cl:nil "uint8 behavior~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BehaviorStyleSet-request)))
  "Returns full string definition for message of type 'BehaviorStyleSet-request"
  (cl:format cl:nil "uint8 behavior~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BehaviorStyleSet-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BehaviorStyleSet-request>))
  "Converts a ROS message object to a list"
  (cl:list 'BehaviorStyleSet-request
    (cl:cons ':behavior (behavior msg))
))
;//! \htmlinclude BehaviorStyleSet-response.msg.html

(cl:defclass <BehaviorStyleSet-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (info
    :reader info
    :initarg :info
    :type cl:fixnum
    :initform 0))
)

(cl:defclass BehaviorStyleSet-response (<BehaviorStyleSet-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BehaviorStyleSet-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BehaviorStyleSet-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<BehaviorStyleSet-response> is deprecated: use icra_roboin_msgs-srv:BehaviorStyleSet-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <BehaviorStyleSet-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'info-val :lambda-list '(m))
(cl:defmethod info-val ((m <BehaviorStyleSet-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:info-val is deprecated.  Use icra_roboin_msgs-srv:info instead.")
  (info m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BehaviorStyleSet-response>) ostream)
  "Serializes a message object of type '<BehaviorStyleSet-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'info)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BehaviorStyleSet-response>) istream)
  "Deserializes a message object of type '<BehaviorStyleSet-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'info) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BehaviorStyleSet-response>)))
  "Returns string type for a service object of type '<BehaviorStyleSet-response>"
  "icra_roboin_msgs/BehaviorStyleSetResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BehaviorStyleSet-response)))
  "Returns string type for a service object of type 'BehaviorStyleSet-response"
  "icra_roboin_msgs/BehaviorStyleSetResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BehaviorStyleSet-response>)))
  "Returns md5sum for a message object of type '<BehaviorStyleSet-response>"
  "55497cc3dd55c5632392e3da32c9b591")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BehaviorStyleSet-response)))
  "Returns md5sum for a message object of type 'BehaviorStyleSet-response"
  "55497cc3dd55c5632392e3da32c9b591")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BehaviorStyleSet-response>)))
  "Returns full string definition for message of type '<BehaviorStyleSet-response>"
  (cl:format cl:nil "bool success~%int16 info~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BehaviorStyleSet-response)))
  "Returns full string definition for message of type 'BehaviorStyleSet-response"
  (cl:format cl:nil "bool success~%int16 info~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BehaviorStyleSet-response>))
  (cl:+ 0
     1
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BehaviorStyleSet-response>))
  "Converts a ROS message object to a list"
  (cl:list 'BehaviorStyleSet-response
    (cl:cons ':success (success msg))
    (cl:cons ':info (info msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'BehaviorStyleSet)))
  'BehaviorStyleSet-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'BehaviorStyleSet)))
  'BehaviorStyleSet-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BehaviorStyleSet)))
  "Returns string type for a service object of type '<BehaviorStyleSet>"
  "icra_roboin_msgs/BehaviorStyleSet")