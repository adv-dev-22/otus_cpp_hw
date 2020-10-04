
cmake_minimum_required(VERSION 3.5)

project(dz_09_file_system_tests)

find_package(GTest REQUIRED)

set(TEST_FS_BLOCKS_NUMBER test_fs_blocks_number)

add_executable(${TEST_FS_BLOCKS_NUMBER}
        test_file_blocks_number.cpp
)

target_include_directories(${TEST_FS_BLOCKS_NUMBER} PUBLIC ${CMAKE_SOURCE_DIR}/include)

set_target_properties(${TEST_FS_BLOCKS_NUMBER} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(${TEST_FS_BLOCKS_NUMBER} PRIVATE
        ${FS09_LIB}
	GTest::GTest
        GTest::Main
        ${Boost_LIBRARIES}
)

add_test(NAME HomeWork09::boost_file_system COMMAND ${TEST_FS_BLOCKS_NUMBER})

# End of the file

