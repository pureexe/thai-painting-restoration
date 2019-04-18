cmake_minimum_required(VERSION 2.8)

project( thai-painting-restoration )

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( thai-painting-restoration src/main.cpp )
target_link_libraries( thai-painting-restoration ${OpenCV_LIBS} )

enable_testing()
add_executable(gradient tests/Gradient.cpp)
add_test(Gradient gradient)