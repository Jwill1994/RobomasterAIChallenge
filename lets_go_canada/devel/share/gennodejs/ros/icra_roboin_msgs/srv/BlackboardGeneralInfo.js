// Auto-generated. Do not edit!

// (in-package icra_roboin_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

let GoalDescription = require('../msg/GoalDescription.js');
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class BlackboardGeneralInfoRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stamp = null;
      this.request_sender = null;
      this.confirm = null;
    }
    else {
      if (initObj.hasOwnProperty('stamp')) {
        this.stamp = initObj.stamp
      }
      else {
        this.stamp = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('request_sender')) {
        this.request_sender = initObj.request_sender
      }
      else {
        this.request_sender = '';
      }
      if (initObj.hasOwnProperty('confirm')) {
        this.confirm = initObj.confirm
      }
      else {
        this.confirm = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type BlackboardGeneralInfoRequest
    // Serialize message field [stamp]
    bufferOffset = _serializer.time(obj.stamp, buffer, bufferOffset);
    // Serialize message field [request_sender]
    bufferOffset = _serializer.string(obj.request_sender, buffer, bufferOffset);
    // Serialize message field [confirm]
    bufferOffset = _serializer.bool(obj.confirm, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BlackboardGeneralInfoRequest
    let len;
    let data = new BlackboardGeneralInfoRequest(null);
    // Deserialize message field [stamp]
    data.stamp = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [request_sender]
    data.request_sender = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [confirm]
    data.confirm = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.request_sender.length;
    return length + 13;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/BlackboardGeneralInfoRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '66a57ffbb7b0191a46e5cac0c5adf55b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    time stamp
    string request_sender
    bool confirm
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BlackboardGeneralInfoRequest(null);
    if (msg.stamp !== undefined) {
      resolved.stamp = msg.stamp;
    }
    else {
      resolved.stamp = {secs: 0, nsecs: 0}
    }

    if (msg.request_sender !== undefined) {
      resolved.request_sender = msg.request_sender;
    }
    else {
      resolved.request_sender = ''
    }

    if (msg.confirm !== undefined) {
      resolved.confirm = msg.confirm;
    }
    else {
      resolved.confirm = false
    }

    return resolved;
    }
};

class BlackboardGeneralInfoResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.stamp = null;
      this.time_passed_from_start = null;
      this.game_state = null;
      this.buff_zone_cooltime = null;
      this.reload_zone_cooltime = null;
      this.my_health = null;
      this.is_hit = null;
      this.which_armor_hit = null;
      this.last_hit_time = null;
      this.has_buff = null;
      this.buff_left = null;
      this.ammo = null;
      this.my_pose = null;
      this.enemy_pose1 = null;
      this.enemy_pose2 = null;
      this.how_many_enemies_detected = null;
      this.is_enemy_1_detected = null;
      this.is_enemy_2_detected = null;
      this.locked_on_enemy = null;
      this.enemy_priority = null;
      this.goal = null;
      this.current_behavior_style = null;
      this.current_behavior_process = null;
    }
    else {
      if (initObj.hasOwnProperty('stamp')) {
        this.stamp = initObj.stamp
      }
      else {
        this.stamp = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('time_passed_from_start')) {
        this.time_passed_from_start = initObj.time_passed_from_start
      }
      else {
        this.time_passed_from_start = 0;
      }
      if (initObj.hasOwnProperty('game_state')) {
        this.game_state = initObj.game_state
      }
      else {
        this.game_state = 0;
      }
      if (initObj.hasOwnProperty('buff_zone_cooltime')) {
        this.buff_zone_cooltime = initObj.buff_zone_cooltime
      }
      else {
        this.buff_zone_cooltime = 0;
      }
      if (initObj.hasOwnProperty('reload_zone_cooltime')) {
        this.reload_zone_cooltime = initObj.reload_zone_cooltime
      }
      else {
        this.reload_zone_cooltime = 0;
      }
      if (initObj.hasOwnProperty('my_health')) {
        this.my_health = initObj.my_health
      }
      else {
        this.my_health = 0;
      }
      if (initObj.hasOwnProperty('is_hit')) {
        this.is_hit = initObj.is_hit
      }
      else {
        this.is_hit = false;
      }
      if (initObj.hasOwnProperty('which_armor_hit')) {
        this.which_armor_hit = initObj.which_armor_hit
      }
      else {
        this.which_armor_hit = 0;
      }
      if (initObj.hasOwnProperty('last_hit_time')) {
        this.last_hit_time = initObj.last_hit_time
      }
      else {
        this.last_hit_time = 0;
      }
      if (initObj.hasOwnProperty('has_buff')) {
        this.has_buff = initObj.has_buff
      }
      else {
        this.has_buff = false;
      }
      if (initObj.hasOwnProperty('buff_left')) {
        this.buff_left = initObj.buff_left
      }
      else {
        this.buff_left = 0;
      }
      if (initObj.hasOwnProperty('ammo')) {
        this.ammo = initObj.ammo
      }
      else {
        this.ammo = 0;
      }
      if (initObj.hasOwnProperty('my_pose')) {
        this.my_pose = initObj.my_pose
      }
      else {
        this.my_pose = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('enemy_pose1')) {
        this.enemy_pose1 = initObj.enemy_pose1
      }
      else {
        this.enemy_pose1 = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('enemy_pose2')) {
        this.enemy_pose2 = initObj.enemy_pose2
      }
      else {
        this.enemy_pose2 = new geometry_msgs.msg.PoseStamped();
      }
      if (initObj.hasOwnProperty('how_many_enemies_detected')) {
        this.how_many_enemies_detected = initObj.how_many_enemies_detected
      }
      else {
        this.how_many_enemies_detected = 0;
      }
      if (initObj.hasOwnProperty('is_enemy_1_detected')) {
        this.is_enemy_1_detected = initObj.is_enemy_1_detected
      }
      else {
        this.is_enemy_1_detected = false;
      }
      if (initObj.hasOwnProperty('is_enemy_2_detected')) {
        this.is_enemy_2_detected = initObj.is_enemy_2_detected
      }
      else {
        this.is_enemy_2_detected = false;
      }
      if (initObj.hasOwnProperty('locked_on_enemy')) {
        this.locked_on_enemy = initObj.locked_on_enemy
      }
      else {
        this.locked_on_enemy = 0;
      }
      if (initObj.hasOwnProperty('enemy_priority')) {
        this.enemy_priority = initObj.enemy_priority
      }
      else {
        this.enemy_priority = 0;
      }
      if (initObj.hasOwnProperty('goal')) {
        this.goal = initObj.goal
      }
      else {
        this.goal = new GoalDescription();
      }
      if (initObj.hasOwnProperty('current_behavior_style')) {
        this.current_behavior_style = initObj.current_behavior_style
      }
      else {
        this.current_behavior_style = 0;
      }
      if (initObj.hasOwnProperty('current_behavior_process')) {
        this.current_behavior_process = initObj.current_behavior_process
      }
      else {
        this.current_behavior_process = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type BlackboardGeneralInfoResponse
    // Serialize message field [stamp]
    bufferOffset = _serializer.time(obj.stamp, buffer, bufferOffset);
    // Serialize message field [time_passed_from_start]
    bufferOffset = _serializer.int32(obj.time_passed_from_start, buffer, bufferOffset);
    // Serialize message field [game_state]
    bufferOffset = _serializer.uint8(obj.game_state, buffer, bufferOffset);
    // Serialize message field [buff_zone_cooltime]
    bufferOffset = _serializer.int32(obj.buff_zone_cooltime, buffer, bufferOffset);
    // Serialize message field [reload_zone_cooltime]
    bufferOffset = _serializer.int32(obj.reload_zone_cooltime, buffer, bufferOffset);
    // Serialize message field [my_health]
    bufferOffset = _serializer.int16(obj.my_health, buffer, bufferOffset);
    // Serialize message field [is_hit]
    bufferOffset = _serializer.bool(obj.is_hit, buffer, bufferOffset);
    // Serialize message field [which_armor_hit]
    bufferOffset = _serializer.uint8(obj.which_armor_hit, buffer, bufferOffset);
    // Serialize message field [last_hit_time]
    bufferOffset = _serializer.int32(obj.last_hit_time, buffer, bufferOffset);
    // Serialize message field [has_buff]
    bufferOffset = _serializer.bool(obj.has_buff, buffer, bufferOffset);
    // Serialize message field [buff_left]
    bufferOffset = _serializer.int32(obj.buff_left, buffer, bufferOffset);
    // Serialize message field [ammo]
    bufferOffset = _serializer.int16(obj.ammo, buffer, bufferOffset);
    // Serialize message field [my_pose]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.my_pose, buffer, bufferOffset);
    // Serialize message field [enemy_pose1]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.enemy_pose1, buffer, bufferOffset);
    // Serialize message field [enemy_pose2]
    bufferOffset = geometry_msgs.msg.PoseStamped.serialize(obj.enemy_pose2, buffer, bufferOffset);
    // Serialize message field [how_many_enemies_detected]
    bufferOffset = _serializer.uint8(obj.how_many_enemies_detected, buffer, bufferOffset);
    // Serialize message field [is_enemy_1_detected]
    bufferOffset = _serializer.bool(obj.is_enemy_1_detected, buffer, bufferOffset);
    // Serialize message field [is_enemy_2_detected]
    bufferOffset = _serializer.bool(obj.is_enemy_2_detected, buffer, bufferOffset);
    // Serialize message field [locked_on_enemy]
    bufferOffset = _serializer.uint8(obj.locked_on_enemy, buffer, bufferOffset);
    // Serialize message field [enemy_priority]
    bufferOffset = _serializer.uint8(obj.enemy_priority, buffer, bufferOffset);
    // Serialize message field [goal]
    bufferOffset = GoalDescription.serialize(obj.goal, buffer, bufferOffset);
    // Serialize message field [current_behavior_style]
    bufferOffset = _serializer.uint8(obj.current_behavior_style, buffer, bufferOffset);
    // Serialize message field [current_behavior_process]
    bufferOffset = _serializer.uint8(obj.current_behavior_process, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BlackboardGeneralInfoResponse
    let len;
    let data = new BlackboardGeneralInfoResponse(null);
    // Deserialize message field [stamp]
    data.stamp = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [time_passed_from_start]
    data.time_passed_from_start = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [game_state]
    data.game_state = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [buff_zone_cooltime]
    data.buff_zone_cooltime = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [reload_zone_cooltime]
    data.reload_zone_cooltime = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [my_health]
    data.my_health = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [is_hit]
    data.is_hit = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [which_armor_hit]
    data.which_armor_hit = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [last_hit_time]
    data.last_hit_time = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [has_buff]
    data.has_buff = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [buff_left]
    data.buff_left = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [ammo]
    data.ammo = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [my_pose]
    data.my_pose = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [enemy_pose1]
    data.enemy_pose1 = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [enemy_pose2]
    data.enemy_pose2 = geometry_msgs.msg.PoseStamped.deserialize(buffer, bufferOffset);
    // Deserialize message field [how_many_enemies_detected]
    data.how_many_enemies_detected = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [is_enemy_1_detected]
    data.is_enemy_1_detected = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [is_enemy_2_detected]
    data.is_enemy_2_detected = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [locked_on_enemy]
    data.locked_on_enemy = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [enemy_priority]
    data.enemy_priority = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [goal]
    data.goal = GoalDescription.deserialize(buffer, bufferOffset);
    // Deserialize message field [current_behavior_style]
    data.current_behavior_style = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [current_behavior_process]
    data.current_behavior_process = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.my_pose);
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.enemy_pose1);
    length += geometry_msgs.msg.PoseStamped.getMessageSize(object.enemy_pose2);
    length += GoalDescription.getMessageSize(object.goal);
    return length + 43;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/BlackboardGeneralInfoResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '5a6420e2d73a3b280e9fbf108fe64e9e';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    time stamp
    int32 time_passed_from_start
    
    uint8 game_state
    int32 buff_zone_cooltime
    int32 reload_zone_cooltime
    int16 my_health
    bool is_hit
    uint8 which_armor_hit
    int32 last_hit_time
    bool has_buff
    int32 buff_left
    int16 ammo
    geometry_msgs/PoseStamped my_pose
    geometry_msgs/PoseStamped enemy_pose1
    geometry_msgs/PoseStamped enemy_pose2
    uint8 how_many_enemies_detected
    bool is_enemy_1_detected
    bool is_enemy_2_detected
    uint8 locked_on_enemy
    uint8 enemy_priority
    icra_roboin_msgs/GoalDescription goal
    uint8 current_behavior_style
    uint8 current_behavior_process
    
    
    ================================================================================
    MSG: geometry_msgs/PoseStamped
    # A Pose with reference coordinate frame and timestamp
    Header header
    Pose pose
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    # 0: no frame
    # 1: global frame
    string frame_id
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    ================================================================================
    MSG: icra_roboin_msgs/GoalDescription
    std_msgs/Header header
    float64 x
    float64 y
    float64 yaw
    float64 xa
    float64 ya
    float64 yawa
    float64 etc
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BlackboardGeneralInfoResponse(null);
    if (msg.stamp !== undefined) {
      resolved.stamp = msg.stamp;
    }
    else {
      resolved.stamp = {secs: 0, nsecs: 0}
    }

    if (msg.time_passed_from_start !== undefined) {
      resolved.time_passed_from_start = msg.time_passed_from_start;
    }
    else {
      resolved.time_passed_from_start = 0
    }

    if (msg.game_state !== undefined) {
      resolved.game_state = msg.game_state;
    }
    else {
      resolved.game_state = 0
    }

    if (msg.buff_zone_cooltime !== undefined) {
      resolved.buff_zone_cooltime = msg.buff_zone_cooltime;
    }
    else {
      resolved.buff_zone_cooltime = 0
    }

    if (msg.reload_zone_cooltime !== undefined) {
      resolved.reload_zone_cooltime = msg.reload_zone_cooltime;
    }
    else {
      resolved.reload_zone_cooltime = 0
    }

    if (msg.my_health !== undefined) {
      resolved.my_health = msg.my_health;
    }
    else {
      resolved.my_health = 0
    }

    if (msg.is_hit !== undefined) {
      resolved.is_hit = msg.is_hit;
    }
    else {
      resolved.is_hit = false
    }

    if (msg.which_armor_hit !== undefined) {
      resolved.which_armor_hit = msg.which_armor_hit;
    }
    else {
      resolved.which_armor_hit = 0
    }

    if (msg.last_hit_time !== undefined) {
      resolved.last_hit_time = msg.last_hit_time;
    }
    else {
      resolved.last_hit_time = 0
    }

    if (msg.has_buff !== undefined) {
      resolved.has_buff = msg.has_buff;
    }
    else {
      resolved.has_buff = false
    }

    if (msg.buff_left !== undefined) {
      resolved.buff_left = msg.buff_left;
    }
    else {
      resolved.buff_left = 0
    }

    if (msg.ammo !== undefined) {
      resolved.ammo = msg.ammo;
    }
    else {
      resolved.ammo = 0
    }

    if (msg.my_pose !== undefined) {
      resolved.my_pose = geometry_msgs.msg.PoseStamped.Resolve(msg.my_pose)
    }
    else {
      resolved.my_pose = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.enemy_pose1 !== undefined) {
      resolved.enemy_pose1 = geometry_msgs.msg.PoseStamped.Resolve(msg.enemy_pose1)
    }
    else {
      resolved.enemy_pose1 = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.enemy_pose2 !== undefined) {
      resolved.enemy_pose2 = geometry_msgs.msg.PoseStamped.Resolve(msg.enemy_pose2)
    }
    else {
      resolved.enemy_pose2 = new geometry_msgs.msg.PoseStamped()
    }

    if (msg.how_many_enemies_detected !== undefined) {
      resolved.how_many_enemies_detected = msg.how_many_enemies_detected;
    }
    else {
      resolved.how_many_enemies_detected = 0
    }

    if (msg.is_enemy_1_detected !== undefined) {
      resolved.is_enemy_1_detected = msg.is_enemy_1_detected;
    }
    else {
      resolved.is_enemy_1_detected = false
    }

    if (msg.is_enemy_2_detected !== undefined) {
      resolved.is_enemy_2_detected = msg.is_enemy_2_detected;
    }
    else {
      resolved.is_enemy_2_detected = false
    }

    if (msg.locked_on_enemy !== undefined) {
      resolved.locked_on_enemy = msg.locked_on_enemy;
    }
    else {
      resolved.locked_on_enemy = 0
    }

    if (msg.enemy_priority !== undefined) {
      resolved.enemy_priority = msg.enemy_priority;
    }
    else {
      resolved.enemy_priority = 0
    }

    if (msg.goal !== undefined) {
      resolved.goal = GoalDescription.Resolve(msg.goal)
    }
    else {
      resolved.goal = new GoalDescription()
    }

    if (msg.current_behavior_style !== undefined) {
      resolved.current_behavior_style = msg.current_behavior_style;
    }
    else {
      resolved.current_behavior_style = 0
    }

    if (msg.current_behavior_process !== undefined) {
      resolved.current_behavior_process = msg.current_behavior_process;
    }
    else {
      resolved.current_behavior_process = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: BlackboardGeneralInfoRequest,
  Response: BlackboardGeneralInfoResponse,
  md5sum() { return '194169ae9786a8ee22311fb734602f60'; },
  datatype() { return 'icra_roboin_msgs/BlackboardGeneralInfo'; }
};
