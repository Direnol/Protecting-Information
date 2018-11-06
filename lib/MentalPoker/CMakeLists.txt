cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(MentalPoker SHARED src/MentalPoker.cpp inc/MetalPoker.h inc/MentalPlayer.h inc/MentalCard.h)
target_link_libraries(MentalPoker Encryption Operation)