cmake_minimum_required(VERSION 4.2)
project(impl_lockfree_mpmc)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_DIRECTORY ${CMAKE_SOURCE_DIR}/output)

add_subdirectory(src)