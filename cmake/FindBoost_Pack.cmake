set(Boost_USE_MULTITHREADED ON)
# EOSIO build with boost static libs
#   set(Boost_USE_STATIC_LIBS OFF)
find_package(Boost 1.58.0)

if(Boost_FOUND)
    message(STATUS "Found Boost include dir - ${Green}${Boost_INCLUDE_DIR}${ColourReset}")
    message(STATUS "Found Boost library dir - ${Green}${Boost_LIBRARY_DIR_RELEASE}${ColourReset}")
else()
    message(WARNING ${Red}"Boost not found"${ColourReset})
endif()
