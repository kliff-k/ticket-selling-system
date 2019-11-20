cmake_minimum_required(VERSION 3.15)
project(tp_cpp)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/linux")
set(CMAKE_CXX_FLAGS "-std=c++17 -lpqxx -lncurses")

include_directories("/data/projects/frameworks")
link_directories("/data/projects/frameworks/pdcurses/unix/")

add_executable(tp_cpp src/main.cpp src/Dominios.cpp src/Dominios.h src/Entidades.cpp src/Entidades.h src/Servicos.cpp src/Servicos.h src/Apresentacao.cpp src/Apresentacao.h)