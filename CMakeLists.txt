cmake_minimum_required(VERSION 3.28)

set(TARGET_NAME template)
project(template LANGUAGES CXX)
add_executable(${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    EXPORT_COMPILE_COMMANDS YES
    COMPILE_WARNING_AS_ERROR YES
)

if(MSVC)
    target_compile_options(${TARGET_NAME} PRIVATE /W4)
else()
    target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_sources(${TARGET_NAME} PRIVATE
    src/main.cpp
    include/util/ptr.hpp
)
target_include_directories(${TARGET_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")