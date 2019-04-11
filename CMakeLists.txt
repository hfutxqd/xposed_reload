cmake_minimum_required(VERSION 3.13)
project(XposedTools C)

set(CMAKE_C_STANDARD 99)

add_executable(XposedTools jni/main.c)