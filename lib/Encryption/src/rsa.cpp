//
// Created by direnol on 01.10.18.
//

#include <rsa.h>

rsa::rsa(const std::string &in_file, const std::string &out_file) : Encrypt(in_file, out_file)
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

rsa::rsa(const std::string &in_file, const std::string &out_file, int64_t C, int64_t D, int64_t P, int64_t Q)
        : Encrypt(in_file, out_file), C(C), D(D), Q(Q), P(P)
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
    std::ifstream in(this->in_file, std::ifstream::binary);
    std::ofstream out(this->out_file, std::ofstream::binary);

    int8_t m;
    out.write(reinterpret_cast<const char *>(&P), sizeof(P));
    out.write(reinterpret_cast<const char *>(&Q), sizeof(P));
    out.write(reinterpret_cast<const char *>(&C), sizeof(P));
    out.write(reinterpret_cast<const char *>(&D), sizeof(P));
    out.write(reinterpret_cast<const char *>(&N), sizeof(P));
    out.write(reinterpret_cast<const char *>(&F), sizeof(P));
    while (!in.eof()) {
        in.read(reinterpret_cast<char *>(&m), sizeof(m));
        auto e = Encode(m);
        out.write(reinterpret_cast<const char *>(&e), sizeof(e));
    }
}


void rsa::Decode()
{
    std::ifstream in(this->in_file, std::ifstream::binary);
    std::ofstream out(this->out_file, std::ofstream::binary);

    in.read(reinterpret_cast<char *>(&P), sizeof(P));
    in.read(reinterpret_cast<char *>(&Q), sizeof(P));
    in.read(reinterpret_cast<char *>(&C), sizeof(P));
    in.read(reinterpret_cast<char *>(&D), sizeof(P));
    in.read(reinterpret_cast<char *>(&N), sizeof(P));
    in.read(reinterpret_cast<char *>(&F), sizeof(P));
    int64_t e;
    while (!in.eof()) {
        in.read(reinterpret_cast<char *>(&e), sizeof(e));
        auto m = Encode(e);
        out << (char) m;
    }
}

void rsa::print()
{
    std::cout << "Rsa: P:" << P << " Q:" << Q << " N:" << N << std::endl
              << " C:" << C << " D:" << D << " F:" << F << std::endl;

}
