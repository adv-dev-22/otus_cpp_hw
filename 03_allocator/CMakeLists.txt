
cmake_minimum_required(VERSION 3.5)

project(dz_03_allocator)
find_package(GTest REQUIRED)

add_executable(custom_allocator main_allocator.cpp  custom_allocator.hpp)

set_target_properties(custom_allocator PROPERTIES
        CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

install(TARGETS custom_allocator RUNTIME DESTINATION bin)


# Tests

add_executable(test_custom_allocator
	test_allocator.cpp
)

set_target_properties(test_custom_allocator PROPERTIES
        CXX_STANDARD 17
	CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_custom_allocator PRIVATE
        GTest::GTest 
        GTest::Main
)

add_test(NAME HomeWork03::allocator COMMAND test_custom_allocator)

# End of the file

