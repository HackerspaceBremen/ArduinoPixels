#
#  ClassGenerator
#  CMakeLists.txt
#
#  Created on: 2014/12/01
#      Author: Hans Robeers (https://github.com/hrobeers)
#

cmake_minimum_required(VERSION 2.8.11)


#
# Project settings
#

project(ClassGenerator)


#
# Build flags & compiler settings
#

# Define the Build flags
option(CINDER_INCLUDE_DIR "Cinder's include dir.")
option(CINDER_LIB_DIR "Cinder's lib dir.")
option(CCache "Build using ccache." OFF)

# Optionally enable ccache
if(CCache)
    SET_PROPERTY(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif()

# Set the compilation flags
set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O3 -fomit-frame-pointer -finline-functions -ffast-math")


#
# Find and include external dependencies
#

# Boost
find_package(Boost REQUIRED COMPONENTS system filesystem)
if(Boost_FOUND)
  message(STATUS "Including Boost from: ${Boost_INCLUDE_DIRS}")
  include_directories(${Boost_INCLUDE_DIRS})
endif()

# PNG
find_package(PNG REQUIRED)
if(PNG_FOUND)
  message(STATUS "Including Boost from: ${PNG_INCLUDE_DIRS}")
  include_directories(${PNG_INCLUDE_DIRS})
endif()


#
# Source files
#

# Sources
set(SRC
    src/classgeneratorApp.cpp
)

# Set GENERATOR_DIR macro
add_definitions(-DGENERATOR_DIR="${CMAKE_SOURCE_DIR}")


#
# The executable
#

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
add_executable(ClassGenerator WIN32 ${SRC})


#
# Linking
#

target_link_libraries(ClassGenerator
    ${Boost_LIBRARIES}
    ${PNG_LIBRARIES}
)
