# The MIT License (MIT)
#
# Copyright (c) 2021 Alexander Kurbatov

cmake_minimum_required(VERSION 3.1)

project(Scrubber)

# Specify output directories.
set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("contrib")
add_subdirectory("src")
