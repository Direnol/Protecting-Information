//
// Created by direnol on 01.10.18.
//

#ifndef PROTECTION_INFORMATION_RSA_H
#define PROTECTION_INFORMATION_RSA_H

#include "Encrypt.h"

class rsa : public Encrypt {
    int64_t C, D, N, P, Q, F;
public:
    rsa();

    rsa(int64_t C, int64_t D, int64_t P, int64_t Q);

    int64_t Encode(int64_t m) override;

    void Encode(std::istream &in, std::ostream &out) override;

    int64_t Decode(int64_t m) override;

    void Decode(std::istream &in, std::ostream &out) override;

    void print() override;

};


#endif //PROTECTION_INFORMATION_RSA_H
