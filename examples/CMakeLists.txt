link_libraries(
    ${armadillo_libraries}
    "idx-loader"
    "compiler-warnings")

include_directories(
    ${armadillo_includes}
    "../idx-loader/src")

add_executable(print_MNIST_digits print_MNIST_digits.cpp)

set(example_binaries print_MNIST_digits)


set_target_properties(${example_binaries} PROPERTIES FOLDER "DL/examples")
set_target_properties(${example_binaries} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${example_binaries} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${example_binaries} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${example_binaries} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${example_binaries} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_HOME_DIRECTORY}/bin )
set_target_properties(${example_binaries} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin )