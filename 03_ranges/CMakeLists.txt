
cmake_minimum_required(VERSION 3.5)

project(dz_03_ranges)
find_package(GTest REQUIRED)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(ip_processor_rangesv3 
        ip_main.cpp 
        ip_loader.cpp
        ip_processor.cpp
)

set_target_properties(ip_processor_rangesv3 PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(ip_processor_rangesv3 ${CONAN_LIBS})

install(TARGETS ip_processor_rangesv3 RUNTIME DESTINATION bin)


# Tests

add_executable(test_out_01 
        test_out.cpp
        ip_loader.cpp
        ip_processor.cpp
)

set_target_properties(test_out_01 PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_link_libraries(test_out_01 PRIVATE
        GTest::GTest
        GTest::Main
)

set(TEST_03_RANGE_INP_FILE  ${CMAKE_SOURCE_DIR}/03_ranges/ip_filter-12995-758870.tsv)
add_test(NAME IpConfig::ranges COMMAND test_out_01 ${TEST_03_RANGE_INP_FILE} ip_out.txt)

# End of the file

