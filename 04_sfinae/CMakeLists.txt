
cmake_minimum_required(VERSION 3.5)

project(dz_04_sfinae)
find_package(GTest REQUIRED)

add_executable(print_ip 
        main.cpp
        print_ip_04.hpp
)

set_target_properties(print_ip PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS print_ip RUNTIME DESTINATION bin)


# Tests

#add_executable(test_reserve_allocator
#test_allocator.cpp
#        fixed_sz_allocator.hpp
#)

#set_target_properties(test_reserve_allocator PROPERTIES
#        CXX_STANDARD 17
#CXX_STANDARD_REQUIRED ON
#)

#target_link_libraries(test_reserve_allocator PRIVATE
#        GTest::GTest 
#        GTest::Main
#)

#add_test(NAME HomeWork03::allocator COMMAND test_reserve_allocator)

# End of the file

