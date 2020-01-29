
cmake_minimum_required(VERSION 3.5)

project(dz_02)

add_executable(ip_processor 
	ip_main.cpp 
	ip_processor.cpp)

set_target_properties(ip_processor PROPERTIES
        CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
	)

install(TARGETS ip_processor RUNTIME DESTINATION bin)



# End of the file

