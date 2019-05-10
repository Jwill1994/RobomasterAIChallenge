// Generated by gencpp from file roborts_msgs/GimbalRate.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_GIMBALRATE_H
#define ROBORTS_MSGS_MESSAGE_GIMBALRATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace roborts_msgs
{
template <class ContainerAllocator>
struct GimbalRate_
{
  typedef GimbalRate_<ContainerAllocator> Type;

  GimbalRate_()
    : header()
    , pitch_rate(0.0)
    , yaw_rate(0.0)  {
    }
  GimbalRate_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , pitch_rate(0.0)
    , yaw_rate(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef double _pitch_rate_type;
  _pitch_rate_type pitch_rate;

   typedef double _yaw_rate_type;
  _yaw_rate_type yaw_rate;





  typedef boost::shared_ptr< ::roborts_msgs::GimbalRate_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::GimbalRate_<ContainerAllocator> const> ConstPtr;

}; // struct GimbalRate_

typedef ::roborts_msgs::GimbalRate_<std::allocator<void> > GimbalRate;

typedef boost::shared_ptr< ::roborts_msgs::GimbalRate > GimbalRatePtr;
typedef boost::shared_ptr< ::roborts_msgs::GimbalRate const> GimbalRateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::GimbalRate_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::GimbalRate_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roborts_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'roborts_msgs': ['/home/nvidia/Desktop/tae_han_test_final/devel/share/roborts_msgs/msg', '/home/nvidia/Desktop/tae_han_test_final/src/roborts_msgs/msg', '/home/nvidia/Desktop/tae_han_test_final/src/roborts_msgs/msg/referee_system'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::GimbalRate_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::GimbalRate_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::GimbalRate_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "525d7f3e8f2df5fe6c116264d2afd49a";
  }

  static const char* value(const ::roborts_msgs::GimbalRate_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x525d7f3e8f2df5feULL;
  static const uint64_t static_value2 = 0x6c116264d2afd49aULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/GimbalRate";
  }

  static const char* value(const ::roborts_msgs::GimbalRate_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n\
float64 pitch_rate\n\
float64 yaw_rate\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::roborts_msgs::GimbalRate_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pitch_rate);
      stream.next(m.yaw_rate);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GimbalRate_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::GimbalRate_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::GimbalRate_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "pitch_rate: ";
    Printer<double>::stream(s, indent + "  ", v.pitch_rate);
    s << indent << "yaw_rate: ";
    Printer<double>::stream(s, indent + "  ", v.yaw_rate);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_GIMBALRATE_H
