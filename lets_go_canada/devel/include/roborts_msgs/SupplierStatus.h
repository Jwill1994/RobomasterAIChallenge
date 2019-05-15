// Generated by gencpp from file roborts_msgs/SupplierStatus.msg
// DO NOT EDIT!


#ifndef ROBORTS_MSGS_MESSAGE_SUPPLIERSTATUS_H
#define ROBORTS_MSGS_MESSAGE_SUPPLIERSTATUS_H


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
struct SupplierStatus_
{
  typedef SupplierStatus_<ContainerAllocator> Type;

  SupplierStatus_()
    : status(0)  {
    }
  SupplierStatus_(const ContainerAllocator& _alloc)
    : status(0)  {
  (void)_alloc;
    }



   typedef uint8_t _status_type;
  _status_type status;



  enum {
    CLOSE = 0u,
    PREPARING = 1u,
    SUPPLYING = 2u,
  };


  typedef boost::shared_ptr< ::roborts_msgs::SupplierStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::roborts_msgs::SupplierStatus_<ContainerAllocator> const> ConstPtr;

}; // struct SupplierStatus_

typedef ::roborts_msgs::SupplierStatus_<std::allocator<void> > SupplierStatus;

typedef boost::shared_ptr< ::roborts_msgs::SupplierStatus > SupplierStatusPtr;
typedef boost::shared_ptr< ::roborts_msgs::SupplierStatus const> SupplierStatusConstPtr;

// constants requiring out of line definition

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::roborts_msgs::SupplierStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::roborts_msgs::SupplierStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::roborts_msgs::SupplierStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::roborts_msgs::SupplierStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "81f3d032e85b689acf259876e6f8d051";
  }

  static const char* value(const ::roborts_msgs::SupplierStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x81f3d032e85b689aULL;
  static const uint64_t static_value2 = 0xcf259876e6f8d051ULL;
};

template<class ContainerAllocator>
struct DataType< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "roborts_msgs/SupplierStatus";
  }

  static const char* value(const ::roborts_msgs::SupplierStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "#supplier status\n\
uint8 CLOSE = 0\n\
uint8 PREPARING = 1\n\
uint8 SUPPLYING = 2\n\
uint8 status\n\
\n\
";
  }

  static const char* value(const ::roborts_msgs::SupplierStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SupplierStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::roborts_msgs::SupplierStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::roborts_msgs::SupplierStatus_<ContainerAllocator>& v)
  {
    s << indent << "status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBORTS_MSGS_MESSAGE_SUPPLIERSTATUS_H
