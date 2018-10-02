//
// Created by direnol on 01.10.18.
//

#include "shamir.h"

shamir::shamir(const std::string &in_file, const std::string &out_file, int64_t C, int64_t D, int64_t P)
        : Encrypt(in_file, out_file), C(C), D(D), P(P)
{}

shamir::shamir(const std::string &in_file, const std::string &out_file) : Encrypt(in_file, out_file)
{
    P = op.getQ();
    auto[c, d] = op.getCD(0, P);
    C = c;
    D = d;
}

shamir::shamir(const std::string &in_file, const std::string &out_file, int64_t P) : Encrypt(in_file, out_file), P(P)
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

void shamir::Encode()
{
    std::ifstream in(this->in_file);
    std::ofstream out(this->in_file);

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

void shamir::Decode()
{
    std::ifstream in(this->in_file);
    std::ofstream out(this->in_file);


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
