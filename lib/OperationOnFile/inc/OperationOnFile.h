//
// Created by stanley on 08.09.18.
//

#ifndef CLION_OPERATIONONFILE_H
#define CLION_OPERATIONONFILE_H

#include <fstream>
#include <iostream>

using lambdaCrypt = int8_t(int8_t);

class OperationOnFile {
    std::ifstream in;
    std::ofstream out;
    bool cout;
public:
    OperationOnFile(std::string in, std::string out);

    OperationOnFile(std::string in) : in(in), cout(true)
    {};

    ~OperationOnFile() = default;

    bool ChangeFile(std::string in, std::string out);

    void Crypto(lambdaCrypt f);

};


#endif //CLION_OPERATIONONFILE_H
