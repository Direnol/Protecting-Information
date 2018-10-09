//
// Created by direnol on 01.10.18.
//

#include <vernam.h>

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

vernam::vernam(const std::string &in_file, const std::string &out_file, const std::string &key) : Encrypt(in_file,
                                                                                                          out_file, key)
{
    k = op.getQ();
}

vernam::vernam(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t k)
        : Encrypt(in_file, out_file,
                  key), k(k)
{}

void vernam::print()
{
    std::cout << "Vernam: K:" << k << std::endl;
}

void vernam::write_key() {
    std::ofstream out(this->key, std::ofstream::binary);
    out.write(reinterpret_cast<const char *>(&k), sizeof(k));
}

void vernam::read_key() {
    std::ifstream in(this->key, std::ifstream::binary);
    in.read(reinterpret_cast<char *>(&k), sizeof(k));
}
