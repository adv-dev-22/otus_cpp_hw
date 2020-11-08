cmake_minimum_required(VERSION 3.5)

project(dz_12_asio_server)

find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads)
include_directories(${Boost_INCLUDE_DIR})

#add_library(asio_server_12 SHARED
	#        src/async_block_observer.cpp
	#src/async_block_state.cpp
	#src/async_data_block.cpp
	#src/async_data_processor.cpp
	#src/async_data_translator.cpp
	#src/async_interface.cpp
	#src/async_time_holder.cpp
	#)

add_executable(run_asio_server
        src/asio_main.cpp
)

##set_target_properties(run_bulk_async bulk_11_async PROPERTIES
#        CXX_STANDARD 17
#        CXX_STANDARD_REQUIRED ON
#)

#target_include_directories(bulk_11_async PUBLIC ./include)
#target_include_directories(run_bulk_async PUBLIC ./include)


#target_link_libraries(run_bulk_async bulk_11_async)


#End of the file
