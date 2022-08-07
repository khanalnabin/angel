cmake_minimum_required(VERSION 3.4)
project(angel VERSION 1.0)

add_library(angel src/Angel.cpp deps/glad/src/glad.cpp)
target_include_directories(angel PRIVATE include deps/glad/include)
target_link_libraries(angel ${GLAD_LIBRARIES})

add_executable(demo examples/demo.cpp)
target_include_directories(demo PRIVATE include deps/glad/include)
target_link_libraries(demo angel ${GLAD_LIBRARIES})
