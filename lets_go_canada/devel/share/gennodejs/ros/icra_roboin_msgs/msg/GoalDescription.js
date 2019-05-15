// Auto-generated. Do not edit!

// (in-package icra_roboin_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class GoalDescription {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.x = null;
      this.y = null;
      this.yaw = null;
      this.xa = null;
      this.ya = null;
      this.yawa = null;
      this.etc = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('yaw')) {
        this.yaw = initObj.yaw
      }
      else {
        this.yaw = 0.0;
      }
      if (initObj.hasOwnProperty('xa')) {
        this.xa = initObj.xa
      }
      else {
        this.xa = 0.0;
      }
      if (initObj.hasOwnProperty('ya')) {
        this.ya = initObj.ya
      }
      else {
        this.ya = 0.0;
      }
      if (initObj.hasOwnProperty('yawa')) {
        this.yawa = initObj.yawa
      }
      else {
        this.yawa = 0.0;
      }
      if (initObj.hasOwnProperty('etc')) {
        this.etc = initObj.etc
      }
      else {
        this.etc = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GoalDescription
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [yaw]
    bufferOffset = _serializer.float64(obj.yaw, buffer, bufferOffset);
    // Serialize message field [xa]
    bufferOffset = _serializer.float64(obj.xa, buffer, bufferOffset);
    // Serialize message field [ya]
    bufferOffset = _serializer.float64(obj.ya, buffer, bufferOffset);
    // Serialize message field [yawa]
    bufferOffset = _serializer.float64(obj.yawa, buffer, bufferOffset);
    // Serialize message field [etc]
    bufferOffset = _serializer.float64(obj.etc, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GoalDescription
    let len;
    let data = new GoalDescription(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yaw]
    data.yaw = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [xa]
    data.xa = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ya]
    data.ya = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [yawa]
    data.yawa = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [etc]
    data.etc = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 56;
  }

  static datatype() {
    // Returns string type for a message object
    return 'icra_roboin_msgs/GoalDescription';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '245d250014695050d5f8815bfc401e15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new GoalDescription(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.yaw !== undefined) {
      resolved.yaw = msg.yaw;
    }
    else {
      resolved.yaw = 0.0
    }

    if (msg.xa !== undefined) {
      resolved.xa = msg.xa;
    }
    else {
      resolved.xa = 0.0
    }

    if (msg.ya !== undefined) {
      resolved.ya = msg.ya;
    }
    else {
      resolved.ya = 0.0
    }

    if (msg.yawa !== undefined) {
      resolved.yawa = msg.yawa;
    }
    else {
      resolved.yawa = 0.0
    }

    if (msg.etc !== undefined) {
      resolved.etc = msg.etc;
    }
    else {
      resolved.etc = 0.0
    }

    return resolved;
    }
};

module.exports = GoalDescription;
