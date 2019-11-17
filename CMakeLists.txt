cmake_minimum_required(VERSION 3.15)
project(tp_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tp_cpp src/main.cpp src/Dominios.cpp src/Dominios.h src/Entidades.cpp src/Entidades.h)

#cmake_minimum_required(VERSION 3.14)
#project(tp)
#
#set(CMAKE_CXX_STANDARD 14)
#
#set(LIBS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs")
#set(CMAKE_PREFIX_PATH "${LIBS_PATH}/qt/5.13.0/lib/cmake")
#
#include_directories(${LIBS_PATH})
#
#find_package(Qt5Core REQUIRED)
#find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Quick REQUIRED)
#
#add_executable(tp main.cpp)
#
#IF(UNIX)
#    set(CMAKE_CXX_FLAGS "-std=c++17 -lncurses")
#
#    link_directories("${LIBS_PATH}/pdcurses/unix/")
#ELSE (WIN32)
#    set(CMAKE_CXX_FLAGS "/std:c++latest")
#
#    link_directories("${LIBS_PATH}/pdcurses/windows/")
#ENDIF (UNIX)
#
#target_link_libraries(tp Qt5::Core)
#target_link_libraries(tp Qt5::Widgets)
#target_link_libraries(tp Qt5::Quick)