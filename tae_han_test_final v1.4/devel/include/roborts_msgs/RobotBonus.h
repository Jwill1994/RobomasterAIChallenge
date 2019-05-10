// Generated by gencpp from file roborts_msgs/RobotBonus.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_ROBOTBONUS_H
#define ROBORTS_MSGS_MESSAGE_ROBOTBONUS_H


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
struct RobotBonus_
{
  typedef RobotBonus_<ContainerAllocator> Type;

  RobotBonus_()
    : bonus(false)  {
    }
  RobotBonus_(const ContainerAllocator& _alloc)
    : bonus(false)  {
  (void)_alloc;
    }



   typedef uint8_t _bonus_type;
  _bonus_type bonus;





  typedef boost::shared_ptr< ::roborts_msgs::RobotBonus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::RobotBonus_<ContainerAllocator> const> ConstPtr;

}; // struct RobotBonus_

typedef ::roborts_msgs::RobotBonus_<std::allocator<void> > RobotBonus;

typedef boost::shared_ptr< ::roborts_msgs::RobotBonus > RobotBonusPtr;
typedef boost::shared_ptr< ::roborts_msgs::RobotBonus const> RobotBonusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::RobotBonus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::RobotBonus_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::RobotBonus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::RobotBonus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::RobotBonus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "22365d98c104f9d16cae777ed759cbfe";
  }

  static const char* value(const ::roborts_msgs::RobotBonus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x22365d98c104f9d1ULL;
  static const uint64_t static_value2 = 0x6cae777ed759cbfeULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/RobotBonus";
  }

  static const char* value(const ::roborts_msgs::RobotBonus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#robot bonus\n\
bool bonus\n\
";
  }

  static const char* value(const ::roborts_msgs::RobotBonus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.bonus);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RobotBonus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::RobotBonus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::RobotBonus_<ContainerAllocator>& v)
  {
    s << indent << "bonus: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.bonus);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_ROBOTBONUS_H
