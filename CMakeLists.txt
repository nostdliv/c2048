cmake_minimum_required(VERSION 3.12)
project(c2048)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "src/*.c")

add_executable(c2048 ${SRC})
target_include_directories(c2048 PRIVATE include)
