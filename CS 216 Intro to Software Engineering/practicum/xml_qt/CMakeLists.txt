PROJECT(xml)
CMAKE_MINIMUM_REQUIRED(VERSION 2.4 FATAL_ERROR)

SET(QT_USE_QTXML true)
SET(QT_USE_QTXMLPATTERNS true)
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

SET(xml_source
  main.cpp
  address.cpp
  addressprocessor.cpp)

SET(xml_header
  address.h
  addressprocessor.h)

SET(xml_resources
  addresslist.qrc)

SET_SOURCE_FILES_PROPERTIES(addresslist.qrc
  PROPERTIES OBJECT_DEPENDS "addresslist.xsd")

QT4_ADD_RESOURCES(xml_rc_files ${xml_resources})

ADD_EXECUTABLE(xml_test
  ${xml_source}
  ${xml_header}
  ${xml_rc_files})

TARGET_LINK_LIBRARIES(xml_test ${QT_LIBRARIES})
