cmake_minimum_required(VERSION 3.0)
project (image_read)

FIND_PACKAGE (OpenCV REQUIRED)
MESSAGE ("OPENCV VERSION: " ${OpenCV_VERSION})

INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
LINK_DIRECTORIES(${OpenCV_LIB_DIR})

SET (SOURCES ./src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})