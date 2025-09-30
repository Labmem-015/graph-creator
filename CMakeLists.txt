cmake_minimum_required(VERSION 3.31 FATAL_ERROR)
cmake_policy(VERSION 3.31)

if(NOT DEFINED ENV{VCPKG_ROOT})
	message(FATAL_ERROR "VCPKG_ROOT is not defined!")
endif()

include(CMakePrintHelpers)
cmake_print_variables(CMAKE_TOOLCHAIN_FILE)

project(graph-creator DESCRIPTION "Graph Creator" VERSION 0.1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)

file(GLOB hpp_files CONFIGURE_DEPENDS src/*.hpp)
file(GLOB cpp_files CONFIGURE_DEPENDS src/*.cpp)

# TODO: Rename repo to "graph-builder" or "grator"
add_executable(graph_creator ${hpp_files} ${cpp_files})
target_precompile_headers(graph_creator PUBLIC src/main.hpp)

find_package(raylib CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(graph_creator raylib glfw)

if(EXISTS "${PROJECT_SOURCE_DIR}/snippets/")
    add_subdirectory(snippets)
endif()

# This is for clangd support. You can comment those lines if you don't use clangd
# Check if the file exists
if(EXISTS "${PROJECT_SOURCE_DIR}/.clangd")
    message(STATUS "Creating symlink to 'compile_commands.json'")
    add_custom_target(run_after_generation ALL
        COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_BINARY_DIR}/compile_commands.json
            ${PROJECT_SOURCE_DIR}/compile_commands.json
    )
endif()