cmake_minimum_required(VERSION 3.16)
project(hpx_matrix_multiplication CXX)

find_package(HPX REQUIRED)

add_executable(matrix_multiply src/main.cpp)
target_link_libraries(matrix_multiply HPX::hpx HPX::wrap_main)
target_compile_features(matrix_multiply PRIVATE cxx_std_17)
