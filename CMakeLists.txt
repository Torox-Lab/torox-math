cmake_minimum_required(VERSION 3.21)
project(tMath VERSION 1.0.0 LANGUAGES CXX)

# ========= Set C++ standard
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========= Set directories
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# ========= Include directories
include_directories(${SOURCE_DIR})
include_directories(${INCLUDE_DIR})

# ========= Add directories files
file(GLOB_RECURSE SOURCES
    "${SOURCE_DIR}/*.c"
    "${SOURCE_DIR}/*.cpp"
    "${INCLUDE_DIR}/*.h"
    "${INCLUDE_DIR}/*.hpp"
)

# ========= Include libraries
    # find_package(Boost COMPONENTS random filesystem system REQUIRED)

# ========= Add executable
add_executable(${CMAKE_PROJECT_NAME}
    ${SOURCES}
)

# ========= Cnfigure macOS package
if(APPLE)
    set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES MACOSX_BUNDLE TRUE)
endif()

# ========= Generate Xcode project
if(CMAKE_GENERATOR STREQUAL "Xcode")
    set(XCODE_SCHEME "NoIdea")
    set(XCODE_CONFIGURATION "Debug")
    set_property(DIRECTORY PROPERTY XCODE_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_SCHEME ${XCODE_SCHEME})
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_GENERATE_SCHEME TRUE)
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_SCHEME_ENVIRONMENT "${CMAKE_XCODE_SCHEME_ENVIRONMENT}")
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_SCHEME_ARGUMENTS "${CMAKE_XCODE_SCHEME_ARGUMENTS}")
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY XCODE_SCHEME_WORKING_DIRECTORY "${CMAKE_XCODE_SCHEME_WORKING_DIRECTORY}")
    set(CMAKE_XCODE_ATTRIBUTE_CONFIGURATION ${XCODE_CONFIGURATION})
endif()

# ========= Link target subDirectories
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC src)
target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC include)