cmake_minimum_required (VERSION 3.7)
project (Nibbler-game)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory (Game)
add_subdirectory (ncurseslib)
add_subdirectory (sdllib)
add_subdirectory (sfmllib)
