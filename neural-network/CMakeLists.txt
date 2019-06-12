set(target_name "neural-network")

set(src_files
    "src/NeuralNetwork.cpp"
    "src/NeuralNetwork.h"
    "src/main.cpp")

add_executable(${target_name} ${src_files})

source_group("src" FILES ${src_files})

target_link_libraries(${target_name} PUBLIC ${armadillo_libraries})
target_link_libraries(${target_name} PUBLIC "idx-loader")
target_link_libraries(${target_name} PUBLIC "compiler-warnings")
target_include_directories(${target_name} PUBLIC ${armadillo_includes})

set_target_properties(${target_name} PROPERTIES FOLDER "DL")
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${target_name} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin )