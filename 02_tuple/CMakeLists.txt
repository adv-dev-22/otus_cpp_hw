
cmake_minimum_required(VERSION 3.5)

project(dz_02_tuple)

add_executable(custom_pair_exmpl cstm_pair_exmpl.cpp)

set_target_properties(custom_pair_exmpl PROPERTIES
        CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	)

install(TARGETS custom_pair_exmpl RUNTIME DESTINATION bin)

# End of the file

