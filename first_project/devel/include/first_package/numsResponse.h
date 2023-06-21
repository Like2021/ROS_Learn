// Generated by gencpp from file first_package/numsResponse.msg
// DO NOT EDIT!


#ifndef FIRST_PACKAGE_MESSAGE_NUMSRESPONSE_H
#define FIRST_PACKAGE_MESSAGE_NUMSRESPONSE_H


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
struct numsResponse_
{
  typedef numsResponse_<ContainerAllocator> Type;

  numsResponse_()
    : sum(0)  {
    }
  numsResponse_(const ContainerAllocator& _alloc)
    : sum(0)  {
  (void)_alloc;
    }



   typedef int32_t _sum_type;
  _sum_type sum;





  typedef boost::shared_ptr< ::first_package::numsResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::first_package::numsResponse_<ContainerAllocator> const> ConstPtr;

}; // struct numsResponse_

typedef ::first_package::numsResponse_<std::allocator<void> > numsResponse;

typedef boost::shared_ptr< ::first_package::numsResponse > numsResponsePtr;
typedef boost::shared_ptr< ::first_package::numsResponse const> numsResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::first_package::numsResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::first_package::numsResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::first_package::numsResponse_<ContainerAllocator1> & lhs, const ::first_package::numsResponse_<ContainerAllocator2> & rhs)
{
  return lhs.sum == rhs.sum;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::first_package::numsResponse_<ContainerAllocator1> & lhs, const ::first_package::numsResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace first_package

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::first_package::numsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::first_package::numsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::first_package::numsResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::first_package::numsResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::first_package::numsResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::first_package::numsResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::first_package::numsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0ba699c25c9418c0366f3595c0c8e8ec";
  }

  static const char* value(const ::first_package::numsResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0ba699c25c9418c0ULL;
  static const uint64_t static_value2 = 0x366f3595c0c8e8ecULL;
};

template<class ContainerAllocator>
struct DataType< ::first_package::numsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "first_package/numsResponse";
  }

  static const char* value(const ::first_package::numsResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::first_package::numsResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# 服务器响应发送的数据\n"
"int32 sum\n"
;
  }

  static const char* value(const ::first_package::numsResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::first_package::numsResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.sum);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct numsResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::first_package::numsResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::first_package::numsResponse_<ContainerAllocator>& v)
  {
    s << indent << "sum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sum);
  }
};

} // namespace message_operations
} // namespace ros

#endif // FIRST_PACKAGE_MESSAGE_NUMSRESPONSE_H
