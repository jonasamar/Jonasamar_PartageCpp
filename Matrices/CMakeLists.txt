cmake_minimum_required(VERSION 3.0.0)
project(test01 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(test01 main.cpp main.cpp Matrix.cpp tests_q1.cpp question2.cpp question3.cpp question4.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
