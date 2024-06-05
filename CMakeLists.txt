cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY out)
set(CMAKE_BUILD_TYPE Release)

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
	set(CMAKE_CXX_FLAGS "-g")
	message(STATUS "Debug mode enabled")
endif()

project(OpenGL1)
add_subdirectory(lib/glad)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(main
	main.cpp)

target_link_libraries(main PRIVATE glad glfw OpenGL::GL)
