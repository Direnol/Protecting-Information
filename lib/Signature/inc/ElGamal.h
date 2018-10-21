//
// Created by evgenii on 20.10.18.
//

#ifndef PROTECTION_INFORMATION_ELGAMAL_H
#define PROTECTION_INFORMATION_ELGAMAL_H

#include <Signature.h>
#include <utility>

namespace Signature {
    class ElGamal : public Signature {
    private:
        int64_t P, Q, g, x, y, k, r, u, inverse_k;
        void WriteSign() override;
        void InitFromSignFile() override;
    public:
        ElGamal(std::string in_f, std::string out_f);

        void Sign() override;

        bool TestSign() override;

        void Print() override;
    };
}

#endif //PROTECTION_INFORMATION_ELGAMAL_H
