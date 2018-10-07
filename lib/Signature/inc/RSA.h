#include <utility>

//
// Created by direnol on 02.10.18.
//

#ifndef PROTECTION_INFORMATION_RSA_H
#define PROTECTION_INFORMATION_RSA_H

#include <Signature.h>

namespace Signature {
    class RSA : public Signature {
    private:
        int64_t P, Q, N, F, c, d;
    public:
        RSA(std::string in_f, std::string out_f);

        uint64_t Sign() override;

        uint64_t Unsign() override;

        void Print() override;
    };
}

#endif //PROTECTION_INFORMATION_RSA_H
