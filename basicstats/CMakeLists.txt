cmake_minimum_required(VERSION 3.26)
project(basicstats C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(basicstats main.c)
target_link_libraries(basicstats m)
