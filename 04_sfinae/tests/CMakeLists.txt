
cmake_minimum_required(VERSION 3.5)

project(dz_04_sfinae_tests)
find_package(GTest REQUIRED)

enable_testing()

add_executable(test_print_ip 
        test_print_ip.cpp
        ../print_ip_04.hpp
)

set_target_properties(test_print_ip PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_print_ip PRIVATE
        GTest::GTest
        GTest::Main
)

add_test(NAME HomeWork04::print_ip COMMAND test_print_ip)

# End of the file

