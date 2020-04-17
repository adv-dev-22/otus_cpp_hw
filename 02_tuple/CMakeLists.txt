
cmake_minimum_required(VERSION 3.5)

project(dz_02_tuple)

add_executable(custom_pair_exmpl    cstm_pair_exmpl.cpp)
add_executable(custom_pair_exmpl_2  cstm_pair_exmpl_2.cpp)
add_executable(cstm_tuple_exmpl     cstm_tuple_exmpl.cpp)

set_target_properties(custom_pair_exmpl 
        custom_pair_exmpl_2 
        cstm_tuple_exmpl
    PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS custom_pair_exmpl custom_pair_exmpl_2 cstm_tuple_exmpl RUNTIME DESTINATION bin)

# End of the file

