
cmake_minimum_required(VERSION 3.5)

project(dz_11_bulk_async)

add_library(bulk_11_async SHARED 
	src/async_data_translator.cpp
        src/async_interface.cpp	
        src/async_time_holder.cpp
)

add_executable(run_bulk_async
        src/async_main.cpp
#    block_observer.cpp
#block_state.cpp
#data_block.cpp
#data_processor.cpp
)

set_target_properties(run_bulk_async bulk_11_async PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(bulk_11_async PUBLIC ./include)
target_include_directories(run_bulk_async PUBLIC ./include)


target_link_libraries(run_bulk_async bulk_11_async)

install(TARGETS run_bulk_async RUNTIME DESTINATION bin)

# End of the file


#find_package(GTest REQUIRED)
#enable_testing()


#add_subdirectory(tests)

