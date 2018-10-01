//
// Created by direnol on 01.10.18.
//

#include "shamir.h"

shamir::shamir(int64_t C, int64_t D, int64_t P) : C(C), D(D), P(P)
{}

shamir::shamir()
{
    P = op.getQ();
    auto[c, d] = op.getCD(0, P);
    C = c;
    D = d;
}

shamir::shamir(int64_t P) : P(P)
{
    auto[c, d] = op.getCD(0, P);
    C = c;
    D = d;
}

int64_t shamir::getP() const
{
    return P;
}

int64_t shamir::Encode(int64_t m)
{
    return op.powmod(m, D, P);
}

void shamir::Encode(std::istream &in, std::ostream &out)
{
    int8_t m;
    out << C << D << P;
    while (in >> m) {
        out << Encode(m);
    }
}

int64_t shamir::Decode(int64_t m)
{
    return op.powmod(m, C, P);
}

void shamir::Decode(std::istream &in, std::ostream &out)
{

    int64_t m;
    in >> C >> D >> P;
    while (in >> m) {
        out << Decode(m);
    }
}

void shamir::print()
{
    std::cout << "Shamir: C:" << C << " D:" << D << " P:" << P << std::endl;
}
