//
// Created by direnol on 01.10.18.
//

#ifndef PROTECTION_INFORMATION_VERNAM_H
#define PROTECTION_INFORMATION_VERNAM_H


#include <cstdint>
#include "Encrypt.h"

class vernam : public Encrypt {
    int64_t k;
public:
    void print() override;

    explicit vernam(int64_t k);

    vernam();

    int64_t Encode(int64_t m) override;

    void Encode(std::istream &in, std::ostream &out) override;

    int64_t Decode(int64_t m) override;

    void Decode(std::istream &in, std::ostream &out) override;
};


#endif //PROTECTION_INFORMATION_VERNAM_H
