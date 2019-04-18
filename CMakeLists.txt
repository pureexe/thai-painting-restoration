cmake_minimum_required(VERSION 2.8)

project( thai-painting-restoration )

set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/build/)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( thai-painting-restoration src/main.cpp )
target_link_libraries( thai-painting-restoration ${OpenCV_LIBS} )

enable_testing()

add_executable(gradient tests/Gradient.cpp EXCLUDE_FROM_ALL)
target_link_libraries(gradient ${OpenCV_LIBS} )
add_dependencies(test gradient)
add_test(Gradient tests/gradient)