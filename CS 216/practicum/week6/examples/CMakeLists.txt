add_executable(sorttest main.cpp sortable.h sortable.cpp)
target_link_libraries(sorttest ${PROJECT_NAME})
install(TARGETS sorttest DESTINATION bin)
