set(DIRS Operation OperationOnFile Encryption Signature MentalPoker DigitalMoney)

foreach(loop ${DIRS})
    add_subdirectory(${loop})
endforeach(loop)