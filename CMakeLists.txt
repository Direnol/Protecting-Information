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

set(SRC_OOF src/OperationOnFile.cpp inc/OperationOnFile.h)
add_library(OpOnFile ${SRC_OOF})

set(SRC_SIGN src/Signature.cpp inc/Signature.h)
add_library(Signature ${SRC_SIGN})
target_link_libraries(Signature Operation crypto)

add_executable(clion main.cpp)
target_link_libraries(clion Encryption BigInt OpOnFile Signature)


get_cmake_property(clion CMAKE_CXX_FLAGS)
