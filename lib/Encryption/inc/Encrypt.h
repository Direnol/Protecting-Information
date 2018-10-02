//
// Created by stanley on 05.09.18.
//

#ifndef CLION_ENCRYPT_H
#define CLION_ENCRYPT_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdint>
#include <Operation.h>
#include <fstream>

class Encrypt {
protected:
    Operation op;
    std::string in_file;
    std::string out_file;
public:
    Encrypt(const std::string &in_file, const std::string &out_file);

    void setIn_file(const std::string &in_file);

    void setOut_file(const std::string &out_file);

    virtual int64_t Encode(int64_t m) = 0;

    virtual void Encode() = 0;

    virtual int64_t Decode(int64_t m) = 0;

    virtual void Decode() = 0;

    virtual void print() = 0;
};

#endif //CLION_ENCRYPT_H
