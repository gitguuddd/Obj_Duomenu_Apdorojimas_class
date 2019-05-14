cmake_minimum_required(VERSION 3.13)
project(Obj_Duomenu_apdorojimas)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 ")
add_executable(Obj_Duomenu_apdorojimas main.cpp )

include_directories(code)
add_subdirectory(code)
add_subdirectory(Obj_test)

target_link_libraries(Obj_Duomenu_apdorojimas code)