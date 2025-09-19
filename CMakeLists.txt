cmake_minimum_required(VERSION 3.31 FATAL_ERROR)
cmake_policy(VERSION 3.31)

project(graph-creator DESCRIPTION "Graph Creator" VERSION 0.1.0 LANGUAGES CXX)

if(NOT DEFINED ENV{VCPKG_ROOT})
	message(FATAL_ERROR "VCPKG_ROOT is not defined!")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

# TODO: Rename repo to "graph-builder"
add_executable(graph_creator src/main.cpp)
target_precompile_headers(graph_creator PUBLIC src/main.hpp)

# find_package(raylib)
# target_link_libraries(graph_creator raylib)


add_custom_target(run_after_generation ALL
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${PROJECT_SOURCE_DIR}/compile_commands.json
)