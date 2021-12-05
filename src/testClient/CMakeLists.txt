message(STATUS "----------------------------------------------")
message(STATUS "Build TEST ${TARGET}")
message(STATUS "----------------------------------------------")

set(TARGET client)
set(OUT_DIR ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(${TARGET} main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/messages)
#target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${TARGET} Threads::Threads)

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})