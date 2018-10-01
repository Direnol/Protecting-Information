//
// Created by direnol on 01.10.18.
//

#include "el_gamal.h"

el_gamal::el_gamal()
{
    auto[p, q] = op.get_simple_pair();
    P = p;
    Q = q;
    g = op.getG(P, Q);
    C = op.getQ();
    k = 1 + op.getRand() % (P - 2);
    r = op.powmod(g, k, P);
    D = op.powmod(g, C, P);
}

el_gamal::el_gamal(int64_t P, int64_t Q, int64_t C, int64_t g) : P(P), Q(Q), C(C), g(g)
{
    k = 1 + op.getRand() % (P - 2);
    r = op.powmod(g, k, P);
    D = op.powmod(g, C, P);
}


int64_t el_gamal::Encode(int64_t m)
{
    return ((m % P) * op.powmod(D, k, P)) % P;
}

void el_gamal::Encode(std::istream &in, std::ostream &out)
{
    out << P << Q << g << C << D << r << k;
    int8_t m;
    while (in >> m) {
        out << Encode(m);
    }
}

int64_t el_gamal::Decode(int64_t m)
{
    return ((m % P) * op.powmod(r, P - 1 - C, P)) % P;
}

void el_gamal::Decode(std::istream &in, std::ostream &out)
{

    in >> P >> Q >> g >> C >> D >> r >> k;
    int64_t m;
    while (in >> m) {
        out << Encode(m);
    }
}

void el_gamal::print()
{
    std::cout << "El Gamal: P:" << P << " Q:" << Q << " g:" << g << std::endl
              << " C:" << C << " D:" << D << " r:" << r << " k:" << k << std::endl;
}
