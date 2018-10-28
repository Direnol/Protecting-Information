#ifndef GOST_H

#include "Signature.h"


namespace Signature {
    class Gost : public Signature {

    private:
        int64_t C, D, P, Q, X, Y, b, a, r;
    protected:
        void WriteSign() override;

        void InitFromSignFile() override;

    public:
        Gost(std::string in_f, std::string out_f);

        void Sign() override;

        bool TestSign() override;

        void Print() override;

        ~Gost();
    };

}
#endif // VERNAM_H
