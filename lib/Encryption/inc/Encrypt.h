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

class Encrypt {
protected:
    Operation op;
public:
    virtual int64_t Encode(int64_t m) = 0;

    virtual void Encode(std::istream &in, std::ostream &out) = 0;

    virtual int64_t Decode(int64_t m) = 0;

    virtual void Decode(std::istream &in, std::ostream &out) = 0;

    virtual void print() = 0;
};

#endif //CLION_ENCRYPT_H
