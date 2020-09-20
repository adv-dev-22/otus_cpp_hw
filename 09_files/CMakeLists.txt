
cmake_minimum_required(VERSION 3.5)

project(dz_09_files)

find_package(Boost COMPONENTS program_options REQUIRED)

add_executable(run_fs 
        fs_comparator_controller.cpp
        fs_comparator_engine.cpp
        fs_comparator_options.cpp
        fs_main.cpp
        fs_names_collection.cpp
        fs_option_labels.cpp
        fs_printer.cpp
)

set_target_properties(run_fs PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(run_fs ${Boost_LIBRARIES})

install(TARGETS run_fs RUNTIME DESTINATION bin)


#find_package(GTest REQUIRED)
#enable_testing()

#add_subdirectory(tests)

# End of the file

