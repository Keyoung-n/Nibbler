cmake_minimum_required(VERSION 3.5.1)
project(ncurses-lib)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES ncurseslib.cpp ncurseslib.hpp)

ADD_LIBRARY(ncurses SHARED ${SOURCE_FILES})
target_link_libraries(ncurses ${CURSES_LIBRARIES})
