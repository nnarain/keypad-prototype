cmake_minimum_required(VERSION 3.0)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain/cmake-avr-toolchain/avr-gcc.toolchain.cmake")
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" "${CMAKE_CURRENT_SOURCE_DIR}/src/external/ftl")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_LIST_DIR}/src/external/ftl")

message("${CMAKE_PREFIX_PATH}")

project(keypad)

find_package(ftl)

add_definitions(-DF_CPU=16000000UL)

set(platform "atmega2560")
set(target_name "${PROJECT_NAME}-${platform}")

add_avr_executable(${target_name} ${platform}
    src/main.cpp
    ${FTL_SOURCES}
)

target_include_directories(${target_name}-${platform}.elf PUBLIC
    ${FTL_INCLUDE_DIR}
)
