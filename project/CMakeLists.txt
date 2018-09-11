project(protect-info)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
include_directories(../lib/Operation/inc)
include_directories(../lib/BigInteger/inc)
include_directories(../lib/OperationOnFile/inc)
include_directories(../lib/Encryption/inc)
include_directories(../lib/Signature/inc)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build/bin)

set(LIBS ${PROJECT_SOURCE_DIR}/../build/lib/libOperation.so ${PROJECT_SOURCE_DIR}/../build/lib/libOperationOnFile.so
         ${PROJECT_SOURCE_DIR}/../build/lib/libEncryption.so ${PROJECT_SOURCE_DIR}/../build/lib/libBigInteger.so
         ${PROJECT_SOURCE_DIR}/../build/lib/libSignature.so)


add_executable(protect-info src/main.cpp)
target_link_libraries(protect-info ${LIBS})


get_cmake_property(clion CMAKE_CXX_FLAGS)