
cmake_minimum_required(VERSION 3.5)

project(dz_09_files)

#find_package(GTest REQUIRED)
#enable_testing()

add_executable(run_fs 
        main.cpp
	#block_observer.cpp
	#block_state.cpp
	#data_block.cpp
	#data_processor.cpp
	#data_translator.cpp
	#time_holder.cpp
)

set_target_properties(run_fs PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS run_fs RUNTIME DESTINATION bin)

#add_subdirectory(tests)

# End of the file

