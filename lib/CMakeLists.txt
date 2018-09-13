set(DIRS Operation OperationOnFile Encryption Signature)

foreach(loop ${DIRS})
    add_subdirectory(${loop})
endforeach(loop)