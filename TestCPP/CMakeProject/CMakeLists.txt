add_executable(prog main.cpp)

project (Catch)
add_library(catch INTERFACE)
target_include_directories(catch INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(tests main.cpp ${PROJECT_SOURCES})
target_link_libraries(tests PRIVATE catch)

cmake_minimum_required(VERSION 3.6)

# The project name
project(hello_cmake)

add_subdirectory(thirdparty/catch)
add_subdirectory(src)
add_subdirectory(test)