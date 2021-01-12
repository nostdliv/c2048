cmake_minimum_required(VERSION 3.15)
project(c2048)

add_subdirectory(CStrLL)

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "src/*.c")

add_executable(c2048 ${SRC})
target_link_libraries(c2048 PRIVATE CStrLL)
target_include_directories(c2048 PRIVATE include)
