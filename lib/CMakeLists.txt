set(DIRS Operation OperationOnFile Encryption Signature MentalPoker DigitalMoney ZeroColoring Graph)

foreach(loop ${DIRS})
    add_subdirectory(${loop})
endforeach(loop)