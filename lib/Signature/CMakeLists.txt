cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

add_library(Signature SHARED src/Signature.cpp inc/Signature.h)
target_link_libraries(Signature Operation)