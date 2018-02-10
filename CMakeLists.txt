cmake_minimum_required(VERSION 3.1.0)
project(ABCD CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

set(INCLUDE_DIR "./include")
set(SOURCE_DIR "./src")
set(OUTPUT_DIR "./bin")

include_directories(${INCLUDE_DIR})
file(GLOB SOURCE_LIST ${SOURCE_DIR}/*.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

add_definitions(-D__STDC_CONSTANT_MACROS)
add_definitions(-D__STDC_LIMIT_MACROS)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIST})

file(GLOB HEADER_LIST ${INCLUDE_DIR}/abcd/*.hpp)
install(FILES ${HEADER_LIST} DESTINATION include/abcd)
install(TARGETS ${PROJECT_NAME} DESTINATION lib)