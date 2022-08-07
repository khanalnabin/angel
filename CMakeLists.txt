cmake_minimum_required(VERSION 3.4)
project(angel VERSION 1.0)

include_directories(
	include/
   	lib/glad/include/
)

file(GLOB VENDOR_SOURCES lib/glad/src/glad.c)
file(GLOB PROJECT_HEADERS include/*.hpp)
file(GLOB PROJECT_SOURCES src/*.cpp)

add_library(glad ${VENDOR_SOURCES})

add_library(angel ${PROJECT_SOURCES} ${PROJECT_HEADERS})
target_link_libraries(angel glad)

add_executable(demo examples/demo.cpp)
target_link_libraries(demo angel glad glfw)
