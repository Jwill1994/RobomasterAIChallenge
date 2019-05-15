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

class AmmoConsumeRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.shots = null;
    }
    else {
      if (initObj.hasOwnProperty('shots')) {
        this.shots = initObj.shots
      }
      else {
        this.shots = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type AmmoConsumeRequest
    // Serialize message field [shots]
    bufferOffset = _serializer.int16(obj.shots, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AmmoConsumeRequest
    let len;
    let data = new AmmoConsumeRequest(null);
    // Deserialize message field [shots]
    data.shots = _deserializer.int16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/AmmoConsumeRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8b70f68bd55f14867f198aecd8ff474b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int16 shots
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new AmmoConsumeRequest(null);
    if (msg.shots !== undefined) {
      resolved.shots = msg.shots;
    }
    else {
      resolved.shots = 0
    }

    return resolved;
    }
};

class AmmoConsumeResponse {
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
    // Serializes a message object of type AmmoConsumeResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type AmmoConsumeResponse
    let len;
    let data = new AmmoConsumeResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'icra_roboin_msgs/AmmoConsumeResponse';
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
    const resolved = new AmmoConsumeResponse(null);
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
  Request: AmmoConsumeRequest,
  Response: AmmoConsumeResponse,
  md5sum() { return '5a21dae1d703fd52723eaf9cba0ba9be'; },
  datatype() { return 'icra_roboin_msgs/AmmoConsume'; }
};
