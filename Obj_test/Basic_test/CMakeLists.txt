include_directories(Obj_test/lib/googletest-release-1.8.1/googletest/include)
include_directories(Obj_test/lib/googletest-release-1.8.1/googlemock/include)

add_executable(runBasicClassTests
        basic_check.cpp)

target_link_libraries(runBasicClassTests gtest gtest_main)
target_link_libraries(runBasicClassTests code)