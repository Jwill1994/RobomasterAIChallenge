# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from icra_roboin_msgs/BlackboardGeneralInfoRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import genpy

class BlackboardGeneralInfoRequest(genpy.Message):
  _md5sum = "66a57ffbb7b0191a46e5cac0c5adf55b"
  _type = "icra_roboin_msgs/BlackboardGeneralInfoRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """time stamp
string request_sender
bool confirm
"""
  __slots__ = ['stamp','request_sender','confirm']
  _slot_types = ['time','string','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       stamp,request_sender,confirm

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(BlackboardGeneralInfoRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.stamp is None:
        self.stamp = genpy.Time()
      if self.request_sender is None:
        self.request_sender = ''
      if self.confirm is None:
        self.confirm = False
    else:
      self.stamp = genpy.Time()
      self.request_sender = ''
      self.confirm = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2I().pack(_x.stamp.secs, _x.stamp.nsecs))
      _x = self.request_sender
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_B().pack(self.confirm))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.stamp is None:
        self.stamp = genpy.Time()
      end = 0
      _x = self
      start = end
      end += 8
      (_x.stamp.secs, _x.stamp.nsecs,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.request_sender = str[start:end].decode('utf-8')
      else:
        self.request_sender = str[start:end]
      start = end
      end += 1
      (self.confirm,) = _get_struct_B().unpack(str[start:end])
      self.confirm = bool(self.confirm)
      self.stamp.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2I().pack(_x.stamp.secs, _x.stamp.nsecs))
      _x = self.request_sender
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      buff.write(_get_struct_B().pack(self.confirm))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.stamp is None:
        self.stamp = genpy.Time()
      end = 0
      _x = self
      start = end
      end += 8
      (_x.stamp.secs, _x.stamp.nsecs,) = _get_struct_2I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.request_sender = str[start:end].decode('utf-8')
      else:
        self.request_sender = str[start:end]
      start = end
      end += 1
      (self.confirm,) = _get_struct_B().unpack(str[start:end])
      self.confirm = bool(self.confirm)
      self.stamp.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_B = None
def _get_struct_B():
    global _struct_B
    if _struct_B is None:
        _struct_B = struct.Struct("<B")
    return _struct_B
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from icra_roboin_msgs/BlackboardGeneralInfoResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import icra_roboin_msgs.msg
import geometry_msgs.msg
import genpy
import std_msgs.msg

class BlackboardGeneralInfoResponse(genpy.Message):
  _md5sum = "5a6420e2d73a3b280e9fbf108fe64e9e"
  _type = "icra_roboin_msgs/BlackboardGeneralInfoResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """time stamp
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
"""
  __slots__ = ['stamp','time_passed_from_start','game_state','buff_zone_cooltime','reload_zone_cooltime','my_health','is_hit','which_armor_hit','last_hit_time','has_buff','buff_left','ammo','my_pose','enemy_pose1','enemy_pose2','how_many_enemies_detected','is_enemy_1_detected','is_enemy_2_detected','locked_on_enemy','enemy_priority','goal','current_behavior_style','current_behavior_process']
  _slot_types = ['time','int32','uint8','int32','int32','int16','bool','uint8','int32','bool','int32','int16','geometry_msgs/PoseStamped','geometry_msgs/PoseStamped','geometry_msgs/PoseStamped','uint8','bool','bool','uint8','uint8','icra_roboin_msgs/GoalDescription','uint8','uint8']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       stamp,time_passed_from_start,game_state,buff_zone_cooltime,reload_zone_cooltime,my_health,is_hit,which_armor_hit,last_hit_time,has_buff,buff_left,ammo,my_pose,enemy_pose1,enemy_pose2,how_many_enemies_detected,is_enemy_1_detected,is_enemy_2_detected,locked_on_enemy,enemy_priority,goal,current_behavior_style,current_behavior_process

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(BlackboardGeneralInfoResponse, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.stamp is None:
        self.stamp = genpy.Time()
      if self.time_passed_from_start is None:
        self.time_passed_from_start = 0
      if self.game_state is None:
        self.game_state = 0
      if self.buff_zone_cooltime is None:
        self.buff_zone_cooltime = 0
      if self.reload_zone_cooltime is None:
        self.reload_zone_cooltime = 0
      if self.my_health is None:
        self.my_health = 0
      if self.is_hit is None:
        self.is_hit = False
      if self.which_armor_hit is None:
        self.which_armor_hit = 0
      if self.last_hit_time is None:
        self.last_hit_time = 0
      if self.has_buff is None:
        self.has_buff = False
      if self.buff_left is None:
        self.buff_left = 0
      if self.ammo is None:
        self.ammo = 0
      if self.my_pose is None:
        self.my_pose = geometry_msgs.msg.PoseStamped()
      if self.enemy_pose1 is None:
        self.enemy_pose1 = geometry_msgs.msg.PoseStamped()
      if self.enemy_pose2 is None:
        self.enemy_pose2 = geometry_msgs.msg.PoseStamped()
      if self.how_many_enemies_detected is None:
        self.how_many_enemies_detected = 0
      if self.is_enemy_1_detected is None:
        self.is_enemy_1_detected = False
      if self.is_enemy_2_detected is None:
        self.is_enemy_2_detected = False
      if self.locked_on_enemy is None:
        self.locked_on_enemy = 0
      if self.enemy_priority is None:
        self.enemy_priority = 0
      if self.goal is None:
        self.goal = icra_roboin_msgs.msg.GoalDescription()
      if self.current_behavior_style is None:
        self.current_behavior_style = 0
      if self.current_behavior_process is None:
        self.current_behavior_process = 0
    else:
      self.stamp = genpy.Time()
      self.time_passed_from_start = 0
      self.game_state = 0
      self.buff_zone_cooltime = 0
      self.reload_zone_cooltime = 0
      self.my_health = 0
      self.is_hit = False
      self.which_armor_hit = 0
      self.last_hit_time = 0
      self.has_buff = False
      self.buff_left = 0
      self.ammo = 0
      self.my_pose = geometry_msgs.msg.PoseStamped()
      self.enemy_pose1 = geometry_msgs.msg.PoseStamped()
      self.enemy_pose2 = geometry_msgs.msg.PoseStamped()
      self.how_many_enemies_detected = 0
      self.is_enemy_1_detected = False
      self.is_enemy_2_detected = False
      self.locked_on_enemy = 0
      self.enemy_priority = 0
      self.goal = icra_roboin_msgs.msg.GoalDescription()
      self.current_behavior_style = 0
      self.current_behavior_process = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2IiB2ih2BiBih3I().pack(_x.stamp.secs, _x.stamp.nsecs, _x.time_passed_from_start, _x.game_state, _x.buff_zone_cooltime, _x.reload_zone_cooltime, _x.my_health, _x.is_hit, _x.which_armor_hit, _x.last_hit_time, _x.has_buff, _x.buff_left, _x.ammo, _x.my_pose.header.seq, _x.my_pose.header.stamp.secs, _x.my_pose.header.stamp.nsecs))
      _x = self.my_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d3I().pack(_x.my_pose.pose.position.x, _x.my_pose.pose.position.y, _x.my_pose.pose.position.z, _x.my_pose.pose.orientation.x, _x.my_pose.pose.orientation.y, _x.my_pose.pose.orientation.z, _x.my_pose.pose.orientation.w, _x.enemy_pose1.header.seq, _x.enemy_pose1.header.stamp.secs, _x.enemy_pose1.header.stamp.nsecs))
      _x = self.enemy_pose1.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d3I().pack(_x.enemy_pose1.pose.position.x, _x.enemy_pose1.pose.position.y, _x.enemy_pose1.pose.position.z, _x.enemy_pose1.pose.orientation.x, _x.enemy_pose1.pose.orientation.y, _x.enemy_pose1.pose.orientation.z, _x.enemy_pose1.pose.orientation.w, _x.enemy_pose2.header.seq, _x.enemy_pose2.header.stamp.secs, _x.enemy_pose2.header.stamp.nsecs))
      _x = self.enemy_pose2.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d5B3I().pack(_x.enemy_pose2.pose.position.x, _x.enemy_pose2.pose.position.y, _x.enemy_pose2.pose.position.z, _x.enemy_pose2.pose.orientation.x, _x.enemy_pose2.pose.orientation.y, _x.enemy_pose2.pose.orientation.z, _x.enemy_pose2.pose.orientation.w, _x.how_many_enemies_detected, _x.is_enemy_1_detected, _x.is_enemy_2_detected, _x.locked_on_enemy, _x.enemy_priority, _x.goal.header.seq, _x.goal.header.stamp.secs, _x.goal.header.stamp.nsecs))
      _x = self.goal.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d2B().pack(_x.goal.x, _x.goal.y, _x.goal.yaw, _x.goal.xa, _x.goal.ya, _x.goal.yawa, _x.goal.etc, _x.current_behavior_style, _x.current_behavior_process))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      if self.stamp is None:
        self.stamp = genpy.Time()
      if self.my_pose is None:
        self.my_pose = geometry_msgs.msg.PoseStamped()
      if self.enemy_pose1 is None:
        self.enemy_pose1 = geometry_msgs.msg.PoseStamped()
      if self.enemy_pose2 is None:
        self.enemy_pose2 = geometry_msgs.msg.PoseStamped()
      if self.goal is None:
        self.goal = icra_roboin_msgs.msg.GoalDescription()
      end = 0
      _x = self
      start = end
      end += 48
      (_x.stamp.secs, _x.stamp.nsecs, _x.time_passed_from_start, _x.game_state, _x.buff_zone_cooltime, _x.reload_zone_cooltime, _x.my_health, _x.is_hit, _x.which_armor_hit, _x.last_hit_time, _x.has_buff, _x.buff_left, _x.ammo, _x.my_pose.header.seq, _x.my_pose.header.stamp.secs, _x.my_pose.header.stamp.nsecs,) = _get_struct_2IiB2ih2BiBih3I().unpack(str[start:end])
      self.is_hit = bool(self.is_hit)
      self.has_buff = bool(self.has_buff)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.my_pose.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.my_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.my_pose.pose.position.x, _x.my_pose.pose.position.y, _x.my_pose.pose.position.z, _x.my_pose.pose.orientation.x, _x.my_pose.pose.orientation.y, _x.my_pose.pose.orientation.z, _x.my_pose.pose.orientation.w, _x.enemy_pose1.header.seq, _x.enemy_pose1.header.stamp.secs, _x.enemy_pose1.header.stamp.nsecs,) = _get_struct_7d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.enemy_pose1.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.enemy_pose1.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.enemy_pose1.pose.position.x, _x.enemy_pose1.pose.position.y, _x.enemy_pose1.pose.position.z, _x.enemy_pose1.pose.orientation.x, _x.enemy_pose1.pose.orientation.y, _x.enemy_pose1.pose.orientation.z, _x.enemy_pose1.pose.orientation.w, _x.enemy_pose2.header.seq, _x.enemy_pose2.header.stamp.secs, _x.enemy_pose2.header.stamp.nsecs,) = _get_struct_7d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.enemy_pose2.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.enemy_pose2.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 73
      (_x.enemy_pose2.pose.position.x, _x.enemy_pose2.pose.position.y, _x.enemy_pose2.pose.position.z, _x.enemy_pose2.pose.orientation.x, _x.enemy_pose2.pose.orientation.y, _x.enemy_pose2.pose.orientation.z, _x.enemy_pose2.pose.orientation.w, _x.how_many_enemies_detected, _x.is_enemy_1_detected, _x.is_enemy_2_detected, _x.locked_on_enemy, _x.enemy_priority, _x.goal.header.seq, _x.goal.header.stamp.secs, _x.goal.header.stamp.nsecs,) = _get_struct_7d5B3I().unpack(str[start:end])
      self.is_enemy_1_detected = bool(self.is_enemy_1_detected)
      self.is_enemy_2_detected = bool(self.is_enemy_2_detected)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.goal.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.goal.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 58
      (_x.goal.x, _x.goal.y, _x.goal.yaw, _x.goal.xa, _x.goal.ya, _x.goal.yawa, _x.goal.etc, _x.current_behavior_style, _x.current_behavior_process,) = _get_struct_7d2B().unpack(str[start:end])
      self.stamp.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2IiB2ih2BiBih3I().pack(_x.stamp.secs, _x.stamp.nsecs, _x.time_passed_from_start, _x.game_state, _x.buff_zone_cooltime, _x.reload_zone_cooltime, _x.my_health, _x.is_hit, _x.which_armor_hit, _x.last_hit_time, _x.has_buff, _x.buff_left, _x.ammo, _x.my_pose.header.seq, _x.my_pose.header.stamp.secs, _x.my_pose.header.stamp.nsecs))
      _x = self.my_pose.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d3I().pack(_x.my_pose.pose.position.x, _x.my_pose.pose.position.y, _x.my_pose.pose.position.z, _x.my_pose.pose.orientation.x, _x.my_pose.pose.orientation.y, _x.my_pose.pose.orientation.z, _x.my_pose.pose.orientation.w, _x.enemy_pose1.header.seq, _x.enemy_pose1.header.stamp.secs, _x.enemy_pose1.header.stamp.nsecs))
      _x = self.enemy_pose1.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d3I().pack(_x.enemy_pose1.pose.position.x, _x.enemy_pose1.pose.position.y, _x.enemy_pose1.pose.position.z, _x.enemy_pose1.pose.orientation.x, _x.enemy_pose1.pose.orientation.y, _x.enemy_pose1.pose.orientation.z, _x.enemy_pose1.pose.orientation.w, _x.enemy_pose2.header.seq, _x.enemy_pose2.header.stamp.secs, _x.enemy_pose2.header.stamp.nsecs))
      _x = self.enemy_pose2.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d5B3I().pack(_x.enemy_pose2.pose.position.x, _x.enemy_pose2.pose.position.y, _x.enemy_pose2.pose.position.z, _x.enemy_pose2.pose.orientation.x, _x.enemy_pose2.pose.orientation.y, _x.enemy_pose2.pose.orientation.z, _x.enemy_pose2.pose.orientation.w, _x.how_many_enemies_detected, _x.is_enemy_1_detected, _x.is_enemy_2_detected, _x.locked_on_enemy, _x.enemy_priority, _x.goal.header.seq, _x.goal.header.stamp.secs, _x.goal.header.stamp.nsecs))
      _x = self.goal.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.pack('<I%ss'%length, length, _x))
      _x = self
      buff.write(_get_struct_7d2B().pack(_x.goal.x, _x.goal.y, _x.goal.yaw, _x.goal.xa, _x.goal.ya, _x.goal.yawa, _x.goal.etc, _x.current_behavior_style, _x.current_behavior_process))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      if self.stamp is None:
        self.stamp = genpy.Time()
      if self.my_pose is None:
        self.my_pose = geometry_msgs.msg.PoseStamped()
      if self.enemy_pose1 is None:
        self.enemy_pose1 = geometry_msgs.msg.PoseStamped()
      if self.enemy_pose2 is None:
        self.enemy_pose2 = geometry_msgs.msg.PoseStamped()
      if self.goal is None:
        self.goal = icra_roboin_msgs.msg.GoalDescription()
      end = 0
      _x = self
      start = end
      end += 48
      (_x.stamp.secs, _x.stamp.nsecs, _x.time_passed_from_start, _x.game_state, _x.buff_zone_cooltime, _x.reload_zone_cooltime, _x.my_health, _x.is_hit, _x.which_armor_hit, _x.last_hit_time, _x.has_buff, _x.buff_left, _x.ammo, _x.my_pose.header.seq, _x.my_pose.header.stamp.secs, _x.my_pose.header.stamp.nsecs,) = _get_struct_2IiB2ih2BiBih3I().unpack(str[start:end])
      self.is_hit = bool(self.is_hit)
      self.has_buff = bool(self.has_buff)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.my_pose.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.my_pose.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.my_pose.pose.position.x, _x.my_pose.pose.position.y, _x.my_pose.pose.position.z, _x.my_pose.pose.orientation.x, _x.my_pose.pose.orientation.y, _x.my_pose.pose.orientation.z, _x.my_pose.pose.orientation.w, _x.enemy_pose1.header.seq, _x.enemy_pose1.header.stamp.secs, _x.enemy_pose1.header.stamp.nsecs,) = _get_struct_7d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.enemy_pose1.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.enemy_pose1.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 68
      (_x.enemy_pose1.pose.position.x, _x.enemy_pose1.pose.position.y, _x.enemy_pose1.pose.position.z, _x.enemy_pose1.pose.orientation.x, _x.enemy_pose1.pose.orientation.y, _x.enemy_pose1.pose.orientation.z, _x.enemy_pose1.pose.orientation.w, _x.enemy_pose2.header.seq, _x.enemy_pose2.header.stamp.secs, _x.enemy_pose2.header.stamp.nsecs,) = _get_struct_7d3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.enemy_pose2.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.enemy_pose2.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 73
      (_x.enemy_pose2.pose.position.x, _x.enemy_pose2.pose.position.y, _x.enemy_pose2.pose.position.z, _x.enemy_pose2.pose.orientation.x, _x.enemy_pose2.pose.orientation.y, _x.enemy_pose2.pose.orientation.z, _x.enemy_pose2.pose.orientation.w, _x.how_many_enemies_detected, _x.is_enemy_1_detected, _x.is_enemy_2_detected, _x.locked_on_enemy, _x.enemy_priority, _x.goal.header.seq, _x.goal.header.stamp.secs, _x.goal.header.stamp.nsecs,) = _get_struct_7d5B3I().unpack(str[start:end])
      self.is_enemy_1_detected = bool(self.is_enemy_1_detected)
      self.is_enemy_2_detected = bool(self.is_enemy_2_detected)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.goal.header.frame_id = str[start:end].decode('utf-8')
      else:
        self.goal.header.frame_id = str[start:end]
      _x = self
      start = end
      end += 58
      (_x.goal.x, _x.goal.y, _x.goal.yaw, _x.goal.xa, _x.goal.ya, _x.goal.yawa, _x.goal.etc, _x.current_behavior_style, _x.current_behavior_process,) = _get_struct_7d2B().unpack(str[start:end])
      self.stamp.canon()
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2IiB2ih2BiBih3I = None
def _get_struct_2IiB2ih2BiBih3I():
    global _struct_2IiB2ih2BiBih3I
    if _struct_2IiB2ih2BiBih3I is None:
        _struct_2IiB2ih2BiBih3I = struct.Struct("<2IiB2ih2BiBih3I")
    return _struct_2IiB2ih2BiBih3I
_struct_7d3I = None
def _get_struct_7d3I():
    global _struct_7d3I
    if _struct_7d3I is None:
        _struct_7d3I = struct.Struct("<7d3I")
    return _struct_7d3I
_struct_7d5B3I = None
def _get_struct_7d5B3I():
    global _struct_7d5B3I
    if _struct_7d5B3I is None:
        _struct_7d5B3I = struct.Struct("<7d5B3I")
    return _struct_7d5B3I
_struct_7d2B = None
def _get_struct_7d2B():
    global _struct_7d2B
    if _struct_7d2B is None:
        _struct_7d2B = struct.Struct("<7d2B")
    return _struct_7d2B
class BlackboardGeneralInfo(object):
  _type          = 'icra_roboin_msgs/BlackboardGeneralInfo'
  _md5sum = '194169ae9786a8ee22311fb734602f60'
  _request_class  = BlackboardGeneralInfoRequest
  _response_class = BlackboardGeneralInfoResponse
