
cmake_minimum_required(VERSION 3.5)

project(dz_03_allocator)
find_package(GTest REQUIRED)

add_executable(reserve_allocator 
        main_allocator.cpp  
        flexible_allocator.hpp
        fixed_sz_allocator.hpp
        custom_container.hpp
)

set_target_properties(reserve_allocator PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS reserve_allocator RUNTIME DESTINATION bin)


# Tests

add_executable(test_reserve_allocator
        test_allocator.cpp
        fixed_sz_allocator.hpp
)

set_target_properties(test_reserve_allocator PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_reserve_allocator PRIVATE
        GTest::GTest 
        GTest::Main
)

add_test(NAME HomeWork03::allocator COMMAND test_reserve_allocator)

# End of the file

