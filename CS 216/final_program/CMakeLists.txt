PROJECT(final)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4 FATAL_ERROR)

SET(QT_USE_QTXML true)
SET(QT_USE_QTXMLPATTERNS true)
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

SET(final_source
  main.cpp
  processor.cpp
  account.cpp
  plan.cpp
  planfactory.cpp
  voice.cpp
  voicefactory.cpp
  text.cpp
  textfactory.cpp
  data.cpp
  datafactory.cpp)

SET(final_header
  processor.h
  account.h
  plan.h
  planfactory.h
  voice.h
  voicefactory.h
  text.h
  textfactory.h
  data.h
  datafactory.h)

SET(final_resources
  resource.qrc)

SET_SOURCE_FILES_PROPERTIES(resource.qrc
  PROPERTIES OBJECT_DEPENDS "plans.xsd")
  
SET_SOURCE_FILES_PROPERTIES(resource.qrc
  PROPERTIES OBJECT_DEPENDS "accounts.xsd")

QT4_ADD_RESOURCES(final_rc_files ${final_resources})

ADD_EXECUTABLE(final_test
  ${final_source}
  ${final_header}
  ${final_rc_files})

TARGET_LINK_LIBRARIES(final_test ${QT_LIBRARIES})
