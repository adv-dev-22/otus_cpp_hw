
cmake_minimum_required(VERSION 3.2)
project(homeworks VERSION 0.0.1)

enable_testing()


if (HW01 OR HWALL)
    add_subdirectory(01)
endif()

if (HW02 OR HWALL)
    add_subdirectory(02)
endif()


set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)


# End of the main file

