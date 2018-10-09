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

void rsa::write_key()
{
    std::ofstream out(this->key);
    out.write(reinterpret_cast<const char *>(&P), sizeof(P));
    out.write(reinterpret_cast<const char *>(&Q), sizeof(P));
    out.write(reinterpret_cast<const char *>(&C), sizeof(P));
    out.write(reinterpret_cast<const char *>(&D), sizeof(P));
    out.write(reinterpret_cast<const char *>(&N), sizeof(P));
    out.write(reinterpret_cast<const char *>(&F), sizeof(P));
}

void rsa::read_key()
{
    std::ifstream in(this->key);
    in.read(reinterpret_cast<char *>(&P), sizeof(P));
    in.read(reinterpret_cast<char *>(&Q), sizeof(P));
    in.read(reinterpret_cast<char *>(&C), sizeof(P));
    in.read(reinterpret_cast<char *>(&D), sizeof(P));
    in.read(reinterpret_cast<char *>(&N), sizeof(P));
    in.read(reinterpret_cast<char *>(&F), sizeof(P));
}

void rsa::print()
{
    std::cout << "Rsa: P:" << P << " Q:" << Q << " N:" << N << std::endl
              << " C:" << C << " D:" << D << " F:" << F << std::endl;

}

void rsa::Encode()
{
    Encrypt::Encode();
}

void rsa::Decode()
{
    Encrypt::Decode();
}
