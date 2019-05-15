; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude ConfirmHit-request.msg.html

(cl:defclass <ConfirmHit-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass ConfirmHit-request (<ConfirmHit-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ConfirmHit-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ConfirmHit-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<ConfirmHit-request> is deprecated: use icra_roboin_msgs-srv:ConfirmHit-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ConfirmHit-request>) ostream)
  "Serializes a message object of type '<ConfirmHit-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ConfirmHit-request>) istream)
  "Deserializes a message object of type '<ConfirmHit-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ConfirmHit-request>)))
  "Returns string type for a service object of type '<ConfirmHit-request>"
  "icra_roboin_msgs/ConfirmHitRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ConfirmHit-request)))
  "Returns string type for a service object of type 'ConfirmHit-request"
  "icra_roboin_msgs/ConfirmHitRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ConfirmHit-request>)))
  "Returns md5sum for a message object of type '<ConfirmHit-request>"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ConfirmHit-request)))
  "Returns md5sum for a message object of type 'ConfirmHit-request"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ConfirmHit-request>)))
  "Returns full string definition for message of type '<ConfirmHit-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ConfirmHit-request)))
  "Returns full string definition for message of type 'ConfirmHit-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ConfirmHit-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ConfirmHit-request>))
  "Converts a ROS message object to a list"
  (cl:list 'ConfirmHit-request
))
;//! \htmlinclude ConfirmHit-response.msg.html

(cl:defclass <ConfirmHit-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ConfirmHit-response (<ConfirmHit-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ConfirmHit-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ConfirmHit-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<ConfirmHit-response> is deprecated: use icra_roboin_msgs-srv:ConfirmHit-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <ConfirmHit-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:success-val is deprecated.  Use icra_roboin_msgs-srv:success instead.")
  (success m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ConfirmHit-response>) ostream)
  "Serializes a message object of type '<ConfirmHit-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ConfirmHit-response>) istream)
  "Deserializes a message object of type '<ConfirmHit-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ConfirmHit-response>)))
  "Returns string type for a service object of type '<ConfirmHit-response>"
  "icra_roboin_msgs/ConfirmHitResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ConfirmHit-response)))
  "Returns string type for a service object of type 'ConfirmHit-response"
  "icra_roboin_msgs/ConfirmHitResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ConfirmHit-response>)))
  "Returns md5sum for a message object of type '<ConfirmHit-response>"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ConfirmHit-response)))
  "Returns md5sum for a message object of type 'ConfirmHit-response"
  "358e233cde0c8a8bcfea4ce193f8fc15")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ConfirmHit-response>)))
  "Returns full string definition for message of type '<ConfirmHit-response>"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ConfirmHit-response)))
  "Returns full string definition for message of type 'ConfirmHit-response"
  (cl:format cl:nil "bool success~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ConfirmHit-response>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ConfirmHit-response>))
  "Converts a ROS message object to a list"
  (cl:list 'ConfirmHit-response
    (cl:cons ':success (success msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'ConfirmHit)))
  'ConfirmHit-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'ConfirmHit)))
  'ConfirmHit-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ConfirmHit)))
  "Returns string type for a service object of type '<ConfirmHit>"
  "icra_roboin_msgs/ConfirmHit")