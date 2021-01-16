cmake_minimum_required(VERSION 3.0)

project(mouse_click_marker)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LINK_LIBS})

set(SOURCE ./src/${PROJECT_NAME}.cpp)

MESSAGE("CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
#target_include_directories(${PROJECT_NAME})

#MESSAGE("OPENCV_LIBS: " ${OpenCV_LIBS})
