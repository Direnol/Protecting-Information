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
    std::string key;

    void _encode(std::ifstream &in, std::ofstream &out);

    void _decode(std::ifstream &in, std::ofstream &out);

    virtual void write_key() = 0;

    virtual void read_key() = 0;


    pair<std::ifstream, std::ofstream> open();

public:
    Encrypt(const std::string &in_file, const std::string &out_file, const std::string &key);

    void setIn_file(const std::string &in_file);

    void setOut_file(const std::string &out_file);

    void Swap_files();

    virtual int64_t Encode(int64_t m) = 0;

    virtual void Encode();

    virtual int64_t Decode(int64_t m) = 0;

    virtual void Decode();

    virtual void print() = 0;
};

#endif //CLION_ENCRYPT_H
