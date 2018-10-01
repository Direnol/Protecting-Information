//
// Created by direnol on 01.10.18.
//

#include "vernam.h"

int64_t vernam::Encode(int64_t m)
{
    return k ^ m;
}

void vernam::Encode(std::istream &in, std::ostream &out)
{
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

void vernam::Decode(std::istream &in, std::ostream &out)
{
    in >> k;
    int64_t m;
    while (in >> m) {
        out << Decode(m);
    }
}

vernam::vernam()
{
    k = op.getQ();
}

vernam::vernam(int64_t k) : k(k)
{}

void vernam::print()
{
    std::cout << "Vernam: K:" << k << std::endl;
}
