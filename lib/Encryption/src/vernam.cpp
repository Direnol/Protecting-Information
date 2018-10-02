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
    std::ifstream in(this->in_file);
    std::ofstream out(this->in_file);

    int8_t m;
    in >> k;
    while (in >> m) {
        out << Encode(m);
    }
}

int64_t vernam::Decode(int64_t m)
{
    return k ^ m;
}

void vernam::Decode()
{
    std::ifstream in(this->in_file);
    std::ofstream out(this->in_file);

    in >> k;
    int64_t m;
    while (in >> m) {
        out << Decode(m);
    }
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
