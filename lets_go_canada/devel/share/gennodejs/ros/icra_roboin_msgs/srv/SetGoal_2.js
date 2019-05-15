// Auto-generated. Do not edit!

// (in-package icra_roboin_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let GoalDescription = require('../msg/GoalDescription.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class SetGoal_2Request {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.goal = null;
    }
    else {
      if (initObj.hasOwnProperty('goal')) {
        this.goal = initObj.goal
      }
      else {
        this.goal = new GoalDescription();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetGoal_2Request
    // Serialize message field [goal]
    bufferOffset = GoalDescription.serialize(obj.goal, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetGoal_2Request
    let len;
    let data = new SetGoal_2Request(null);
    // Deserialize message field [goal]
    data.goal = GoalDescription.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += GoalDescription.getMessageSize(object.goal);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/SetGoal_2Request';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0b503641e6c15140727658d31ee49db3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    icra_roboin_msgs/GoalDescription goal
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetGoal_2Request(null);
    if (msg.goal !== undefined) {
      resolved.goal = GoalDescription.Resolve(msg.goal)
    }
    else {
      resolved.goal = new GoalDescription()
    }

    return resolved;
    }
};

class SetGoal_2Response {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
      this.info = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
      if (initObj.hasOwnProperty('info')) {
        this.info = initObj.info
      }
      else {
        this.info = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetGoal_2Response
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [info]
    bufferOffset = _serializer.int64(obj.info, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetGoal_2Response
    let len;
    let data = new SetGoal_2Response(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [info]
    data.info = _deserializer.int64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 9;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/SetGoal_2Response';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'a07e602d7d93fc4ad25d4e1a75f0edf5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    int64 info
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetGoal_2Response(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    if (msg.info !== undefined) {
      resolved.info = msg.info;
    }
    else {
      resolved.info = 0
    }

    return resolved;
    }
};

module.exports = {
  Request: SetGoal_2Request,
  Response: SetGoal_2Response,
  md5sum() { return '3adb4c2d2dfadd29c140f6e5796b855e'; },
  datatype() { return 'icra_roboin_msgs/SetGoal_2'; }
};
