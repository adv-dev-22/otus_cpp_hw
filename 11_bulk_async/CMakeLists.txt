
cmake_minimum_required(VERSION 3.5)

project(dz_11_bulk_async)
#find_package(GTest REQUIRED)

enable_testing()

add_executable(run_bulk_async
        src/async_interface.cpp	
        src/async_main.cpp
#    block_observer.cpp
#block_state.cpp
#data_block.cpp
#data_processor.cpp
#        data_translator.cpp
#time_holder.cpp
)

set_target_properties(run_bulk_async PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(run_bulk_async PUBLIC ./include)

install(TARGETS run_bulk_async RUNTIME DESTINATION bin)

#add_subdirectory(tests)

# End of the file

