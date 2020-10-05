
cmake_minimum_required(VERSION 3.5)

project(dz_09_files)

find_package(Boost COMPONENTS 
        program_options
        filesystem
        regex	
        REQUIRED
)

set(FS09_LIB fs09comparator)
set(FS09_RUN fs09run)

add_library(${FS09_LIB} STATIC
        src/fs_base_file_proxy.cpp
        src/fs_block_file_proxy.cpp
        src/fs_block_files_holder.cpp
        src/fs_blocks_number_proxy.cpp
        src/fs_comparator_controller.cpp
        src/fs_comparator_engine.cpp
        src/fs_comparator_options.cpp
        src/fs_file_block_proxy.cpp
        src/fs_names_collection.cpp
        src/fs_option_labels.cpp
        src/fs_printer.cpp
)

add_executable(${FS09_RUN} 
        src/fs_main.cpp
)

set_target_properties(${FS09_RUN} ${FS09_LIB} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(${FS09_RUN} PUBLIC 
        ./include
)

target_include_directories(${FS09_LIB} PUBLIC 
        ./include
        ${Boost_INCLUDE_DIR}
)

target_link_libraries(${FS09_LIB} ${Boost_LIBRARIES})

target_link_libraries(${FS09_RUN} ${FS09_LIB})

install(TARGETS ${FS09_RUN} RUNTIME DESTINATION bin)

find_package(GTest REQUIRED)
enable_testing()
add_subdirectory(tests)

# End of the file

