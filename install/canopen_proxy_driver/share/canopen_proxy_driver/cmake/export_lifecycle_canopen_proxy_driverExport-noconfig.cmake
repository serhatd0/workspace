#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_proxy_driver::lifecycle_canopen_proxy_driver" for configuration ""
set_property(TARGET canopen_proxy_driver::lifecycle_canopen_proxy_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_proxy_driver::lifecycle_canopen_proxy_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/liblifecycle_canopen_proxy_driver.so"
  IMPORTED_SONAME_NOCONFIG "liblifecycle_canopen_proxy_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_proxy_driver::lifecycle_canopen_proxy_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_proxy_driver::lifecycle_canopen_proxy_driver "${_IMPORT_PREFIX}/lib/liblifecycle_canopen_proxy_driver.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
