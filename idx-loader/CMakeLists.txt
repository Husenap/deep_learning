set(target_name "idx-loader")

set(src_files
    "src/IDXLoader.cpp"
    "src/IDXLoader.h")

add_library(${target_name} STATIC ${src_files})

source_group("src" FILES ${src_files})

target_link_libraries(${target_name} PUBLIC ${armadillo_libraries})
target_link_libraries(${target_name} PUBLIC "compiler-warnings")
target_include_directories(${target_name} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${armadillo_includes})

set_target_properties(${target_name} PROPERTIES FOLDER "DL")
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin )