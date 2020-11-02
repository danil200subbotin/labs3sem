 cmake_minimum_required(VERSION 3.17)
 project(lab3byte3)

 include_directories(lib/googletest-master/googletest/include)
 include_directories(lib/googletest-master/googlemock/include)

 set(CMAKE_CXX_STANDARD 20)

 add_executable(lab3byte1 biglong.cpp biglong.h testwithgoogle.cpp)

 add_subdirectory(lib/googletest-master)
 target_link_libraries(lab3byte1 gtest gtest_main)