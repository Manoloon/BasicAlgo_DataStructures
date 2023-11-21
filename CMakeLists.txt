cmake_minimum_required(VERSION 3.0)
project(Algorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algorithms main.cpp Src/Union_Find.h Src/QuickUnion.h)
