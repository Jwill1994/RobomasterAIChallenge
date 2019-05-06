// Generated by gencpp from file icra_roboin_msgs/BlackboardGeneralInfo.msg
// DO NOT EDIT!


#ifndef ICRA_ROBOIN_MSGS_MESSAGE_BLACKBOARDGENERALINFO_H
#define ICRA_ROBOIN_MSGS_MESSAGE_BLACKBOARDGENERALINFO_H

#include <ros/service_traits.h>


#include <icra_roboin_msgs/BlackboardGeneralInfoRequest.h>
#include <icra_roboin_msgs/BlackboardGeneralInfoResponse.h>


namespace icra_roboin_msgs
{

struct BlackboardGeneralInfo
{

typedef BlackboardGeneralInfoRequest Request;
typedef BlackboardGeneralInfoResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct BlackboardGeneralInfo
} // namespace icra_roboin_msgs


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfo > {
  static const char* value()
  {
    return "b163c0ce1011a983e5ca043d25ff9b1c";
  }

  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfo&) { return value(); }
};

template<>
struct DataType< ::icra_roboin_msgs::BlackboardGeneralInfo > {
  static const char* value()
  {
    return "icra_roboin_msgs/BlackboardGeneralInfo";
  }

  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfo&) { return value(); }
};


// service_traits::MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfoRequest> should match 
// service_traits::MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfo > 
template<>
struct MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfoRequest>
{
  static const char* value()
  {
    return MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfo >::value();
  }
  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfoRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::icra_roboin_msgs::BlackboardGeneralInfoRequest> should match 
// service_traits::DataType< ::icra_roboin_msgs::BlackboardGeneralInfo > 
template<>
struct DataType< ::icra_roboin_msgs::BlackboardGeneralInfoRequest>
{
  static const char* value()
  {
    return DataType< ::icra_roboin_msgs::BlackboardGeneralInfo >::value();
  }
  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfoRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfoResponse> should match 
// service_traits::MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfo > 
template<>
struct MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfoResponse>
{
  static const char* value()
  {
    return MD5Sum< ::icra_roboin_msgs::BlackboardGeneralInfo >::value();
  }
  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfoResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::icra_roboin_msgs::BlackboardGeneralInfoResponse> should match 
// service_traits::DataType< ::icra_roboin_msgs::BlackboardGeneralInfo > 
template<>
struct DataType< ::icra_roboin_msgs::BlackboardGeneralInfoResponse>
{
  static const char* value()
  {
    return DataType< ::icra_roboin_msgs::BlackboardGeneralInfo >::value();
  }
  static const char* value(const ::icra_roboin_msgs::BlackboardGeneralInfoResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // ICRA_ROBOIN_MSGS_MESSAGE_BLACKBOARDGENERALINFO_H
