cmake_minimum_required(VERSION 3.5)

project(dz_12_asio_server)

find_package(Boost COMPONENTS system REQUIRED)
find_package(Threads)
include_directories(${Boost_INCLUDE_DIR})

add_library(asio_server_12 SHARED
        src/asio_bulk_controller.cpp
        src/asio_bulk_server.cpp
        src/asio_bulk_session.cpp
)

#src/async_block_state.cpp
#src/async_data_block.cpp
#src/async_data_processor.cpp
#src/async_data_translator.cpp
#src/async_interface.cpp
#src/async_time_holder.cpp

add_executable(run_asio_server
        src/asio_bulk_main.cpp
)

set_target_properties(run_asio_server asio_server_12 PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(asio_server_12 PUBLIC ./include)
target_include_directories(run_asio_server PUBLIC ./include)

target_link_libraries(run_asio_server 
        asio_server_12
        ${Boost_LIBRARIES}
        ${CMAKE_THREAD_LIBS_INIT}
)

#End of the file
