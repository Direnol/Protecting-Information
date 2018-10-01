//
// Created by direnol on 01.10.18.
//

#include <rsa.h>

rsa::rsa()
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

rsa::rsa(int64_t C, int64_t D, int64_t P, int64_t Q) : C(C), D(D), Q(Q), P(P)
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

void rsa::Encode(std::istream &in, std::ostream &out)
{
    int8_t m;
    out << P << Q << C << D << N << F;
    while (in >> m) {
        out << Encode(m);
    }
}


void rsa::Decode(std::istream &in, std::ostream &out)
{
    in >> P >> Q >> C >> D >> N >> F;
    int64_t m;
    while (in >> m) {
        out << Decode(m);
    }
}

void rsa::print()
{
    std::cout << "Rsa: P:" << P << " Q:" << Q << " N:" << N << std::endl
              << " C:" << C << " D:" << D << " F:" << F << std::endl;

}
