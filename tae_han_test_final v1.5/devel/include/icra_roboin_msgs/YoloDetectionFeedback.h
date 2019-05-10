// Generated by gencpp from file icra_roboin_msgs/YoloDetectionFeedback.msg
// DO NOT EDIT!


#ifndef ICRA_ROBOIN_MSGS_MESSAGE_YOLODETECTIONFEEDBACK_H
#define ICRA_ROBOIN_MSGS_MESSAGE_YOLODETECTIONFEEDBACK_H


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
struct YoloDetectionFeedback_
{
  typedef YoloDetectionFeedback_<ContainerAllocator> Type;

  YoloDetectionFeedback_()
    : stamp()
    , infochecker(0)
    , enemy(0)
    , angle_hori()
    , angle_verti()
    , Pixel_X()
    , Pixel_Y()
    , Pixel_width()
    , Pixel_height()
    , real_width()
    , real_height()
    , distance()  {
      angle_hori.assign(0);

      angle_verti.assign(0);

      Pixel_X.assign(0);

      Pixel_Y.assign(0);

      Pixel_width.assign(0);

      Pixel_height.assign(0);

      real_width.assign(0);

      real_height.assign(0);

      distance.assign(0);
  }
  YoloDetectionFeedback_(const ContainerAllocator& _alloc)
    : stamp()
    , infochecker(0)
    , enemy(0)
    , angle_hori()
    , angle_verti()
    , Pixel_X()
    , Pixel_Y()
    , Pixel_width()
    , Pixel_height()
    , real_width()
    , real_height()
    , distance()  {
  (void)_alloc;
      angle_hori.assign(0);

      angle_verti.assign(0);

      Pixel_X.assign(0);

      Pixel_Y.assign(0);

      Pixel_width.assign(0);

      Pixel_height.assign(0);

      real_width.assign(0);

      real_height.assign(0);

      distance.assign(0);
  }



   typedef ros::Time _stamp_type;
  _stamp_type stamp;

   typedef uint8_t _infochecker_type;
  _infochecker_type infochecker;

   typedef uint8_t _enemy_type;
  _enemy_type enemy;

   typedef boost::array<int16_t, 3>  _angle_hori_type;
  _angle_hori_type angle_hori;

   typedef boost::array<int16_t, 3>  _angle_verti_type;
  _angle_verti_type angle_verti;

   typedef boost::array<int16_t, 3>  _Pixel_X_type;
  _Pixel_X_type Pixel_X;

   typedef boost::array<int16_t, 3>  _Pixel_Y_type;
  _Pixel_Y_type Pixel_Y;

   typedef boost::array<int16_t, 3>  _Pixel_width_type;
  _Pixel_width_type Pixel_width;

   typedef boost::array<int16_t, 3>  _Pixel_height_type;
  _Pixel_height_type Pixel_height;

   typedef boost::array<int16_t, 3>  _real_width_type;
  _real_width_type real_width;

   typedef boost::array<int16_t, 3>  _real_height_type;
  _real_height_type real_height;

   typedef boost::array<int16_t, 3>  _distance_type;
  _distance_type distance;





  typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> const> ConstPtr;

}; // struct YoloDetectionFeedback_

typedef ::icra_roboin_msgs::YoloDetectionFeedback_<std::allocator<void> > YoloDetectionFeedback;

typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionFeedback > YoloDetectionFeedbackPtr;
typedef boost::shared_ptr< ::icra_roboin_msgs::YoloDetectionFeedback const> YoloDetectionFeedbackConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "264543f7a1172d61963435fe8085999c";
  }

  static const char* value(const ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x264543f7a1172d61ULL;
  static const uint64_t static_value2 = 0x963435fe8085999cULL;
};

template<class ContainerAllocator>
struct DataType< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "icra_roboin_msgs/YoloDetectionFeedback";
  }

  static const char* value(const ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
#feedback\n\
time stamp\n\
uint8 infochecker\n\
uint8 enemy\n\
int16[3] angle_hori\n\
int16[3] angle_verti\n\
int16[3] Pixel_X\n\
int16[3] Pixel_Y\n\
int16[3] Pixel_width\n\
int16[3] Pixel_height\n\
int16[3] real_width\n\
int16[3] real_height\n\
int16[3] distance\n\
\n\
";
  }

  static const char* value(const ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.infochecker);
      stream.next(m.enemy);
      stream.next(m.angle_hori);
      stream.next(m.angle_verti);
      stream.next(m.Pixel_X);
      stream.next(m.Pixel_Y);
      stream.next(m.Pixel_width);
      stream.next(m.Pixel_height);
      stream.next(m.real_width);
      stream.next(m.real_height);
      stream.next(m.distance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct YoloDetectionFeedback_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::icra_roboin_msgs::YoloDetectionFeedback_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.stamp);
    s << indent << "infochecker: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.infochecker);
    s << indent << "enemy: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.enemy);
    s << indent << "angle_hori[]" << std::endl;
    for (size_t i = 0; i < v.angle_hori.size(); ++i)
    {
      s << indent << "  angle_hori[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.angle_hori[i]);
    }
    s << indent << "angle_verti[]" << std::endl;
    for (size_t i = 0; i < v.angle_verti.size(); ++i)
    {
      s << indent << "  angle_verti[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.angle_verti[i]);
    }
    s << indent << "Pixel_X[]" << std::endl;
    for (size_t i = 0; i < v.Pixel_X.size(); ++i)
    {
      s << indent << "  Pixel_X[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.Pixel_X[i]);
    }
    s << indent << "Pixel_Y[]" << std::endl;
    for (size_t i = 0; i < v.Pixel_Y.size(); ++i)
    {
      s << indent << "  Pixel_Y[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.Pixel_Y[i]);
    }
    s << indent << "Pixel_width[]" << std::endl;
    for (size_t i = 0; i < v.Pixel_width.size(); ++i)
    {
      s << indent << "  Pixel_width[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.Pixel_width[i]);
    }
    s << indent << "Pixel_height[]" << std::endl;
    for (size_t i = 0; i < v.Pixel_height.size(); ++i)
    {
      s << indent << "  Pixel_height[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.Pixel_height[i]);
    }
    s << indent << "real_width[]" << std::endl;
    for (size_t i = 0; i < v.real_width.size(); ++i)
    {
      s << indent << "  real_width[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.real_width[i]);
    }
    s << indent << "real_height[]" << std::endl;
    for (size_t i = 0; i < v.real_height.size(); ++i)
    {
      s << indent << "  real_height[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.real_height[i]);
    }
    s << indent << "distance[]" << std::endl;
    for (size_t i = 0; i < v.distance.size(); ++i)
    {
      s << indent << "  distance[" << i << "]: ";
      Printer<int16_t>::stream(s, indent + "  ", v.distance[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ICRA_ROBOIN_MSGS_MESSAGE_YOLODETECTIONFEEDBACK_H
