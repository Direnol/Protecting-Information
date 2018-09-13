project(lab)
set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../build/bin)

set(LIBS Operation)

function(add_exec_link EXEC_NAME SRC)
    add_executable(${EXEC_NAME} ${SRC})
    target_link_libraries(${EXEC_NAME} ${LIBS})
    message(STATUS "Create target ${EXEC_NAME}\n"
            "\twith sources: ${SRC}\n"
            "\twith library: ${LIBS}")
endfunction(add_exec_link)


add_exec_link(${PROJECT_NAME}-1 src/main1.cpp)
set(LIBS Encrypt)
add_exec_link(${PROJECT_NAME}-2 src/main2.cpp)
