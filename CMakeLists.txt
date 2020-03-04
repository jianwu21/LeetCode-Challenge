cmake_minimum_required(VERSION 3.15)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        LeetCode
        LeetCode.cpp
        DynamicProgrammingSolution.cpp
        DynamicProgrammingSolution.h
        LinkedListSolution.cpp
        LinkedListSolution.h
        TreeSolution.cpp
        TreeSolution.h
        MathSolution.cpp
        MathSolution.h
        FunSolution.cpp
        FunSolution.h
        SortAlgorithm.cpp
        SortAlgorithm.h
        Common.h EasySolution.cpp EasySolution.h OfferSolution.cpp OfferSolution.h BinarySearchSolution.cpp BinarySearchSolution.h)