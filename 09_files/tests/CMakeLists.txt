
cmake_minimum_required(VERSION 3.5)

project(dz_09_file_system_tests)
find_package(GTest REQUIRED)

enable_testing()

add_executable(test_fblocks_number
        test_file_blocks_number.cpp
)

set_target_properties(test_fblocks_number PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_fblocks_number PRIVATE
        GTest::GTest
        GTest::Main
)

add_test(NAME HomeWork09::boost_file_system COMMAND test_fblocks_number)

# End of the file

