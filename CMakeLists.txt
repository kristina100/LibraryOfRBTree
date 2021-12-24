cmake_minimum_required(VERSION 3.20)
project(RBTreeOfLibary)

set(CMAKE_CXX_STANDARD 14)

add_executable(RBTreeOfLibary main.cpp
        SourceFiles/BinarySearchTree.cpp
        SourceFiles/BalancedBinaryTree.cpp
        SourceFiles/BinaryTree.cpp
        SourceFiles/RedBlackTreeUtils.cpp
        SourceFiles/RedBlackTree.cpp

        HeaderFiles/BalancedBinaryTree.h
        HeaderFiles/BinarySearchTree.h
        HeaderFiles/BinaryTree.h
        HeaderFiles/RedBlackTree.h
        HeaderFiles/RedBlackTreeUtils.h)
