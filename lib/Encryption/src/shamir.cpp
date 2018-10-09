//
// Created by direnol on 01.10.18.
//

#include <shamir.h>

shamir::shamir(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t C,
               int64_t D, int64_t P)
        : Encrypt(in_file, out_file, key), C(C), D(D), P(P)
{}

shamir::shamir(const std::string &in_file, const std::string &out_file, const std::string &key)
        : Encrypt(in_file,
                  out_file, key)
{
    P = op.getQ();
    auto[c, d] = op.getCD(0, P);
    C = c;
    D = d;
}

shamir::shamir(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t P)
        : Encrypt(in_file, out_file,
                  key), P(P)
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

int64_t shamir::Decode(int64_t m)
{
    return op.powmod(m, C, P);
}

void shamir::print()
{
    std::cout << "Shamir: C:" << C << " D:" << D << " P:" << P << std::endl;
}

void shamir::write_key()
{
    std::ofstream out(this->key);
    out.write(reinterpret_cast<const char *>(&P), sizeof(P));
    out.write(reinterpret_cast<const char *>(&C), sizeof(P));
    out.write(reinterpret_cast<const char *>(&D), sizeof(P));
}

void shamir::read_key()
{
    std::ifstream in(this->key);
    in.read(reinterpret_cast<char *>(&P), sizeof(P));
    in.read(reinterpret_cast<char *>(&C), sizeof(P));
    in.read(reinterpret_cast<char *>(&D), sizeof(P));
}

void shamir::Encode()
{
    Encrypt::Encode();
}

void shamir::Decode()
{
    Encrypt::Decode();
}
