
cmake_minimum_required(VERSION 3.5)

project(dz_05_editor)
find_package(GTest REQUIRED)

enable_testing()

add_executable(run_editor 
	base_shape_2d.cpp
	circle_shape_2d.cpp
	color_engine.cpp
	composite_shape_2d.cpp
        default.cpp	
        document.cpp
        document_parameters.cpp	
        editor_core.cpp
        main.cpp
	point_2d.cpp
	triangle_shape_2d.cpp
)

set_target_properties(run_editor PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

install(TARGETS run_editor RUNTIME DESTINATION bin)

#add_subdirectory(tests)

# End of the file

