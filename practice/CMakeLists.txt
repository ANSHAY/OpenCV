cmake_minimum_required(VERSION 3.0)

project(capture_and_store)

set(SOURCE src/${PROJECT_NAME}.cpp)
find_package(OpenCV REQUIRED)

include_directories($OpenCV_INCLUDE_DIRS)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
MESSAGE("OPENCV_LIBS: " ${OpenCV_LIBS})
