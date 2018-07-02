find_path(SPDLOG_INCLUDE_DIR NAMES spdlog/spdlog.h PATHS ${PROJECT_DIR}/Third_Party/include NO_DEFAULT_PATH)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(spdlog REQUIRED_VARS SPDLOG_INCLUDE_DIR)

if(SPDLOG_FOUND)
    message(STATUS ${Green}"Found SpdLog include dir - ${SPDLOG_INCLUDE_DIR}"${ColourReset})
else()
    message(WARNING ${Red}"SpdLog not found"${ColourReset})
endif()

