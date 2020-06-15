
cmake_minimum_required(VERSION 3.5)

project(dz_06_matrix_tests)
find_package(GTest REQUIRED)

enable_testing()

add_executable(test_inf_matrix 
        test_inf_matrix.cpp
        ../infinite_row.h
)

set_target_properties(test_inf_matrix PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_inf_matrix PRIVATE
        GTest::GTest
        GTest::Main
)

add_test(NAME HomeWork06::infinite_matrix COMMAND test_inf_matrix)

# End of the file

