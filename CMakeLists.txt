cmake_minimum_required(VERSION 2.8.10)
project(osx-key-test)

find_file(OSX_CG_LIB CoreGraphics HINTS /System/Library/Frameworks/CoreGraphics.framework/Versions/A)

if(NOT OSX_CG_LIB)
  message(FATAL "OSX CoreGraphics is not found")
else()
  message(STATUS "OSX CoreGraphics: ${OSX_CG_LIB}")
endif()

find_file(OSX_CF_LIB CoreFoundation HINTS /System/Library/Frameworks/CoreFoundation.framework/Versions/A)

if(NOT OSX_CF_LIB)
  message(FATAL "OSX CoreFoundation is not found")
else()
  message(STATUS "OSX CoreFoundation: ${OSX_CF_LIB}")
endif()

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

add_executable(osx-key-test osx-key-test.cxx)
target_link_libraries(osx-key-test ${OSX_CG_LIB} ${OSX_CF_LIB})

