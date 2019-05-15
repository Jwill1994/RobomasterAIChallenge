// Auto-generated. Do not edit!

// (in-package icra_roboin_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------


//-----------------------------------------------------------

class RefereeHitRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.damage = null;
      this.your_hp = null;
      this.which_armor = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('damage')) {
        this.damage = initObj.damage
      }
      else {
        this.damage = 0;
      }
      if (initObj.hasOwnProperty('your_hp')) {
        this.your_hp = initObj.your_hp
      }
      else {
        this.your_hp = 0;
      }
      if (initObj.hasOwnProperty('which_armor')) {
        this.which_armor = initObj.which_armor
      }
      else {
        this.which_armor = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RefereeHitRequest
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [damage]
    bufferOffset = _serializer.int16(obj.damage, buffer, bufferOffset);
    // Serialize message field [your_hp]
    bufferOffset = _serializer.int16(obj.your_hp, buffer, bufferOffset);
    // Serialize message field [which_armor]
    bufferOffset = _serializer.uint8(obj.which_armor, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RefereeHitRequest
    let len;
    let data = new RefereeHitRequest(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [damage]
    data.damage = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [your_hp]
    data.your_hp = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [which_armor]
    data.which_armor = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/RefereeHitRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'f1f02b3a3464db1f137d3ed01d8a1b55';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    int16 damage
    int16 your_hp
    
    uint8 which_armor
    
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
    const resolved = new RefereeHitRequest(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.damage !== undefined) {
      resolved.damage = msg.damage;
    }
    else {
      resolved.damage = 0
    }

    if (msg.your_hp !== undefined) {
      resolved.your_hp = msg.your_hp;
    }
    else {
      resolved.your_hp = 0
    }

    if (msg.which_armor !== undefined) {
      resolved.which_armor = msg.which_armor;
    }
    else {
      resolved.which_armor = 0
    }

    return resolved;
    }
};

class RefereeHitResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RefereeHitResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RefereeHitResponse
    let len;
    let data = new RefereeHitResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/RefereeHitResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RefereeHitResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: RefereeHitRequest,
  Response: RefereeHitResponse,
  md5sum() { return 'f2c65d4bc3ae1c76b3e2a29cb052e810'; },
  datatype() { return 'icra_roboin_msgs/RefereeHit'; }
};
