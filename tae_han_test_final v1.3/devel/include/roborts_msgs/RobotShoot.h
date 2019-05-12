// Generated by gencpp from file roborts_msgs/RobotShoot.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_ROBOTSHOOT_H
#define ROBORTS_MSGS_MESSAGE_ROBOTSHOOT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace roborts_msgs
{
template <class ContainerAllocator>
struct RobotShoot_
{
  typedef RobotShoot_<ContainerAllocator> Type;

  RobotShoot_()
    : frequency(0)
    , speed(0.0)  {
    }
  RobotShoot_(const ContainerAllocator& _alloc)
    : frequency(0)
    , speed(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _frequency_type;
  _frequency_type frequency;

   typedef double _speed_type;
  _speed_type speed;





  typedef boost::shared_ptr< ::roborts_msgs::RobotShoot_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::RobotShoot_<ContainerAllocator> const> ConstPtr;

}; // struct RobotShoot_

typedef ::roborts_msgs::RobotShoot_<std::allocator<void> > RobotShoot;

typedef boost::shared_ptr< ::roborts_msgs::RobotShoot > RobotShootPtr;
typedef boost::shared_ptr< ::roborts_msgs::RobotShoot const> RobotShootConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::RobotShoot_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::RobotShoot_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roborts_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'roborts_msgs': ['/home/nvidia/Desktop/tae_han_test_final/devel/share/roborts_msgs/msg', '/home/nvidia/Desktop/tae_han_test_final/src/roborts_msgs/msg', '/home/nvidia/Desktop/tae_han_test_final/src/roborts_msgs/msg/referee_system'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::RobotShoot_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::RobotShoot_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::RobotShoot_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2634dbd94553eb6552f07bddaa5136d1";
  }

  static const char* value(const ::roborts_msgs::RobotShoot_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2634dbd94553eb65ULL;
  static const uint64_t static_value2 = 0x52f07bddaa5136d1ULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/RobotShoot";
  }

  static const char* value(const ::roborts_msgs::RobotShoot_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#robot shoot data\n\
uint8 frequency\n\
float64 speed\n\
";
  }

  static const char* value(const ::roborts_msgs::RobotShoot_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.frequency);
      stream.next(m.speed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RobotShoot_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::RobotShoot_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::RobotShoot_<ContainerAllocator>& v)
  {
    s << indent << "frequency: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.frequency);
    s << indent << "speed: ";
    Printer<double>::stream(s, indent + "  ", v.speed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_ROBOTSHOOT_H