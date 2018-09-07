cmake_minimum_required(VERSION 3.12)
project(clion)

set(CMAKE_CXX_STANDARD 17)


set(SRC_OP src/Operation.cpp inc/Operation.h)
add_library(Operation ${SRC_OP})

set(SRC_ENC src/Encrypt.cpp inc/Encrypt.h)
add_library(Encryption ${SRC_ENC})
target_link_libraries(Encryption Operation)

set(SRC_BIGINT src/BigInteger.cpp inc/BigInteger.h)
add_library(BigInt ${SRC_BIGINT})

add_executable(clion main.cpp)
target_link_libraries(clion Encryption BigInt)

get_cmake_property(clion CMAKE_CXX_FLAGS)
