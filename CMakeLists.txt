cmake_minimum_required (VERSION 3.1)
project(Solt LANGUAGES CXX)

# C++ 17
set(CMAKE_CXX_STANDARD 17)
# 이 옵션을 OFF인 경우 CXX_STANDARD설정이 옵션으로 판단되어 낮을 버전으로 수행될 수 있다.
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# GNU 확장을 사용하지 않는다
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include/boost_1_77_0)
include_directories(${PROJECT_SOURCE_DIR}/include/asio)

add_subdirectory(src)
