//
// Created by direnol on 02.10.18.
//

#include <RSA.h>

uint64_t Signature::RSA::Sign() {
    return 0;
}

uint64_t Signature::RSA::Unsign() {
    return 0;
}

Signature::RSA::RSA(std::string in_f, std::string out_f) : Signature(std::move(in_f), std::move(out_f)) {
    auto[p, q] = op.get_simple_pair();
    this->P = p;
    this->Q = q;
    this->N = P * Q;
    this->F = (P - 1) * (Q - 1);
    auto[d, c] = op.getCD(1 + op.getRand() % (F - 1), F + 1);
    this->d = d;
    this->c = c;
}

void Signature::RSA::Print() {

}