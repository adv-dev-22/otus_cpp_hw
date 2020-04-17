
cmake_minimum_required(VERSION 3.5)

project(dz_04_sfinae)
find_package(GTest REQUIRED)

enable_testing()

add_executable(print_ip 
        main.cpp
        print_ip_04.hpp
)

set_target_properties(print_ip PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS print_ip RUNTIME DESTINATION bin)

add_subdirectory(tests)

# End of the file

