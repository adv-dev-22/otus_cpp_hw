
cmake_minimum_required(VERSION 3.2)

if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    set(COMMON_TBN $ENV{TRAVIS_BUILD_NUMBER})
else()
    set(COMMON_TBN 1)
    message(WARNING "TRAVIS_BUILD_NUMBER env variable is undefined! It is set to 1.")
endif()

project(homeworks VERSION 4.1.${COMMON_TBN})

enable_testing()


if (HW01 OR HWALL)
    add_subdirectory(01)
endif()

if (HW02 OR HWALL)
    add_subdirectory(02)
    add_subdirectory(02_tuple)
endif()

if (HW03 OR HWALL)
    add_subdirectory(03_ranges)
    add_subdirectory(03_allocator)
endif()

if (HW04 OR HWALL)
    add_subdirectory(04_sfinae)
endif()

if (HW05 OR HWALL)
    add_subdirectory(05_editor)
endif()

if (HW06 OR HWALL)
    add_subdirectory(06_matrix)
endif()

if (HW07 OR HWALL)
    add_subdirectory(07_bulk)
endif()

if (HW09 OR HWALL)
    add_subdirectory(09_files)
endif()

if (HW10 OR HWALL)
    add_subdirectory(10_bulkmt)
endif()

if (HW11 OR HWALL)
    add_subdirectory(11_bulk_async)
endif()

if (HW12 OR HWALL)
    add_subdirectory(12_bulk_server)
endif()


set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)


# End of the main file

