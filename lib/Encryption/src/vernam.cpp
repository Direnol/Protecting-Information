//
// Created by direnol on 01.10.18.
//

#include "vernam.h"

int64_t vernam::Encode(int64_t m)
{
    return k ^ m;

}

void vernam::Encode()
{
    auto[in, out] = open();

    out.write(reinterpret_cast<const char *>(&k), sizeof(k));
    _encode(in, out);
}

int64_t vernam::Decode(int64_t m)
{
    return k ^ m;
}

void vernam::Decode()
{
    auto[in, out] = open();

    in.read(reinterpret_cast<char *>(&k), sizeof(k));
    _decode(in, out);
}

vernam::vernam(const std::string &in_file, const std::string &out_file) : Encrypt(in_file, out_file)
{
    k = op.getQ();
}

vernam::vernam(const std::string &in_file, const std::string &out_file, int64_t k) : Encrypt(in_file, out_file), k(k)
{}

void vernam::print()
{
    std::cout << "Vernam: K:" << k << std::endl;
}
