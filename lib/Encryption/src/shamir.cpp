//
// Created by direnol on 01.10.18.
//

#include <shamir.h>

shamir::shamir(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t C,
               int64_t D, int64_t P)
        : Encrypt(in_file, out_file, key), C(C), D(D), P(P)
{}

shamir::shamir(const std::string &in_file, const std::string &out_file, const std::string &key) : Encrypt(in_file,
                                                                                                          out_file, key)
{
    P = op.getQ();
    auto[c, d] = op.getCD(0, P);
    C = c;
    D = d;
}

shamir::shamir(const std::string &in_file, const std::string &out_file, int64_t P) : Encrypt(in_file, out_file,
                                                                                             <#initializer#>), P(P)
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
    auto[in, out] = open();
    int64_t m;
    while (in.read(reinterpret_cast<char *>(&m), sizeof(m))) {
        auto e = Encode(m);
        out.write(reinterpret_cast<const char *>(&e), sizeof(e));
    }
}

int64_t shamir::Decode(int64_t m)
{
    return op.powmod(m, C, P);
}

void shamir::Decode()
{
    auto[in, out] = open();
    int64_t e;
    while (in.read(reinterpret_cast<char *>(&e), sizeof(e))) {
        auto m = Decode(e);
        out.write(reinterpret_cast<const char *>(&m), sizeof(m));
    }
}

void shamir::print()
{
    std::cout << "Shamir: C:" << C << " D:" << D << " P:" << P << std::endl;
}

void shamir::DecodeM()
{
    auto[in, out] = open();
    _decode(in, out);
}

void shamir::EncodeM()
{
    auto[in, out] = open();
    _encode(in, out);

}
