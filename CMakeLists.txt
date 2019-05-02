cmake_minimum_required(VERSION 3.13)
project(Obj_Duomenu_apdorojimas)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")
set(CMAKE_CXX_FLAGS "-O3 ")

set(CMAKE_CXX_STANDARD 14)

add_executable(Obj_Duomenu_apdorojimas main.cpp Input.h Output.h Input.cpp Output.cpp Mutual.h Mutual.cpp classes/stud/stud.h classes/stud/stud.cpp classes/Timer/Timer.h)