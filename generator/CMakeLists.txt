cmake_minimum_required(VERSION 3.5.00)

PROJECT(image_generator)
SET(CMAKE_CXX_STANDARD 11)

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS})

ADD_EXECUTABLE(generator src/main.cpp)
TARGET_LINK_LIBRARIES(generator ${OpenCV_LIBS} )


