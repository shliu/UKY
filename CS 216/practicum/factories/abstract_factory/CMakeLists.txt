project(factory)

cmake_minimum_required(VERSION 2.6)

set(QT_USE_QTXML true)
set(QT_USE_QTXMLPATTERNS true)

find_package(Qt4 4.6 REQUIRED)

include(${QT_USE_FILE})

set(factory_SOURCES main.cpp.in
                    ${PROJECT_BINARY_DIR}/main.cpp
                    shape.cpp
                    circle.cpp
                    square.cpp
                    rectangle.cpp
                    triangle.cpp
                    circlefactory.cpp
                    squarefactory.cpp
                    rectanglefactory.cpp
                    shapefactory.cpp
                    trianglefactory.cpp
                    mesh.cpp)

set(factory_HEADERS shape.h
                    circle.h
                    square.h
                    rectangle.h
                    triangle.h
                    circlefactory.h
                    squarefactory.h
                    rectanglefactory.h
                    trianglefactory.h
                    shapefactory.h
                    mesh.h)

set(factory_RESOURCES mesh.qrc)
set(factory_MISC_FILES mesh.xsd mesh.xml)

configure_file(main.cpp.in main.cpp)
configure_file(mesh.xml mesh.xml COPYONLY)
include_directories(${PROJECT_SOURCE_DIR})

set_source_files_properties(mesh.qrc 
                            PROPERTIES OBJECT_DEPENDS "mesh.xsd")

qt4_add_resources(factory_RC_FILES ${factory_RESOURCES})

add_executable(factory ${factory_SOURCES}
                       ${factory_HEADERS}
                       ${factory_RC_FILES}
                       ${factory_RESOURCES}
                       ${factory_MISC_FILES})

target_link_libraries(factory ${QT_LIBRARIES})
