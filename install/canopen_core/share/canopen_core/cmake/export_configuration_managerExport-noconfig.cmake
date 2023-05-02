#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_core::configuration_manager" for configuration ""
set_property(TARGET canopen_core::configuration_manager APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_core::configuration_manager PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libconfiguration_manager.so"
  IMPORTED_SONAME_NOCONFIG "libconfiguration_manager.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_core::configuration_manager )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_core::configuration_manager "${_IMPORT_PREFIX}/lib/libconfiguration_manager.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
