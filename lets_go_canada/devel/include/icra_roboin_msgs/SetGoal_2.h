// Generated by gencpp from file icra_roboin_msgs/SetGoal_2.msg
// DO NOT EDIT!


#ifndef ICRA_ROBOIN_MSGS_MESSAGE_SETGOAL_2_H
#define ICRA_ROBOIN_MSGS_MESSAGE_SETGOAL_2_H

#include <ros/service_traits.h>


#include <icra_roboin_msgs/SetGoal_2Request.h>
#include <icra_roboin_msgs/SetGoal_2Response.h>


namespace icra_roboin_msgs
{

struct SetGoal_2
{

typedef SetGoal_2Request Request;
typedef SetGoal_2Response Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetGoal_2
} // namespace icra_roboin_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::icra_roboin_msgs::SetGoal_2 > {
  static const char* value()
  {
    return "3adb4c2d2dfadd29c140f6e5796b855e";
  }

  static const char* value(const ::icra_roboin_msgs::SetGoal_2&) { return value(); }
};

template<>
struct DataType< ::icra_roboin_msgs::SetGoal_2 > {
  static const char* value()
  {
    return "icra_roboin_msgs/SetGoal_2";
  }

  static const char* value(const ::icra_roboin_msgs::SetGoal_2&) { return value(); }
};


// service_traits::MD5Sum< ::icra_roboin_msgs::SetGoal_2Request> should match 
// service_traits::MD5Sum< ::icra_roboin_msgs::SetGoal_2 > 
template<>
struct MD5Sum< ::icra_roboin_msgs::SetGoal_2Request>
{
  static const char* value()
  {
    return MD5Sum< ::icra_roboin_msgs::SetGoal_2 >::value();
  }
  static const char* value(const ::icra_roboin_msgs::SetGoal_2Request&)
  {
    return value();
  }
};

// service_traits::DataType< ::icra_roboin_msgs::SetGoal_2Request> should match 
// service_traits::DataType< ::icra_roboin_msgs::SetGoal_2 > 
template<>
struct DataType< ::icra_roboin_msgs::SetGoal_2Request>
{
  static const char* value()
  {
    return DataType< ::icra_roboin_msgs::SetGoal_2 >::value();
  }
  static const char* value(const ::icra_roboin_msgs::SetGoal_2Request&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::icra_roboin_msgs::SetGoal_2Response> should match 
// service_traits::MD5Sum< ::icra_roboin_msgs::SetGoal_2 > 
template<>
struct MD5Sum< ::icra_roboin_msgs::SetGoal_2Response>
{
  static const char* value()
  {
    return MD5Sum< ::icra_roboin_msgs::SetGoal_2 >::value();
  }
  static const char* value(const ::icra_roboin_msgs::SetGoal_2Response&)
  {
    return value();
  }
};

// service_traits::DataType< ::icra_roboin_msgs::SetGoal_2Response> should match 
// service_traits::DataType< ::icra_roboin_msgs::SetGoal_2 > 
template<>
struct DataType< ::icra_roboin_msgs::SetGoal_2Response>
{
  static const char* value()
  {
    return DataType< ::icra_roboin_msgs::SetGoal_2 >::value();
  }
  static const char* value(const ::icra_roboin_msgs::SetGoal_2Response&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ICRA_ROBOIN_MSGS_MESSAGE_SETGOAL_2_H
