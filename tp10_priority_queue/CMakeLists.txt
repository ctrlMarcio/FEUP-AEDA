cmake_minimum_required(VERSION 3.10)
project(aeda1920_fp10)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1920_fp10 main.cpp test/tests.cpp src/object.cpp src/object.h src/box.cpp src/box.h src/packing_machine.cpp src/packing_machine.h src/empty_machine_exception.h)

target_link_libraries(aeda1920_fp10 gtest gtest_main)