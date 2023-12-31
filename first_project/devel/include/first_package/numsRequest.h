// Generated by gencpp from file first_package/numsRequest.msg
// DO NOT EDIT!


#ifndef FIRST_PACKAGE_MESSAGE_NUMSREQUEST_H
#define FIRST_PACKAGE_MESSAGE_NUMSREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace first_package
{
template <class ContainerAllocator>
struct numsRequest_
{
  typedef numsRequest_<ContainerAllocator> Type;

  numsRequest_()
    : num1(0)
    , num2(0)  {
    }
  numsRequest_(const ContainerAllocator& _alloc)
    : num1(0)
    , num2(0)  {
  (void)_alloc;
    }



   typedef int32_t _num1_type;
  _num1_type num1;

   typedef int32_t _num2_type;
  _num2_type num2;





  typedef boost::shared_ptr< ::first_package::numsRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::first_package::numsRequest_<ContainerAllocator> const> ConstPtr;

}; // struct numsRequest_

typedef ::first_package::numsRequest_<std::allocator<void> > numsRequest;

typedef boost::shared_ptr< ::first_package::numsRequest > numsRequestPtr;
typedef boost::shared_ptr< ::first_package::numsRequest const> numsRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::first_package::numsRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::first_package::numsRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::first_package::numsRequest_<ContainerAllocator1> & lhs, const ::first_package::numsRequest_<ContainerAllocator2> & rhs)
{
  return lhs.num1 == rhs.num1 &&
    lhs.num2 == rhs.num2;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::first_package::numsRequest_<ContainerAllocator1> & lhs, const ::first_package::numsRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace first_package

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::first_package::numsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::first_package::numsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::first_package::numsRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::first_package::numsRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::first_package::numsRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::first_package::numsRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::first_package::numsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c68f3979e1a90aac7d1c75a1096d1e60";
  }

  static const char* value(const ::first_package::numsRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc68f3979e1a90aacULL;
  static const uint64_t static_value2 = 0x7d1c75a1096d1e60ULL;
};

template<class ContainerAllocator>
struct DataType< ::first_package::numsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "first_package/numsRequest";
  }

  static const char* value(const ::first_package::numsRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::first_package::numsRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# 客户端请求时发送的两个数字\n"
"int32 num1\n"
"int32 num2\n"
;
  }

  static const char* value(const ::first_package::numsRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::first_package::numsRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.num1);
      stream.next(m.num2);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct numsRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::first_package::numsRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::first_package::numsRequest_<ContainerAllocator>& v)
  {
    s << indent << "num1: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num1);
    s << indent << "num2: ";
    Printer<int32_t>::stream(s, indent + "  ", v.num2);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FIRST_PACKAGE_MESSAGE_NUMSREQUEST_H
