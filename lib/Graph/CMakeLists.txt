cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

add_library(Graph SHARED src/Graph.cpp inc/Graph.h src/Node.cpp inc/Node.h)
