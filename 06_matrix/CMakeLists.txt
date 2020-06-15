
cmake_minimum_required(VERSION 3.5)

project(dz_06_matrix)
find_package(GTest REQUIRED)

enable_testing()

add_executable(run_matrix 
        main.cpp
        infinite_row.h
)

set_target_properties(run_matrix PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS run_matrix RUNTIME DESTINATION bin)

add_subdirectory(tests)

# End of the file

