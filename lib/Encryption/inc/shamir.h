//
// Created by direnol on 01.10.18.
//

#ifndef PROTECTION_INFORMATION_SHAMIR_H
#define PROTECTION_INFORMATION_SHAMIR_H


#include "Encrypt.h"

class shamir : public Encrypt {
    int64_t C, D, P;
public:
    shamir(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t C,
           int64_t D, int64_t P);

    shamir(const std::string &in_file, const std::string &out_file, const std::string &key);

    explicit shamir(const std::string &in_file, const std::string &out_file, const std::string &key, int64_t P);

    int64_t Encode(int64_t m) override;


    int64_t Decode(int64_t m) override;


    void Encode() override;

    void Decode() override;

    void print() override;

    int64_t getP() const;

protected:
    void write_key() override;

    void read_key() override;
};


#endif //PROTECTION_INFORMATION_SHAMIR_H
