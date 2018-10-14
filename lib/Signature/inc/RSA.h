#include <utility>

//
// Created by direnol on 02.10.18.
//

#ifndef PROTECTION_INFORMATION_RSA_H
#define PROTECTION_INFORMATION_RSA_H

#include <Signature.h>
#include <cstring>

namespace Signature {
    class RSA : public Signature {
    private:
        int64_t P, Q, N, F, c, d;
        void WriteSign() override;
        void InitFromSignFile() override;
    public:
        RSA(std::string in_f, std::string out_f);

        void Sign() override;

        bool TestSign() override;

        void Print() override;
    };
}

#endif //PROTECTION_INFORMATION_RSA_H
