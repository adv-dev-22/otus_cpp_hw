
cmake_minimum_required(VERSION 3.5)

project(dz_10_mt_bulk)

set(MTB10_LIB mtbulk10)
set(MTB10_RUN mtb10run)

add_library(${MTB10_LIB} STATIC
        src/mtb_block_observer.cpp
        src/mtb_block_state.cpp
        src/mtb_data_block.cpp
        src/mtb_data_processor.cpp
        src/mtb_data_translator.cpp
        src/mtb_time_holder.cpp
)

add_executable(${MTB10_RUN} 
        src/mtb_main.cpp
)

set_target_properties(${MTB10_RUN} ${MTB10_LIB} 
        PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(${MTB10_RUN} PUBLIC 
        ./include
)

target_include_directories(${MTB10_LIB} PUBLIC 
        ./include
)

#target_link_libraries(${FS09_LIB} ${Boost_LIBRARIES})

target_link_libraries(${MTB10_RUN} ${MTB10_LIB})

#install(TARGETS ${FS09_RUN} RUNTIME DESTINATION bin)

#find_package(GTest REQUIRED)
#enable_testing()
#add_subdirectory(tests)

# End of the file

