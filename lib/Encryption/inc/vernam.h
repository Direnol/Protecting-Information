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

    explicit vernam(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t k);

    vernam(const std::string &in_file, const std::string &out_file, const std::string &key);

    int64_t Encode(int64_t m) override;

    void Encode() override;

    int64_t Decode(int64_t m) override;

    void Decode() override;
};


#endif //PROTECTION_INFORMATION_VERNAM_H
