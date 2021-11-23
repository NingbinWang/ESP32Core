cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)
list(APPEND EXTRA_COMPONENT_DIRS lib)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(ESP32StarCore)
