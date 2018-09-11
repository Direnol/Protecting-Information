cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(BigInteger SHARED src/BigInteger.cpp inc/BigInteger.h)
target_link_libraries(BigInteger m)