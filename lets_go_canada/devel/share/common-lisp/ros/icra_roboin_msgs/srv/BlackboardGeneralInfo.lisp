; Auto-generated. Do not edit!


(cl:in-package icra_roboin_msgs-srv)


;//! \htmlinclude BlackboardGeneralInfo-request.msg.html

(cl:defclass <BlackboardGeneralInfo-request> (roslisp-msg-protocol:ros-message)
  ((stamp
    :reader stamp
    :initarg :stamp
    :type cl:real
    :initform 0)
   (request_sender
    :reader request_sender
    :initarg :request_sender
    :type cl:string
    :initform "")
   (confirm
    :reader confirm
    :initarg :confirm
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass BlackboardGeneralInfo-request (<BlackboardGeneralInfo-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BlackboardGeneralInfo-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BlackboardGeneralInfo-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<BlackboardGeneralInfo-request> is deprecated: use icra_roboin_msgs-srv:BlackboardGeneralInfo-request instead.")))

(cl:ensure-generic-function 'stamp-val :lambda-list '(m))
(cl:defmethod stamp-val ((m <BlackboardGeneralInfo-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:stamp-val is deprecated.  Use icra_roboin_msgs-srv:stamp instead.")
  (stamp m))

(cl:ensure-generic-function 'request_sender-val :lambda-list '(m))
(cl:defmethod request_sender-val ((m <BlackboardGeneralInfo-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:request_sender-val is deprecated.  Use icra_roboin_msgs-srv:request_sender instead.")
  (request_sender m))

(cl:ensure-generic-function 'confirm-val :lambda-list '(m))
(cl:defmethod confirm-val ((m <BlackboardGeneralInfo-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:confirm-val is deprecated.  Use icra_roboin_msgs-srv:confirm instead.")
  (confirm m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BlackboardGeneralInfo-request>) ostream)
  "Serializes a message object of type '<BlackboardGeneralInfo-request>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stamp) (cl:floor (cl:slot-value msg 'stamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'request_sender))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'request_sender))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'confirm) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BlackboardGeneralInfo-request>) istream)
  "Deserializes a message object of type '<BlackboardGeneralInfo-request>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'request_sender) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'request_sender) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:slot-value msg 'confirm) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BlackboardGeneralInfo-request>)))
  "Returns string type for a service object of type '<BlackboardGeneralInfo-request>"
  "icra_roboin_msgs/BlackboardGeneralInfoRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BlackboardGeneralInfo-request)))
  "Returns string type for a service object of type 'BlackboardGeneralInfo-request"
  "icra_roboin_msgs/BlackboardGeneralInfoRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BlackboardGeneralInfo-request>)))
  "Returns md5sum for a message object of type '<BlackboardGeneralInfo-request>"
  "194169ae9786a8ee22311fb734602f60")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BlackboardGeneralInfo-request)))
  "Returns md5sum for a message object of type 'BlackboardGeneralInfo-request"
  "194169ae9786a8ee22311fb734602f60")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BlackboardGeneralInfo-request>)))
  "Returns full string definition for message of type '<BlackboardGeneralInfo-request>"
  (cl:format cl:nil "time stamp~%string request_sender~%bool confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BlackboardGeneralInfo-request)))
  "Returns full string definition for message of type 'BlackboardGeneralInfo-request"
  (cl:format cl:nil "time stamp~%string request_sender~%bool confirm~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BlackboardGeneralInfo-request>))
  (cl:+ 0
     8
     4 (cl:length (cl:slot-value msg 'request_sender))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BlackboardGeneralInfo-request>))
  "Converts a ROS message object to a list"
  (cl:list 'BlackboardGeneralInfo-request
    (cl:cons ':stamp (stamp msg))
    (cl:cons ':request_sender (request_sender msg))
    (cl:cons ':confirm (confirm msg))
))
;//! \htmlinclude BlackboardGeneralInfo-response.msg.html

(cl:defclass <BlackboardGeneralInfo-response> (roslisp-msg-protocol:ros-message)
  ((stamp
    :reader stamp
    :initarg :stamp
    :type cl:real
    :initform 0)
   (time_passed_from_start
    :reader time_passed_from_start
    :initarg :time_passed_from_start
    :type cl:integer
    :initform 0)
   (game_state
    :reader game_state
    :initarg :game_state
    :type cl:fixnum
    :initform 0)
   (buff_zone_cooltime
    :reader buff_zone_cooltime
    :initarg :buff_zone_cooltime
    :type cl:integer
    :initform 0)
   (reload_zone_cooltime
    :reader reload_zone_cooltime
    :initarg :reload_zone_cooltime
    :type cl:integer
    :initform 0)
   (my_health
    :reader my_health
    :initarg :my_health
    :type cl:fixnum
    :initform 0)
   (is_hit
    :reader is_hit
    :initarg :is_hit
    :type cl:boolean
    :initform cl:nil)
   (which_armor_hit
    :reader which_armor_hit
    :initarg :which_armor_hit
    :type cl:fixnum
    :initform 0)
   (last_hit_time
    :reader last_hit_time
    :initarg :last_hit_time
    :type cl:integer
    :initform 0)
   (has_buff
    :reader has_buff
    :initarg :has_buff
    :type cl:boolean
    :initform cl:nil)
   (buff_left
    :reader buff_left
    :initarg :buff_left
    :type cl:integer
    :initform 0)
   (ammo
    :reader ammo
    :initarg :ammo
    :type cl:fixnum
    :initform 0)
   (my_pose
    :reader my_pose
    :initarg :my_pose
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped))
   (enemy_pose1
    :reader enemy_pose1
    :initarg :enemy_pose1
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped))
   (enemy_pose2
    :reader enemy_pose2
    :initarg :enemy_pose2
    :type geometry_msgs-msg:PoseStamped
    :initform (cl:make-instance 'geometry_msgs-msg:PoseStamped))
   (how_many_enemies_detected
    :reader how_many_enemies_detected
    :initarg :how_many_enemies_detected
    :type cl:fixnum
    :initform 0)
   (is_enemy_1_detected
    :reader is_enemy_1_detected
    :initarg :is_enemy_1_detected
    :type cl:boolean
    :initform cl:nil)
   (is_enemy_2_detected
    :reader is_enemy_2_detected
    :initarg :is_enemy_2_detected
    :type cl:boolean
    :initform cl:nil)
   (locked_on_enemy
    :reader locked_on_enemy
    :initarg :locked_on_enemy
    :type cl:fixnum
    :initform 0)
   (enemy_priority
    :reader enemy_priority
    :initarg :enemy_priority
    :type cl:fixnum
    :initform 0)
   (goal
    :reader goal
    :initarg :goal
    :type icra_roboin_msgs-msg:GoalDescription
    :initform (cl:make-instance 'icra_roboin_msgs-msg:GoalDescription))
   (current_behavior_style
    :reader current_behavior_style
    :initarg :current_behavior_style
    :type cl:fixnum
    :initform 0)
   (current_behavior_process
    :reader current_behavior_process
    :initarg :current_behavior_process
    :type cl:fixnum
    :initform 0))
)

(cl:defclass BlackboardGeneralInfo-response (<BlackboardGeneralInfo-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BlackboardGeneralInfo-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BlackboardGeneralInfo-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name icra_roboin_msgs-srv:<BlackboardGeneralInfo-response> is deprecated: use icra_roboin_msgs-srv:BlackboardGeneralInfo-response instead.")))

(cl:ensure-generic-function 'stamp-val :lambda-list '(m))
(cl:defmethod stamp-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:stamp-val is deprecated.  Use icra_roboin_msgs-srv:stamp instead.")
  (stamp m))

(cl:ensure-generic-function 'time_passed_from_start-val :lambda-list '(m))
(cl:defmethod time_passed_from_start-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:time_passed_from_start-val is deprecated.  Use icra_roboin_msgs-srv:time_passed_from_start instead.")
  (time_passed_from_start m))

(cl:ensure-generic-function 'game_state-val :lambda-list '(m))
(cl:defmethod game_state-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:game_state-val is deprecated.  Use icra_roboin_msgs-srv:game_state instead.")
  (game_state m))

(cl:ensure-generic-function 'buff_zone_cooltime-val :lambda-list '(m))
(cl:defmethod buff_zone_cooltime-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:buff_zone_cooltime-val is deprecated.  Use icra_roboin_msgs-srv:buff_zone_cooltime instead.")
  (buff_zone_cooltime m))

(cl:ensure-generic-function 'reload_zone_cooltime-val :lambda-list '(m))
(cl:defmethod reload_zone_cooltime-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:reload_zone_cooltime-val is deprecated.  Use icra_roboin_msgs-srv:reload_zone_cooltime instead.")
  (reload_zone_cooltime m))

(cl:ensure-generic-function 'my_health-val :lambda-list '(m))
(cl:defmethod my_health-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:my_health-val is deprecated.  Use icra_roboin_msgs-srv:my_health instead.")
  (my_health m))

(cl:ensure-generic-function 'is_hit-val :lambda-list '(m))
(cl:defmethod is_hit-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:is_hit-val is deprecated.  Use icra_roboin_msgs-srv:is_hit instead.")
  (is_hit m))

(cl:ensure-generic-function 'which_armor_hit-val :lambda-list '(m))
(cl:defmethod which_armor_hit-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:which_armor_hit-val is deprecated.  Use icra_roboin_msgs-srv:which_armor_hit instead.")
  (which_armor_hit m))

(cl:ensure-generic-function 'last_hit_time-val :lambda-list '(m))
(cl:defmethod last_hit_time-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:last_hit_time-val is deprecated.  Use icra_roboin_msgs-srv:last_hit_time instead.")
  (last_hit_time m))

(cl:ensure-generic-function 'has_buff-val :lambda-list '(m))
(cl:defmethod has_buff-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:has_buff-val is deprecated.  Use icra_roboin_msgs-srv:has_buff instead.")
  (has_buff m))

(cl:ensure-generic-function 'buff_left-val :lambda-list '(m))
(cl:defmethod buff_left-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:buff_left-val is deprecated.  Use icra_roboin_msgs-srv:buff_left instead.")
  (buff_left m))

(cl:ensure-generic-function 'ammo-val :lambda-list '(m))
(cl:defmethod ammo-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:ammo-val is deprecated.  Use icra_roboin_msgs-srv:ammo instead.")
  (ammo m))

(cl:ensure-generic-function 'my_pose-val :lambda-list '(m))
(cl:defmethod my_pose-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:my_pose-val is deprecated.  Use icra_roboin_msgs-srv:my_pose instead.")
  (my_pose m))

(cl:ensure-generic-function 'enemy_pose1-val :lambda-list '(m))
(cl:defmethod enemy_pose1-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:enemy_pose1-val is deprecated.  Use icra_roboin_msgs-srv:enemy_pose1 instead.")
  (enemy_pose1 m))

(cl:ensure-generic-function 'enemy_pose2-val :lambda-list '(m))
(cl:defmethod enemy_pose2-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:enemy_pose2-val is deprecated.  Use icra_roboin_msgs-srv:enemy_pose2 instead.")
  (enemy_pose2 m))

(cl:ensure-generic-function 'how_many_enemies_detected-val :lambda-list '(m))
(cl:defmethod how_many_enemies_detected-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:how_many_enemies_detected-val is deprecated.  Use icra_roboin_msgs-srv:how_many_enemies_detected instead.")
  (how_many_enemies_detected m))

(cl:ensure-generic-function 'is_enemy_1_detected-val :lambda-list '(m))
(cl:defmethod is_enemy_1_detected-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:is_enemy_1_detected-val is deprecated.  Use icra_roboin_msgs-srv:is_enemy_1_detected instead.")
  (is_enemy_1_detected m))

(cl:ensure-generic-function 'is_enemy_2_detected-val :lambda-list '(m))
(cl:defmethod is_enemy_2_detected-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:is_enemy_2_detected-val is deprecated.  Use icra_roboin_msgs-srv:is_enemy_2_detected instead.")
  (is_enemy_2_detected m))

(cl:ensure-generic-function 'locked_on_enemy-val :lambda-list '(m))
(cl:defmethod locked_on_enemy-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:locked_on_enemy-val is deprecated.  Use icra_roboin_msgs-srv:locked_on_enemy instead.")
  (locked_on_enemy m))

(cl:ensure-generic-function 'enemy_priority-val :lambda-list '(m))
(cl:defmethod enemy_priority-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:enemy_priority-val is deprecated.  Use icra_roboin_msgs-srv:enemy_priority instead.")
  (enemy_priority m))

(cl:ensure-generic-function 'goal-val :lambda-list '(m))
(cl:defmethod goal-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:goal-val is deprecated.  Use icra_roboin_msgs-srv:goal instead.")
  (goal m))

(cl:ensure-generic-function 'current_behavior_style-val :lambda-list '(m))
(cl:defmethod current_behavior_style-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:current_behavior_style-val is deprecated.  Use icra_roboin_msgs-srv:current_behavior_style instead.")
  (current_behavior_style m))

(cl:ensure-generic-function 'current_behavior_process-val :lambda-list '(m))
(cl:defmethod current_behavior_process-val ((m <BlackboardGeneralInfo-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader icra_roboin_msgs-srv:current_behavior_process-val is deprecated.  Use icra_roboin_msgs-srv:current_behavior_process instead.")
  (current_behavior_process m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BlackboardGeneralInfo-response>) ostream)
  "Serializes a message object of type '<BlackboardGeneralInfo-response>"
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'stamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'stamp) (cl:floor (cl:slot-value msg 'stamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let* ((signed (cl:slot-value msg 'time_passed_from_start)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'game_state)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'buff_zone_cooltime)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'reload_zone_cooltime)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'my_health)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_hit) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'which_armor_hit)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'last_hit_time)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'has_buff) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'buff_left)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'ammo)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'my_pose) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'enemy_pose1) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'enemy_pose2) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'how_many_enemies_detected)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_enemy_1_detected) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'is_enemy_2_detected) 1 0)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'locked_on_enemy)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'enemy_priority)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'goal) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_behavior_style)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_behavior_process)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BlackboardGeneralInfo-response>) istream)
  "Deserializes a message object of type '<BlackboardGeneralInfo-response>"
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'stamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'time_passed_from_start) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'game_state)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'buff_zone_cooltime) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'reload_zone_cooltime) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'my_health) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:slot-value msg 'is_hit) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'which_armor_hit)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'last_hit_time) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:setf (cl:slot-value msg 'has_buff) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'buff_left) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ammo) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'my_pose) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'enemy_pose1) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'enemy_pose2) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'how_many_enemies_detected)) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'is_enemy_1_detected) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:slot-value msg 'is_enemy_2_detected) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'locked_on_enemy)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'enemy_priority)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'goal) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_behavior_style)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_behavior_process)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BlackboardGeneralInfo-response>)))
  "Returns string type for a service object of type '<BlackboardGeneralInfo-response>"
  "icra_roboin_msgs/BlackboardGeneralInfoResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BlackboardGeneralInfo-response)))
  "Returns string type for a service object of type 'BlackboardGeneralInfo-response"
  "icra_roboin_msgs/BlackboardGeneralInfoResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BlackboardGeneralInfo-response>)))
  "Returns md5sum for a message object of type '<BlackboardGeneralInfo-response>"
  "194169ae9786a8ee22311fb734602f60")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BlackboardGeneralInfo-response)))
  "Returns md5sum for a message object of type 'BlackboardGeneralInfo-response"
  "194169ae9786a8ee22311fb734602f60")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BlackboardGeneralInfo-response>)))
  "Returns full string definition for message of type '<BlackboardGeneralInfo-response>"
  (cl:format cl:nil "time stamp~%int32 time_passed_from_start~%~%uint8 game_state~%int32 buff_zone_cooltime~%int32 reload_zone_cooltime~%int16 my_health~%bool is_hit~%uint8 which_armor_hit~%int32 last_hit_time~%bool has_buff~%int32 buff_left~%int16 ammo~%geometry_msgs/PoseStamped my_pose~%geometry_msgs/PoseStamped enemy_pose1~%geometry_msgs/PoseStamped enemy_pose2~%uint8 how_many_enemies_detected~%bool is_enemy_1_detected~%bool is_enemy_2_detected~%uint8 locked_on_enemy~%uint8 enemy_priority~%icra_roboin_msgs/GoalDescription goal~%uint8 current_behavior_style~%uint8 current_behavior_process~%~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: icra_roboin_msgs/GoalDescription~%std_msgs/Header header~%float64 x~%float64 y~%float64 yaw~%float64 xa~%float64 ya~%float64 yawa~%float64 etc~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BlackboardGeneralInfo-response)))
  "Returns full string definition for message of type 'BlackboardGeneralInfo-response"
  (cl:format cl:nil "time stamp~%int32 time_passed_from_start~%~%uint8 game_state~%int32 buff_zone_cooltime~%int32 reload_zone_cooltime~%int16 my_health~%bool is_hit~%uint8 which_armor_hit~%int32 last_hit_time~%bool has_buff~%int32 buff_left~%int16 ammo~%geometry_msgs/PoseStamped my_pose~%geometry_msgs/PoseStamped enemy_pose1~%geometry_msgs/PoseStamped enemy_pose2~%uint8 how_many_enemies_detected~%bool is_enemy_1_detected~%bool is_enemy_2_detected~%uint8 locked_on_enemy~%uint8 enemy_priority~%icra_roboin_msgs/GoalDescription goal~%uint8 current_behavior_style~%uint8 current_behavior_process~%~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: icra_roboin_msgs/GoalDescription~%std_msgs/Header header~%float64 x~%float64 y~%float64 yaw~%float64 xa~%float64 ya~%float64 yawa~%float64 etc~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BlackboardGeneralInfo-response>))
  (cl:+ 0
     8
     4
     1
     4
     4
     2
     1
     1
     4
     1
     4
     2
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'my_pose))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'enemy_pose1))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'enemy_pose2))
     1
     1
     1
     1
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'goal))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BlackboardGeneralInfo-response>))
  "Converts a ROS message object to a list"
  (cl:list 'BlackboardGeneralInfo-response
    (cl:cons ':stamp (stamp msg))
    (cl:cons ':time_passed_from_start (time_passed_from_start msg))
    (cl:cons ':game_state (game_state msg))
    (cl:cons ':buff_zone_cooltime (buff_zone_cooltime msg))
    (cl:cons ':reload_zone_cooltime (reload_zone_cooltime msg))
    (cl:cons ':my_health (my_health msg))
    (cl:cons ':is_hit (is_hit msg))
    (cl:cons ':which_armor_hit (which_armor_hit msg))
    (cl:cons ':last_hit_time (last_hit_time msg))
    (cl:cons ':has_buff (has_buff msg))
    (cl:cons ':buff_left (buff_left msg))
    (cl:cons ':ammo (ammo msg))
    (cl:cons ':my_pose (my_pose msg))
    (cl:cons ':enemy_pose1 (enemy_pose1 msg))
    (cl:cons ':enemy_pose2 (enemy_pose2 msg))
    (cl:cons ':how_many_enemies_detected (how_many_enemies_detected msg))
    (cl:cons ':is_enemy_1_detected (is_enemy_1_detected msg))
    (cl:cons ':is_enemy_2_detected (is_enemy_2_detected msg))
    (cl:cons ':locked_on_enemy (locked_on_enemy msg))
    (cl:cons ':enemy_priority (enemy_priority msg))
    (cl:cons ':goal (goal msg))
    (cl:cons ':current_behavior_style (current_behavior_style msg))
    (cl:cons ':current_behavior_process (current_behavior_process msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'BlackboardGeneralInfo)))
  'BlackboardGeneralInfo-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'BlackboardGeneralInfo)))
  'BlackboardGeneralInfo-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BlackboardGeneralInfo)))
  "Returns string type for a service object of type '<BlackboardGeneralInfo>"
  "icra_roboin_msgs/BlackboardGeneralInfo")