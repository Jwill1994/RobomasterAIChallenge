// Generated by gencpp from file roborts_msgs/GameStatus.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_GAMESTATUS_H
#define ROBORTS_MSGS_MESSAGE_GAMESTATUS_H


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
struct GameStatus_
{
  typedef GameStatus_<ContainerAllocator> Type;

  GameStatus_()
    : game_status(0)
    , remaining_time(0)  {
    }
  GameStatus_(const ContainerAllocator& _alloc)
    : game_status(0)
    , remaining_time(0)  {
  (void)_alloc;
    }



   typedef uint8_t _game_status_type;
  _game_status_type game_status;

   typedef uint16_t _remaining_time_type;
  _remaining_time_type remaining_time;



  enum {
    PRE_MATCH = 0u,
    SETUP = 1u,
    INIT = 2u,
    FIVE_SEC_CD = 3u,
    ROUND = 4u,
    CALCULATION = 5u,
  };


  typedef boost::shared_ptr< ::roborts_msgs::GameStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::GameStatus_<ContainerAllocator> const> ConstPtr;

}; // struct GameStatus_

typedef ::roborts_msgs::GameStatus_<std::allocator<void> > GameStatus;

typedef boost::shared_ptr< ::roborts_msgs::GameStatus > GameStatusPtr;
typedef boost::shared_ptr< ::roborts_msgs::GameStatus const> GameStatusConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::GameStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::GameStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace roborts_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'roborts_msgs': ['/home/kimtaehan/Desktop/lets_go_canada/devel/share/roborts_msgs/msg', '/home/kimtaehan/Desktop/lets_go_canada/src/roborts_msgs/msg', '/home/kimtaehan/Desktop/lets_go_canada/src/roborts_msgs/msg/referee_system'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::GameStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::GameStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::GameStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::GameStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::GameStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::GameStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::GameStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1420f1b84d9eff8855d07e0139b55a97";
  }

  static const char* value(const ::roborts_msgs::GameStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1420f1b84d9eff88ULL;
  static const uint64_t static_value2 = 0x55d07e0139b55a97ULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::GameStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/GameStatus";
  }

  static const char* value(const ::roborts_msgs::GameStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::GameStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#game status\n\
uint8 PRE_MATCH = 0\n\
uint8 SETUP = 1\n\
uint8 INIT = 2\n\
uint8 FIVE_SEC_CD = 3\n\
uint8 ROUND = 4\n\
uint8 CALCULATION = 5\n\
uint8 game_status\n\
uint16 remaining_time\n\
\n\
\n\
\n\
";
  }

  static const char* value(const ::roborts_msgs::GameStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::GameStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.game_status);
      stream.next(m.remaining_time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GameStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::GameStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::GameStatus_<ContainerAllocator>& v)
  {
    s << indent << "game_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.game_status);
    s << indent << "remaining_time: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.remaining_time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_GAMESTATUS_H
