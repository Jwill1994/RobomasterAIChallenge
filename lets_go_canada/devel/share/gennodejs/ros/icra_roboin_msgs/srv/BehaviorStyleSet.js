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


//-----------------------------------------------------------

class BehaviorStyleSetRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.behavior = null;
    }
    else {
      if (initObj.hasOwnProperty('behavior')) {
        this.behavior = initObj.behavior
      }
      else {
        this.behavior = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type BehaviorStyleSetRequest
    // Serialize message field [behavior]
    bufferOffset = _serializer.uint8(obj.behavior, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BehaviorStyleSetRequest
    let len;
    let data = new BehaviorStyleSetRequest(null);
    // Deserialize message field [behavior]
    data.behavior = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/BehaviorStyleSetRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '736276b219b2f8e79cd33bbc21236ebd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 behavior
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BehaviorStyleSetRequest(null);
    if (msg.behavior !== undefined) {
      resolved.behavior = msg.behavior;
    }
    else {
      resolved.behavior = 0
    }

    return resolved;
    }
};

class BehaviorStyleSetResponse {
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
    // Serializes a message object of type BehaviorStyleSetResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [info]
    bufferOffset = _serializer.int16(obj.info, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type BehaviorStyleSetResponse
    let len;
    let data = new BehaviorStyleSetResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [info]
    data.info = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 3;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/BehaviorStyleSetResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'fcba3408348f94308a5f17200fcdd9f0';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    int16 info
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new BehaviorStyleSetResponse(null);
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
  Request: BehaviorStyleSetRequest,
  Response: BehaviorStyleSetResponse,
  md5sum() { return '55497cc3dd55c5632392e3da32c9b591'; },
  datatype() { return 'icra_roboin_msgs/BehaviorStyleSet'; }
};
