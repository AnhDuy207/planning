cmake_minimum_required(VERSION 3.0.2)
project(check_depthcam)

find_package(OpenCV REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  cv_bridge
)

## System depend
find_package(Eigen3 REQUIRED)
find_package(PCL 1.7 REQUIRED)

catkin_package(
# INCLUDE_DIRS include
# LIBRARIES check_depthcamera
# CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories( 
    SYSTEM 
    include 
    ${catkin_INCLUDE_DIRS}
    ${Eigen3_INCLUDE_DIRS} 
    ${PCL_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

link_directories(${PCL_LIBRARY_DIRS})

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -O3 -Wall")

add_executable(check_depthcam
    src/check.cpp 
    )

target_link_libraries( check_depthcam
    ${catkin_LIBRARIES} 
    ${PCL_LIBRARIES}
    )  
