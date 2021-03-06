################################################################
# Project M.A.R.S.
################################################################

 PROJECT(MARS)

# version number
set(mars_MAJOR 0)
set(mars_MINOR 7)
set(mars_PATCH 5)
set(mars_VERSION ${mars_MAJOR}.${mars_MINOR}.${mars_PATCH})
set(mars_DESCRIPTION "M.A.R.S. - a ridiculous Shooter")
set(mars_HOMEPAGE "http://www.marsshooter.org")
set(mars_EXENAME "mars")
set(mars_PACKAGENAME "mars")
 
# We require at least version 2.8.0
cmake_minimum_required(VERSION 2.8.0)

#####################################################################
# Configure and find libraries
#####################################################################

# find OpenGL headers and library
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

# find the sfml2 headers and library
include(FindPkgConfig)
pkg_check_modules(SFML REQUIRED sfml-audio>=2.0 sfml-graphics>=2.0
			sfml-window>=2.0 sfml-system>=2.0)
include_directories(${SFML_INCLUDE_DIRS})

# Foundation library needed for apple
if(APPLE)
	find_library(FOUNDATION_LIBRARY Foundation)
endif(APPLE)

# Xrandr library needed for unix
# if(UNIX)
#	find_library(XRANDR_LIBRARY Xrandr)
# endif(UNIX)

# tag library needed for reading tags of music files
	find_library(TAG_LIBRARY tag)

# Fribidi library needed for bi-directional texts
	find_library(FRIBIDI_LIBRARY fribidi)

# set the executable output path
if(APPLE)
	set(EXECUTABLE_OUTPUT_PATH ${MARS_BINARY_DIR})
else(APPLE)
	set(EXECUTABLE_OUTPUT_PATH ${MARS_SOURCE_DIR})
endif(APPLE)

# include the 'include' directory
 include_directories(${MARS_SOURCE_DIR}/include)
 
#####################################################################
# Create executable
#####################################################################

# compile source
set(CMAKE_CXX_FLAGS "-s -O2")
 add_subdirectory(src) 
 
#####################################################################
# Create package
#####################################################################

# CPack version numbers for release tarball name.
set(CPACK_PACKAGE_VERSION_MAJOR ${mars_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${mars_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${mars_PATCH})

# To Create a package, one can run "cpack -G DragNDrop CPackConfig.cmake" on Mac OS X
# where CPackConfig.cmake is created by including CPack
# And then there's ways to customize this as well
set(CPACK_DMG_VOLUME_NAME "mars")
set(CPACK_BINARY_DRAGNDROP ON)
include(CPack)


################################################################
# Summary
################################################################

message( "" )
message( "Summary:" )
message( "  CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}" )
message( "  WIN32 = ${WIN32}" )
message( "  UNIX = ${UNIX}" )
message( "  APPLE = ${APPLE}" )
message( "  CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}" )
message( "  CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )
message( "  CMAKE_OSX_ARCHITECTURES = ${CMAKE_OSX_ARCHITECTURES}" )
message( "  CMAKE_OSX_SYSROOT = ${CMAKE_OSX_SYSROOT}" )
message( "  CMAKE_OSX_DEPLOYMENT_TARGET = ${CMAKE_OSX_DEPLOYMENT_TARGET}" )
message( "  CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( "  SFML_INCLUDE_DIR = ${SFML_INCLUDE_DIR}" )
message( "  SFML_LIBRARIES = ${SFML_LIBRARIES}" )
message( "  OPENGL_INCLUDE_DIR = ${OPENGL_INCLUDE_DIR}" )
message( "  OPENGL_LIBRARIES = ${OPENGL_LIBRARIES}" )
message( "  XRANDR_LIBRARY = ${XRANDR_LIBRARY}" )
message( "  FRIBIDI_LIBRARY = ${FRIBIDI_LIBRARY}" )
message( "  TAG_LIBRARY = ${TAG_LIBRARY}" )
message( "" )


