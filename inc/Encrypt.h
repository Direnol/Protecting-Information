//
// Created by stanley on 05.09.18.
//

#ifndef CLION_ENCRYPT_H
#define CLION_ENCRYPT_H

#include <string>
#include "Operation.h"

using string = std::string;

class Encrypt {
private:
    Operation op;
public:
    uint64_t shamir(uint64_t m, user_key A, user_key B, uint64_t p);

    uint64_t gamal(uint64_t m, user_key B, uint64_t g, uint64_t k, uint64_t p);

    uint64_t vernam();

    uint64_t rsa();
};


#endif //CLION_ENCRYPT_H
