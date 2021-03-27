cmake_minimum_required(VERSION 3.0.0)
project(PthreadOnLinux VERSION 0.1.0)

# include(CTest)
# enable_testing()

# add_executable(PthreadOnLinux main.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

# C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message("CMAKE_CXX_STANDARD: ${CMAKE_CXX_STANDARD}")

add_subdirectory(ch02_management_of_thread)
add_subdirectory(ch03_sharing_data_on_threads)
add_subdirectory(ch04_exclusion_control)
add_subdirectory(ch05_wating_condition)
add_subdirectory(ch06_practice_thread_safe_queue)
add_subdirectory(ch07_design_pattern_of_thread)
add_subdirectory(ch08_socket_programming)

