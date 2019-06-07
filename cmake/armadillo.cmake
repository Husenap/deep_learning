message("-- Armadillo")
set(target_name "armadillo")

add_subdirectory("third-party/armadillo-code")

set(armadillo_libraries
    ${target_name})

set(armadillo_includes
    "${CMAKE_CURRENT_SOURCE_DIR}/third-party/armadillo-code/include")

set_target_properties(${target_name} PROPERTIES FOLDER "third-party//armadillo")

target_compile_definitions(${target_name} PUBLIC ARMA_DONT_USE_LAPACK ARMA_DONT_USE_BLAS)