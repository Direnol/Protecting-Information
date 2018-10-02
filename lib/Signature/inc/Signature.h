//
// Created by stanley on 09.09.18.
//

#ifndef CLION_SIGNATURE_H
#define CLION_SIGNATURE_H


#include <cstdint>
#include <Operation.h>
#include <string>
#include <openssl/md5.h>

using std::string;

class Signature {
protected:
    Operation op;
    uint8_t hash;
    MD5_CTX md5_ctx;
public:
    virtual uint64_t Sign(int64_t m) = 0;

    virtual uint64_t Sign(std::istream in, std::ostream out) = 0;

    void Update(uint8_t *text, size_t n);

    void Clear();

    virtual uint64_t Unsign(int64_t m) = 0;

    virtual uint64_t Unsign(std::istream in, std::ostream out) = 0;

};


#endif //CLION_SIGNATURE_H
