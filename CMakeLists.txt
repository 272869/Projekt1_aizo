cmake_minimum_required(VERSION 3.28)
project(aizo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(aizo main.cpp
        Menu/Menu.cpp
        Menu/Menu.h
        Menu/Arrays.h
        Sorting_algorithms/QuickSort.cpp
        Sorting_algorithms/QuickSort.h
        Sorting_algorithms/ShellSort.cpp
        Sorting_algorithms/ShellSort.h
        Sorting_algorithms/HeapSort.cpp
        Sorting_algorithms/HeapSort.h
        Sorting_algorithms/InsertionSort.h)
