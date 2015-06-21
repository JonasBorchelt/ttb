cmake_minimum_required (VERSION 2.8)
project (ttb)

include_directories(src/)

add_executable(ttb src/main.cpp src/civetweb.c src/CivetServer.cpp)