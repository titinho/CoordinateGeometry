cmake_minimum_required(VERSION 3.3)
project(CoordinateGeometry)
set(OpenCV_DIR "C:/OpenCV/opencv-3.1.0/opencv/build_mingw64/install")
find_package( OpenCV REQUIRED )
add_executable( CoordinateGeometry main.cpp Line.cpp Line.h)
target_link_libraries( CoordinateGeometry ${OpenCV_LIBS} )