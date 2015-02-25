#
#  ArduinoPixels
#  CMakeLists.txt
#
#  Created on: 2014/12/01
#      Author: Hans Robeers (https://github.com/hrobeers)
#

cmake_minimum_required(VERSION 2.8.11)


#
# Project settings
#

project(ArduinoPixels)


#
# Build flags & compiler settings
#

# Define the Build flags
option(CCache "Build using ccache." OFF)

# Optionally enable ccache
if(CCache)
    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif()

if(CMAKE_BUILD_TYPE MATCHES DEBUG)
    add_definitions(-DDEBUG)
endif()

# Set the compilation flags
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -fomit-frame-pointer -finline-functions -ffast-math")


#
# Include subdirectories
#

# Include the subdirectories
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/pixelApp")
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/libraries/PixelShared")
INCLUDE_DIRECTORIES("${CMAKE_SOURCE_DIR}/libraries/PixelGame")

add_subdirectory(pixelApp)
