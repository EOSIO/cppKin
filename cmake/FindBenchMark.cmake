find_path(BENCHMARK_INCLUDE_DIR NAMES benchmark PATHS ${PROJECT_3RD_LOC}/include)
find_library(BENCHMARK_LIBRARY_DIR NAMES benchmark PATHS ${PROJECT_3RD_LOC}/lib)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(benchmark REQUIRED_VARS BENCHMARK_INCLUDE_DIR BENCHMARK_LIBRARY_DIR)

if(BENCHMARK_FOUND)
    message(STATUS "Found Benchmark include dir - ${Green}${BENCHMARK_INCLUDE_DIR}${ColourReset}")
    message(STATUS "Found Benchmark library dir - ${Green}${BENCHMARK_LIBRARY_DIR}${ColourReset}")
else()
    message(WARNING ${Red}"Benchmark not found"${ColourReset})
endif()
