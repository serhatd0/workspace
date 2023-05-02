#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "canopen_402_driver::canopen_402_driver" for configuration ""
set_property(TARGET canopen_402_driver::canopen_402_driver APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(canopen_402_driver::canopen_402_driver PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libcanopen_402_driver.so"
  IMPORTED_SONAME_NOCONFIG "libcanopen_402_driver.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS canopen_402_driver::canopen_402_driver )
list(APPEND _IMPORT_CHECK_FILES_FOR_canopen_402_driver::canopen_402_driver "${_IMPORT_PREFIX}/lib/libcanopen_402_driver.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
