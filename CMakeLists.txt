cmake_minimum_required(VERSION 3.10)
project(Protection-Information)

set(DIRS Operation OperationOnFile Encryption Signature MentalPoker)
set(LIB lib)

foreach(loop ${DIRS})
    include_directories(${LIB}/${loop}/inc)
endforeach(loop)

add_subdirectory(${LIB})
add_subdirectory(project)
