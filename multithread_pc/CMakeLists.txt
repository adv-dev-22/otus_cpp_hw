cmake_minimum_required(VERSION 3.10)
project(ProducerConsumer VERSION 1.0.0 LANGUAGES CXX)

add_executable(pc_run 
        main.cpp
        mlt_thr_data_server.cpp
        prod_cons_simulator.cpp
)

set_target_properties(pc_run PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(pc_run pthread)

# End of the file

