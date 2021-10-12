cmake_minimum_required(VERSION 3.20)
project(CSA_Task1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CSA_Task1
        container.cpp
        container.h
        functional.cpp
        functional.h
        language.cpp
        language.h
        main.cpp
        object_oriented.cpp
        object_oriented.h
        procedural.cpp
        procedural.h
        rnd.h)
