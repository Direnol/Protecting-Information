//
// Created by stanley on 09.09.18.
//

#ifndef CLION_SIGNATURE_H
#define CLION_SIGNATURE_H


#include <cstdint>
#include <Operation.h>
#include <string>
#include <openssl/md5.h>

using string = std::string;

class Signature {
    Operation op;

public:
    struct RSA_data {
        string h;
        int64_t S[MD5_DIGEST_LENGTH];
        int64_t D;
        int64_t N;
    };

    auto EnRsa(string data) -> RSA_data;

    bool DeRsa(RSA_data data);
};


#endif //CLION_SIGNATURE_H
