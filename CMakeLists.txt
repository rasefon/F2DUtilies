cmake_minimum_required(VERSION 3.11)
project(HzF2dUtilies)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC
        src/*.cpp
        public/include/*.h
        include/*.h
        include/impl/*.hpp
        )

add_library(HzF2dUtilies ${SRC})

add_executable(main src/main.cpp)
target_link_libraries(main HzF2dUtilies)