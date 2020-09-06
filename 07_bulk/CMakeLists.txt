
cmake_minimum_required(VERSION 3.5)

project(dz_07_bulk)
#find_package(GTest REQUIRED)

enable_testing()

add_executable(run_bulk 
        main.cpp
        block_observer.cpp
        data_block.cpp
        data_processor.cpp
        data_translator.cpp
)

set_target_properties(run_bulk PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS run_bulk RUNTIME DESTINATION bin)

#add_subdirectory(tests)

# End of the file

