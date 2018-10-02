//
// Created by stanley on 05.09.18.
//

#include <Encrypt.h>

Encrypt::Encrypt(const std::__cxx11::basic_string<char> &in_file, const std::__cxx11::basic_string<char> &out_file)
        : in_file(in_file), out_file(out_file)
{}

void Encrypt::setIn_file(const std::string &in_file)
{
    Encrypt::in_file = in_file;
}

void Encrypt::setOut_file(const std::string &out_file)
{
    Encrypt::out_file = out_file;
}
