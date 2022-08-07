cmake_minimum_required(VERSION 3.4)
project(angel VERSION 1.0)

include_directories(
	include/
   	lib/glad/include/
)

file(GLOB VENDOR_SOURCES lib/glad/src/glad.c)
file(GLOB PROJECT_HEADERS include/*.hpp)
file(GLOB PROJECT_SOURCES include/*.cpp)

add_library(angel ${PROJECT_SOURCES} ${PROJECT_HEADERS} ${VENDOR_SOURCES})
set_target_properties(angel PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(angel ${GLAD_LIBRARIES})
