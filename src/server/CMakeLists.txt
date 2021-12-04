set(TARGET server)
set(OUT_DIR ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_CXX_FLAGS "-fcoroutines-ts")

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(${TARGET} main.cpp)

target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${TARGET} Threads::Threads)

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})