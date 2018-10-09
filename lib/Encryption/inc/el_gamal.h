//
// Created by direnol on 01.10.18.
//

#ifndef PROTECTION_INFORMATION_EL_GAMAL_H
#define PROTECTION_INFORMATION_EL_GAMAL_H


#include "Encrypt.h"

class el_gamal : public Encrypt {
    int64_t P, Q, C, D, g, k, r;

public:

    void print() override;

    el_gamal(const std::string &in_file, const std::string &out_file, const std::string &key);

    el_gamal(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t P, int64_t Q,
             int64_t C, int64_t g);

    int64_t Encode(int64_t m) override;

    void Encode() override;

    int64_t Decode(int64_t m) override;

    void Decode() override;

protected:
    void write_key() override;

    void read_key() override;
};


#endif //PROTECTION_INFORMATION_EL_GAMAL_H
