#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "udemy_ros2_pkg::udemy_ros2_pkg__rosidl_typesupport_c" for configuration "RelWithDebInfo"
set_property(TARGET udemy_ros2_pkg::udemy_ros2_pkg__rosidl_typesupport_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(udemy_ros2_pkg::udemy_ros2_pkg__rosidl_typesupport_c PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rosidl_runtime_c::rosidl_runtime_c;rosidl_typesupport_c::rosidl_typesupport_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libudemy_ros2_pkg__rosidl_typesupport_c.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libudemy_ros2_pkg__rosidl_typesupport_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS udemy_ros2_pkg::udemy_ros2_pkg__rosidl_typesupport_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_udemy_ros2_pkg::udemy_ros2_pkg__rosidl_typesupport_c "${_IMPORT_PREFIX}/lib/libudemy_ros2_pkg__rosidl_typesupport_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
