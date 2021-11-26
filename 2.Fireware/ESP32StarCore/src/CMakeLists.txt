# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)
FILE(GLOB_RECURSE app_include
${CMAKE_SOURCE_DIR}/src/
${CMAKE_SOURCE_DIR}/src/HAL/
)

idf_component_register(SRCS ${app_sources}
INCLUDE_DIRS ${app_include}
)
