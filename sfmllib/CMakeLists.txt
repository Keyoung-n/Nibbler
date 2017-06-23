cmake_minimum_required(VERSION 3.7)
project (SFML)
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

find_package(SFML REQUIRED network audio graphics window system)
set(SOURCE_FILES sfmllib.cpp)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    link_directories(${SFML_INCLUDE_DIR} ~/.brew/Cellar/sfml/2.4.2/lib/ )
    ADD_LIBRARY(SFML SHARED ${SOURCE_FILES})
    target_link_libraries(SFML ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
