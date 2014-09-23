PROJECT(mvc)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4 FATAL_ERROR)

FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

SET(mvc_source
  main.cpp
  namemodel.cpp
  nameview.cpp
  namefirstview.cpp
  namelastview.cpp
  namecontroller.cpp)

SET(mvc_header
  namemodel.h
  nameview.h
  namefirstview.h
  namelastview.h
  namecontroller.h)

QT4_WRAP_CPP(mvc_moc
  ${mvc_header})

ADD_EXECUTABLE(mvc_test
  ${mvc_source}
  ${mvc_header}
  ${mvc_moc})  

TARGET_LINK_LIBRARIES(mvc_test ${QT_LIBRARIES})
