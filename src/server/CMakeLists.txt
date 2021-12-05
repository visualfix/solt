set(TARGET server)
set(OUT_DIR ${CMAKE_SOURCE_DIR}/bin)

# PThread 사용
find_package(Threads REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG TRUE)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)

# 코루틴 플래그 분기
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-fcoroutines-ts")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-fcoroutines")
endif()

add_executable(${TARGET} main.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/messages)
#target_include_directories(${TARGET} PRIVATE ${CMAKE_SOURCE_DIR}/include)


# PThread 사용
target_link_libraries(${TARGET} Threads::Threads)

set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${OUT_DIR})