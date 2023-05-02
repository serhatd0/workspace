// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from canopen_interfaces:srv/COReadID.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__STRUCT_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__canopen_interfaces__srv__COReadID_Request __attribute__((deprecated))
#else
# define DEPRECATED__canopen_interfaces__srv__COReadID_Request __declspec(deprecated)
#endif

namespace canopen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct COReadID_Request_
{
  using Type = COReadID_Request_<ContainerAllocator>;

  explicit COReadID_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nodeid = 0;
      this->index = 0;
      this->subindex = 0;
      this->type = 0;
    }
  }

  explicit COReadID_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nodeid = 0;
      this->index = 0;
      this->subindex = 0;
      this->type = 0;
    }
  }

  // field types and members
  using _nodeid_type =
    uint8_t;
  _nodeid_type nodeid;
  using _index_type =
    uint16_t;
  _index_type index;
  using _subindex_type =
    uint8_t;
  _subindex_type subindex;
  using _type_type =
    uint8_t;
  _type_type type;

  // setters for named parameter idiom
  Type & set__nodeid(
    const uint8_t & _arg)
  {
    this->nodeid = _arg;
    return *this;
  }
  Type & set__index(
    const uint16_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__subindex(
    const uint8_t & _arg)
  {
    this->subindex = _arg;
    return *this;
  }
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    canopen_interfaces::srv::COReadID_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const canopen_interfaces::srv::COReadID_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::COReadID_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::COReadID_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__canopen_interfaces__srv__COReadID_Request
    std::shared_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__canopen_interfaces__srv__COReadID_Request
    std::shared_ptr<canopen_interfaces::srv::COReadID_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const COReadID_Request_ & other) const
  {
    if (this->nodeid != other.nodeid) {
      return false;
    }
    if (this->index != other.index) {
      return false;
    }
    if (this->subindex != other.subindex) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    return true;
  }
  bool operator!=(const COReadID_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct COReadID_Request_

// alias to use template instance with default allocator
using COReadID_Request =
  canopen_interfaces::srv::COReadID_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace canopen_interfaces


#ifndef _WIN32
# define DEPRECATED__canopen_interfaces__srv__COReadID_Response __attribute__((deprecated))
#else
# define DEPRECATED__canopen_interfaces__srv__COReadID_Response __declspec(deprecated)
#endif

namespace canopen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct COReadID_Response_
{
  using Type = COReadID_Response_<ContainerAllocator>;

  explicit COReadID_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->data = 0ul;
    }
  }

  explicit COReadID_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->data = 0ul;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _data_type =
    uint32_t;
  _data_type data;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__data(
    const uint32_t & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    canopen_interfaces::srv::COReadID_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const canopen_interfaces::srv::COReadID_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::COReadID_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::COReadID_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__canopen_interfaces__srv__COReadID_Response
    std::shared_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__canopen_interfaces__srv__COReadID_Response
    std::shared_ptr<canopen_interfaces::srv::COReadID_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const COReadID_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const COReadID_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct COReadID_Response_

// alias to use template instance with default allocator
using COReadID_Response =
  canopen_interfaces::srv::COReadID_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace canopen_interfaces

namespace canopen_interfaces
{

namespace srv
{

struct COReadID
{
  using Request = canopen_interfaces::srv::COReadID_Request;
  using Response = canopen_interfaces::srv::COReadID_Response;
};

}  // namespace srv

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__STRUCT_HPP_
