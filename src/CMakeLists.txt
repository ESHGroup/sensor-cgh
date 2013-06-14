# Author: Richard McIntosh
# Date: 6/14/2013
# Contact: rmcintosh@nmhu.edu

# we require cmake >= v 2.6
cmake_minimum_required(VERSION 2.6)

# define our project name
set (PROJ_NAME "sensor-cgh")

# tell cmake our project's name
project(${PROJ_NAME})

# versioning
set (SENSOR_CGH_VERSION_MAJOR 0)
set (SENSOR_CGH_VERSION_MINOR 97)

# set our compile flags 
set(CMAKE_CXX_FLAGS "-O0 -g3 -Wall -fmessage-length=0 -MMD -MP")

# define all our source files
set(SOURCES DepthCapture.cpp ParseWavefrontObj.cpp HoloFilm.cpp main.cpp)

# define libraries to be linked with project
set(CORELIBS m OpenNI pthread X11)

# build our project
add_executable(${PROJ_NAME} ${SOURCES})
target_link_libraries(${PROJ_NAME} ${CORELIBS})


