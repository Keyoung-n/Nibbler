cmake_minimum_required(VERSION 3.5.1)
project(snake)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(SOURCE_FILES
        main.cpp
        apples.cpp apples.hpp
        player.cpp player.hpp
        game.cpp game.hpp
        gui.cpp gui.hpp
        vector.h
        GUIInterface.hpp)

add_executable(snake ${SOURCE_FILES})
