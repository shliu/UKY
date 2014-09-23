project(hello)

set(LIBHELLO_VERSION 1.0)

cmake_minimum_required(VERSION 2.8)

configure_file(hello.cpp.in hello.cpp)

include_directories(${PROJECT_SOURCE_DIR})
add_library(hello SHARED hello.h ${PROJECT_BINARY_DIR}/hello.cpp)
add_executable(hellotest hellotest.cpp)

install(TARGETS hello DESTINATION lib)
install(FILES hello.h DESTINATION include)
install(TARGETS hellotest DESTINATION bin)

target_link_libraries(hellotest hello)
