cmake_minimum_required(VERSION 3.20)
project(Simulator)

# 禁止在源码同级目录构建项目
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

#-------------------------------------------------------------
# general configuration
#-------------------------------------------------------------
enable_language(C)
enable_language(CXX)
# C++ standard
set(CMAKE_CXX_STANDARD 17 CACHE STRING "The C++ standard to use")
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)
# export compile commands for lsp
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)



# define c++ macro to root dir of project
add_definitions(-DPROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")
# set out directory
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

# build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# OpenMP
find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    MESSAGE(STATUS "OpenMP is linked")
    link_libraries(OpenMP::OpenMP_CXX)
endif()


#-------------------------------------------------------------
# dependency library
#-------------------------------------------------------------
# polyscope https://polyscope.run/
add_subdirectory(${CMAKE_SOURCE_DIR}/external/polyscope EXCLUDE_FROM_ALL)
# Eigen3 https://eigen.tuxfamily.org
add_subdirectory(${CMAKE_SOURCE_DIR}/external/eigen EXCLUDE_FROM_ALL)

#-------------------------------------------------------------
# Simulator library
#-------------------------------------------------------------
set(simulator_name snow)
add_subdirectory(src)

#-------------------------------------------------------------
# Tutorial
#-------------------------------------------------------------
add_subdirectory(tutorial)



