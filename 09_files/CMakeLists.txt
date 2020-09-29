
cmake_minimum_required(VERSION 3.5)

project(dz_09_files)

find_package(Boost COMPONENTS 
        program_options
        filesystem
        regex	
        REQUIRED
)

add_executable(run_fs 
        src/fs_block_file_proxy.cpp
        src/fs_block_files_holder.cpp
        src/fs_blocks_number_proxy.cpp
	src/fs_comparator_controller.cpp
        src/fs_comparator_engine.cpp
        src/fs_comparator_options.cpp
        src/fs_main.cpp
        src/fs_names_collection.cpp
        src/fs_option_labels.cpp
        src/fs_printer.cpp
)

set_target_properties(run_fs PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_include_directories(run_fs PUBLIC ./include)

target_link_libraries(run_fs ${Boost_LIBRARIES})

install(TARGETS run_fs RUNTIME DESTINATION bin)

find_package(GTest REQUIRED)
#enable_testing()
#add_subdirectory(tests)

# End of the file

