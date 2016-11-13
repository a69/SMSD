cmake_minimum_required(VERSION 2.8)
project(smsd)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") #CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using

set(SOURCE_FILES main.c struct.h default.h config.c config.h error.c error.h send.c send.h receive.c receive.h ussd.c ussd.h pppd.c pppd.h database.c database.h monitor.c monitor.h info.c info.h sms.c sms.h)
add_executable(smsd ${SOURCE_FILES})
include_directories(/usr/local/include/hiredis/)
include_directories(/usr/local/include/gammu)
target_link_libraries(smsd Gammu gsmsd hiredis)
