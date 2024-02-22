cmake_minimum_required(VERSION 3.25)
project(DataStructAlg)

set(CMAKE_CXX_STANDARD 11)



add_executable(DataStructAlg main.cpp 02_circular_array.h 03_linked_list.h 01_array.h 04_double_linked_list.h 06_STL_binary_tree.h 07_hash_table.h random_generator.h 05_custom_binary_tree.h)

set_target_properties(DataStructAlg PROPERTIES LINK_FLAGS -Wl,--stack,1000000000)

