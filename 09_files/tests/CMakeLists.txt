
cmake_minimum_required(VERSION 3.5)

project(dz_09_file_system_tests)
find_package(GTest REQUIRED)
find_package(Boost COMPONENTS
        program_options
        filesystem
        regex
        REQUIRED
)



enable_testing()

add_executable(test_fblocks_number
        test_file_blocks_number.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_block_file_proxy.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_block_files_holder.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_blocks_number_proxy.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_comparator_controller.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_comparator_engine.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_comparator_options.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_names_collection.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_option_labels.cpp
        ${CMAKE_SOURCE_DIR}/src/fs_printer.cpp
)

target_include_directories(test_fblocks_number PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties(test_fblocks_number PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_fblocks_number PRIVATE
        GTest::GTest
        GTest::Main
        ${Boost_LIBRARIES}
)

add_test(NAME HomeWork09::boost_file_system COMMAND test_fblocks_number)

# End of the file

