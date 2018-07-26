find_program(THRIFT_BINARY_DIR NAMES thrift PATHS ${PROJECT_DIR}/Third_Party/bin)
if(WIN32)
	find_library(THRIFT_LIBRARY_DIR NAMES thriftmd.lib PATHS ${PROJECT_DIR}/Third_Party/lib)
else()
	find_program(THRIFT_LIBRARY_DIR NAMES libthrift.so PATHS ${PROJECT_DIR}/Third_Party/lib)
endif()	
find_path(THRIFT_INCLUDE_DIR NAMES thrift/Thrift.h PATHS ${PROJECT_DIR}/Third_Party/include)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(thrift REQUIRED_VARS THRIFT_BINARY_DIR THRIFT_LIBRARY_DIR THRIFT_INCLUDE_DIR)

if(THRIFT_FOUND)
    message(STATUS "Found Thrift binary - ${Green}${THRIFT_BINARY_DIR}${ColourReset}")
    message(STATUS "Found Thrift library - ${Green}${THRIFT_LIBRARY_DIR}${ColourReset}")
    message(STATUS "Found Thrift include - ${Green}${THRIFT_INCLUDE_DIR}${ColourReset}")
else()
    message(WARNING ${Red}"Thrift not found"${ColourReset})
endif()
