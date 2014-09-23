project(meshproc)

cmake_minimum_required(VERSION 2.6)

set(meshproc_HEADERS point.h
                     polygon.h 
                     triangle.h 
                     rectangle.h 
                     square.h)

set(meshproc_SOURCES main.cpp
                     point.cpp
                     polygon.cpp 
                     triangle.cpp 
                     rectangle.cpp 
                     square.cpp)

add_executable(meshproc ${meshproc_HEADERS} ${meshproc_SOURCES})
