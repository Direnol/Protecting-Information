//
// Created by stanley on 05.09.18.
//

#ifndef CLION_ENCRYPT_H
#define CLION_ENCRYPT_H

#include <string>
#include <vector>
#include <iostream>
#include "Operation.h"

using string = std::string;
using data = std::vector<int64_t>;



class Encrypt {
private:
    Operation op;
public:
    struct gamal_data {
        data e;
        int64_t r;
    };

    struct rsa_data {
        data e;
        int64_t C;
        int64_t N;
    };
    int64_t shamir(int64_t m, user_key A, user_key B, int64_t p);

    gamal_data Egamal(data m, int64_t C, int64_t g, int64_t p);

    data Dgamal(gamal_data e, int64_t C, int64_t p);

    int64_t Evernam(int64_t m, int64_t k);

    int64_t Dvernam(int64_t e, int64_t k);

    rsa_data Ersa(data m, int64_t P, int64_t Q);

    data Drsa(rsa_data e);

    void printData(data m, std::ostream &out = std::cout);

    bool equal(data m, data e);
};


#endif //CLION_ENCRYPT_H
