cmake_minimum_required(VERSION 3.2)

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(COMMON_TBN $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(COMMON_TBN 1)
    message(WARNING "TRAVIS_BUILD_NUMBER env variable is undefined! It is set to 1.")
endif()	

project(helloworld VERSION 0.0.${COMMON_TBN})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)
add_library(hw_version vers_lib.cpp)
add_executable(test_vers_boost test_vers_boost.cpp)
add_executable(test_vers_gtest test_vers_gtest.cpp)

set_target_properties(
	helloworld_cli 
	hw_version 
	test_vers_boost 
	test_vers_gtest  
    PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_vers_boost PROPERTIES 
    COMPILE_DEFINITIONS  BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES  ${Boost_INCLUDE_DIR}
)

target_include_directories(hw_version
    PRIVATE "${CMAKE_BINARY_DIR}/01"
)

target_link_libraries(helloworld_cli PRIVATE
    hw_version
)

target_link_libraries(test_vers_boost PRIVATE
    ${Boost_LIBRARIES}
    hw_version
)

target_link_libraries(test_vers_gtest PRIVATE
    GTest::GTest 
    GTest::Main
    hw_version	
)

if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(hw_version PRIVATE
        /W4
    )
    target_compile_options(test_vers_boost PRIVATE
        /W4
    )
    target_compile_options(test_vers_gtest PRIVATE
        /W4
    )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(hw_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_vers_boost PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_vers_gtest PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

#set(CPACK_GENERATOR DEB)

#set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
#set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
#set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

#set(CPACK_PACKAGE_CONTACT example@example.com)

#include(CPack)

#enable_testing()

add_test(Versions::boost_test test_vers_boost)
add_test(Versions::gtest_test test_vers_gtest)


# End of the file
