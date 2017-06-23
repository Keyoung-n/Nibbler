cmake_minimum_required(VERSION 3.7)
project(SDL-lib)

set(CMAKE_CXX_STANDARD 14)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES sdllib.cpp sdllib.hpp)

ADD_LIBRARY(SDL SHARED ${SOURCE_FILES})
target_link_libraries(SDL ${SDL2_LIBRARIES})
