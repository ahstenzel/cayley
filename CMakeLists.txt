cmake_minimum_required(VERSION 3.19)
project(cayley VERSION 1.0.0)

## C language configuration boilerplate
if (NOT DEFINED CMAKE_CXX_VISIBILITY_PRESET AND
    NOT DEFINED CMAKE_VISIBILITY_INLINES_HIDDEN)
  set(CMAKE_CXX_VISIBILITY_PRESET hidden)
  set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
endif()

## Let CAYLEY_SHARED_LIBS override BUILD_SHARED_LIBS
if (DEFINED CAYLEY_SHARED_LIBS)
    set(BUILD_SHARED_LIBS "${CAYLEY_SHARED_LIBS}")
endif()

## Specify library output directory
set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin/static/${CMAKE_SYSTEM_PROCESSOR}")
if (BUILD_SHARED_LIBS)
  set(OUTPUT_DIR "${PROJECT_SOURCE_DIR}/bin/shared/${CMAKE_SYSTEM_PROCESSOR}")
endif()
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${OUTPUT_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}")

## Create the main library target
file(GLOB_RECURSE libsrc "src/*.c")
add_library(cayley ${libsrc})
add_library(cayley::cayley ALIAS cayley)
set_target_properties(cayley PROPERTIES
                      VERSION ${cayley_VERSION}
                      SOVERSION ${cayley_VERSION_MAJOR})
target_include_directories(
    cayley PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>")
target_compile_features(cayley PUBLIC c_std_11)

## Signal to build static or shared library
if (BUILD_SHARED_LIBS)
  add_definitions(-DCAYLEY_SHARED_DEFINE)
endif()