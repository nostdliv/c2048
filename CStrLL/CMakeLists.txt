cmake_minimum_required(VERSION 3.15)
project(CStringLinkedList)
add_library(CStrLL STATIC CStringLinkedList.c)
target_include_directories(CStrLL PUBLIC .)
