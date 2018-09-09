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
    int64_t shamir(int64_t m, user_key A, user_key B, int64_t p);

    int64_t gamal(int64_t m, user_key B, int64_t g, int64_t p);

    int64_t vernam(int64_t m, int64_t k);

    int64_t rsa(int64_t m, int64_t P, int64_t Q);
};


#endif //CLION_ENCRYPT_H
