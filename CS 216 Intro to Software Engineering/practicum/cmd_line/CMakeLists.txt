PROJECT(cmdline)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(cmdline_sources
  main.cpp)

ADD_EXECUTABLE(cmdline_test ${cmdline_sources})
