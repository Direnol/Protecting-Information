//
// Created by direnol on 01.10.18.
//

#include <rsa.h>

rsa::rsa(const std::string &in_file, const std::string &out_file, const std::string &key) : Encrypt(in_file, out_file,
                                                                                                    key)
{
    auto[p, q] = op.get_simple_pair();
    P = p;
    Q = q;
    N = P * Q;
    F = (P - 1) * (Q - 1);
    auto[D, C] = op.getCD(1 + op.getRand() % (F - 1), F + 1);
    this->D = D;
    this->C = C;
}

rsa::rsa(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t C, int64_t D,
         int64_t P, int64_t Q)
        : Encrypt(in_file, out_file, key), C(C), D(D), Q(Q), P(P)
{
    N = P * Q;
    F = (P - 1) * (Q - 1);
}

int64_t rsa::Encode(int64_t m)
{
    return op.powmod(m, D, N);
}


int64_t rsa::Decode(int64_t m)
{
    return op.powmod(m, C, N);
}

void rsa::Encode()
{
    auto[in, out] = open();
    out.write(reinterpret_cast<const char *>(&P), sizeof(P));
    out.write(reinterpret_cast<const char *>(&Q), sizeof(P));
    out.write(reinterpret_cast<const char *>(&C), sizeof(P));
    out.write(reinterpret_cast<const char *>(&D), sizeof(P));
    out.write(reinterpret_cast<const char *>(&N), sizeof(P));
    out.write(reinterpret_cast<const char *>(&F), sizeof(P));
    _encode(in, out);
}


void rsa::Decode()
{
    auto[in, out] = open();
    in.read(reinterpret_cast<char *>(&P), sizeof(P));
    in.read(reinterpret_cast<char *>(&Q), sizeof(P));
    in.read(reinterpret_cast<char *>(&C), sizeof(P));
    in.read(reinterpret_cast<char *>(&D), sizeof(P));
    in.read(reinterpret_cast<char *>(&N), sizeof(P));
    in.read(reinterpret_cast<char *>(&F), sizeof(P));

    _decode(in, out);
}

void rsa::print()
{
    std::cout << "Rsa: P:" << P << " Q:" << Q << " N:" << N << std::endl
              << " C:" << C << " D:" << D << " F:" << F << std::endl;

}
