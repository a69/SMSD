cmake_minimum_required(VERSION 3.0)
project(smsd)


include_directories("/usr/include/gammu")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") #CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using

set(SOURCE_FILES main.c struct.h default.h config.c config.h error.c error.h send.c send.h receive.c receive.h ussd.c ussd.h pppd.c pppd.h database.c database.h monitor.c monitor.h info.c info.h)
add_executable(smsd ${SOURCE_FILES})

include(FindPkgConfig)
find_package(Hiredis REQUIRED)

#find_package(Gammu REQUIRED)
include_directories(${LIBHIREDIS_INCLUDE_DIR})
target_link_libraries(smsd Gammu gsmsd ${LIBHIREDIS_LIBRARIES})