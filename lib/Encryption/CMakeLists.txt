cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

add_library(Encryption SHARED src/Encrypt.cpp inc/Encrypt.h)
target_link_libraries(Encryption Operation)