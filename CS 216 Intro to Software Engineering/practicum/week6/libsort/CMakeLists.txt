set(LIBSORT_HEADERS
  ${PROJECT_SOURCE_DIR}/sort/sortablebase.h
  ${PROJECT_SOURCE_DIR}/sort/timer.h)
set(LIBSORT_SOURCES
  ${PROJECT_SOURCE_DIR}/libsort/sortablebase.cpp
  ${PROJECT_SOURCE_DIR}/libsort/timer.cpp)
add_library(sort SHARED
  ${LIBSORT_HEADERS}
  ${LIBSORT_SOURCES})
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${LIBSORT_HEADERS} DESTINATION include/sort)

