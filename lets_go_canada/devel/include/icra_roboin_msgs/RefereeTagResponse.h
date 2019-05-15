// Generated by gencpp from file icra_roboin_msgs/RefereeTagResponse.msg
// DO NOT EDIT!


#ifndef ICRA_ROBOIN_MSGS_MESSAGE_REFEREETAGRESPONSE_H
#define ICRA_ROBOIN_MSGS_MESSAGE_REFEREETAGRESPONSE_H


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
struct RefereeTagResponse_
{
  typedef RefereeTagResponse_<ContainerAllocator> Type;

  RefereeTagResponse_()
    : info(0)
    , success(false)  {
    }
  RefereeTagResponse_(const ContainerAllocator& _alloc)
    : info(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef int16_t _info_type;
  _info_type info;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> const> ConstPtr;

}; // struct RefereeTagResponse_

typedef ::icra_roboin_msgs::RefereeTagResponse_<std::allocator<void> > RefereeTagResponse;

typedef boost::shared_ptr< ::icra_roboin_msgs::RefereeTagResponse > RefereeTagResponsePtr;
typedef boost::shared_ptr< ::icra_roboin_msgs::RefereeTagResponse const> RefereeTagResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace icra_roboin_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'icra_roboin_msgs': ['/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg', '/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e156420e06769c10db65b694db7ee8bc";
  }

  static const char* value(const ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe156420e06769c10ULL;
  static const uint64_t static_value2 = 0xdb65b694db7ee8bcULL;
};

template<class ContainerAllocator>
struct DataType< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "icra_roboin_msgs/RefereeTagResponse";
  }

  static const char* value(const ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
int16 info\n\
bool success\n\
\n\
\n\
";
  }

  static const char* value(const ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.info);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RefereeTagResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::icra_roboin_msgs::RefereeTagResponse_<ContainerAllocator>& v)
  {
    s << indent << "info: ";
    Printer<int16_t>::stream(s, indent + "  ", v.info);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ICRA_ROBOIN_MSGS_MESSAGE_REFEREETAGRESPONSE_H
