//
// Created by direnol on 01.10.18.
//

#ifndef PROTECTION_INFORMATION_RSA_H
#define PROTECTION_INFORMATION_RSA_H

#include "Encrypt.h"

class rsa : public Encrypt {
    int64_t C, D, N, P, Q, F;
public:
    rsa(const std::string &in_file, const std::string &out_file, const std::string &key);

    rsa(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t C, int64_t D,
        int64_t P, int64_t Q);

    void print() override;

    int64_t Encode(int64_t m) override;

    int64_t Decode(int64_t m) override;


protected:
    void write_key() override;

    void read_key() override;

public:
    void Encode() override;

    void Decode() override;
};


#endif //PROTECTION_INFORMATION_RSA_H
