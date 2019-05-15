// Generated by gencpp from file icra_roboin_msgs/BlackboardGeneralInfoRequest.msg
// DO NOT EDIT!


#ifndef ICRA_ROBOIN_MSGS_MESSAGE_BLACKBOARDGENERALINFOREQUEST_H
#define ICRA_ROBOIN_MSGS_MESSAGE_BLACKBOARDGENERALINFOREQUEST_H


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
struct BlackboardGeneralInfoRequest_
{
  typedef BlackboardGeneralInfoRequest_<ContainerAllocator> Type;

  BlackboardGeneralInfoRequest_()
    : stamp()
    , request_sender()
    , confirm(false)  {
    }
  BlackboardGeneralInfoRequest_(const ContainerAllocator& _alloc)
    : stamp()
    , request_sender(_alloc)
    , confirm(false)  {
  (void)_alloc;
    }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _request_sender_type;
  _request_sender_type request_sender;

   typedef uint8_t _confirm_type;
  _confirm_type confirm;





  typedef boost::shared_ptr< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> const> ConstPtr;

}; // struct BlackboardGeneralInfoRequest_

typedef ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<std::allocator<void> > BlackboardGeneralInfoRequest;

typedef boost::shared_ptr< ::icra_roboin_msgs::BlackboardGeneralInfoRequest > BlackboardGeneralInfoRequestPtr;
typedef boost::shared_ptr< ::icra_roboin_msgs::BlackboardGeneralInfoRequest const> BlackboardGeneralInfoRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace icra_roboin_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'icra_roboin_msgs': ['/home/kimtaehan/Desktop/lets_go_canada/src/icra_roboin_msgs/msg', '/home/kimtaehan/Desktop/lets_go_canada/devel/share/icra_roboin_msgs/msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "66a57ffbb7b0191a46e5cac0c5adf55b";
  }

  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x66a57ffbb7b0191aULL;
  static const uint64_t static_value2 = 0x46e5cac0c5adf55bULL;
};

template<class ContainerAllocator>
struct DataType< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "icra_roboin_msgs/BlackboardGeneralInfoRequest";
  }

  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "time stamp\n\
string request_sender\n\
bool confirm\n\
";
  }

  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.request_sender);
      stream.next(m.confirm);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct BlackboardGeneralInfoRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::icra_roboin_msgs::BlackboardGeneralInfoRequest_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "request_sender: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.request_sender);
    s << indent << "confirm: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.confirm);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ICRA_ROBOIN_MSGS_MESSAGE_BLACKBOARDGENERALINFOREQUEST_H
