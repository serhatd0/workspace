// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from canopen_interfaces:srv/COWrite.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_WRITE__STRUCT_H_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_WRITE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/COWrite in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COWrite_Request
{
  uint16_t index;
  uint8_t subindex;
  uint32_t data;
  /// 8 = uint8_t, 16 = uint16_t, 32 = uint32_t
  uint8_t type;
} canopen_interfaces__srv__COWrite_Request;

// Struct for a sequence of canopen_interfaces__srv__COWrite_Request.
typedef struct canopen_interfaces__srv__COWrite_Request__Sequence
{
  canopen_interfaces__srv__COWrite_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COWrite_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/COWrite in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COWrite_Response
{
  bool success;
} canopen_interfaces__srv__COWrite_Response;

// Struct for a sequence of canopen_interfaces__srv__COWrite_Response.
typedef struct canopen_interfaces__srv__COWrite_Response__Sequence
{
  canopen_interfaces__srv__COWrite_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COWrite_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_WRITE__STRUCT_H_
