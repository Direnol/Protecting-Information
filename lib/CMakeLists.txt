set(DIRS Operation OperationOnFile Encryption Signature MentalPoker)

foreach(loop ${DIRS})
    add_subdirectory(${loop})
endforeach(loop)