cmake_minimum_required(VERSION 3.0)
project(Isaarg)
add_definitions(-std=c++17)
set(SRCS
src/main.cpp
)
include_directories(Isaarg PRIVATE ./src ./test)
add_executable(Isaarg ${SRCS})
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/Isaarg DESTINATION bin)
