cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(Encryption SHARED src/Encrypt.cpp inc/Encrypt.h src/rsa.cpp inc/rsa.h src/shamir.cpp inc/shamir.h src/el_gamal.cpp inc/el_gamal.h src/vernam.cpp inc/vernam.h)
target_link_libraries(Encryption Operation)