//
// Created by direnol on 01.10.18.
//

#include "el_gamal.h"

el_gamal::el_gamal(const std::string &in_file, const std::string &out_file, const std::string &key) : Encrypt(in_file,
                                                                                                              out_file,
                                                                                                              key)
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

el_gamal::el_gamal(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t P,
                   int64_t Q,
                   int64_t C, int64_t g) : Encrypt(in_file, out_file, key), P(P), Q(Q), C(C), g(g)
{
    k = 1 + op.getRand() % (P - 2);
    r = op.powmod(g, k, P);
    D = op.powmod(g, C, P);
}


int64_t el_gamal::Encode(int64_t m)
{
    return ((m % P) * op.powmod(D, k, P)) % P;
}


int64_t el_gamal::Decode(int64_t m)
{
    return ((m % P) * op.powmod(r, P - 1 - C, P)) % P;
}


void el_gamal::print()
{
    std::cout << "El Gamal: P:" << P << " Q:" << Q << " g:" << g << std::endl
              << " C:" << C << " D:" << D << " r:" << r << " k:" << k << std::endl;
}

void el_gamal::write_key()
{


}

void el_gamal::read_key()
{

}
