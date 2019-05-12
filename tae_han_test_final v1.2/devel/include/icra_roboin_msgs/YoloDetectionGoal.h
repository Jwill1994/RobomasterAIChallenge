// Generated by gencpp from file icra_roboin_msgs/YoloDetectionGoal.msg
// DO NOT EDIT!


#ifndef ICRA_ROBOIN_MSGS_MESSAGE_YOLODETECTIONGOAL_H
#define ICRA_ROBOIN_MSGS_MESSAGE_YOLODETECTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace icra_roboin_msgs
{
template <class ContainerAllocator>
struct YoloDetectionGoal_
{
  typedef YoloDetectionGoal_<ContainerAllocator> Type;

  YoloDetectionGoal_()
    : command(0)  {
    }
  YoloDetectionGoal_(const ContainerAllocator& _alloc)
    : command(0)  {
  (void)_alloc;
    }



   typedef uint8_t _command_type;
  _command_type command;





  typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct YoloDetectionGoal_

typedef ::icra_roboin_msgs::YoloDetectionGoal_<std::allocator<void> > YoloDetectionGoal;

typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionGoal > YoloDetectionGoalPtr;
typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionGoal const> YoloDetectionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace icra_roboin_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'icra_roboin_msgs': ['/home/nvidia/Desktop/tae_han_test_final/src/icra_roboin_msgs/msg', '/home/nvidia/Desktop/tae_han_test_final/devel/share/icra_roboin_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "36e1d21d1340e2a5e93f075b6457cbdf";
  }

  static const char* value(const ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x36e1d21d1340e2a5ULL;
  static const uint64_t static_value2 = 0xe93f075b6457cbdfULL;
};

template<class ContainerAllocator>
struct DataType< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "icra_roboin_msgs/YoloDetectionGoal";
  }

  static const char* value(const ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#Send a flag to server to control the thread start, pause, restart and stop\n\
#command == 1 start\n\
#command == 2 pause\n\
#command == 3 stop\n\
uint8 command\n\
";
  }

  static const char* value(const ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.command);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct YoloDetectionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::icra_roboin_msgs::YoloDetectionGoal_<ContainerAllocator>& v)
  {
    s << indent << "command: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.command);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ICRA_ROBOIN_MSGS_MESSAGE_YOLODETECTIONGOAL_H