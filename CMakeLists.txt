cmake_minimum_required(VERSION 3.15)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

message(STATUS "start running cmake...")
find_package(Boost 1.67.0)

if(Boost_FOUND)

    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARIES: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(/usr/local/include)
endif()

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
    Common.h
    EasySolution.cpp
    EasySolution.h
    OfferSolution.cpp
    OfferSolution.h
    BinarySearchSolution.cpp
    BinarySearchSolution.h
    DoublePtrSolution.cpp
    DoublePtrSolution.h
    StackSolution.cpp
    StackSolution.h
    BackTrackingSolution.cpp
    BackTrackingSolution.h
    ConcurrentSolution.cpp
    ConcurrentSolution.h
    HashSolution.cpp
    HashSolution.h
    HeapSolution.cpp
    HeapSolution.h Graph.cpp Graph.h FooBar.h StackSolutions.cpp StackSolutions.h MinStack.h "RandomPickSolutionWithBLSolution.h")
#
#if(Boost_FOUND)
#
#    target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
#
#endif()
