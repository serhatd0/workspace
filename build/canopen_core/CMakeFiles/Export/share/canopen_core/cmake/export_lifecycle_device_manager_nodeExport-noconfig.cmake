#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_core::lifecycle_device_manager_node" for configuration ""
set_property(TARGET canopen_core::lifecycle_device_manager_node APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_core::lifecycle_device_manager_node PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblifecycle_device_manager_node.so"
  IMPORTED_SONAME_NOCONFIG "liblifecycle_device_manager_node.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_core::lifecycle_device_manager_node )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_core::lifecycle_device_manager_node "${_IMPORT_PREFIX}/lib/liblifecycle_device_manager_node.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
