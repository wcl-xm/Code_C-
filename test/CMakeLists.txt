cmake_minimum_required(VERSION 3.16)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp)
add_executable(i i.cpp)

add_executable(polynomials polynomials.cpp)
add_executable(Chain_stack Chain_stack.cpp)
add_executable(queue queue.cpp)
add_executable(sqlist sqlist.cpp)
add_executable(hffuman hffuman.cpp)