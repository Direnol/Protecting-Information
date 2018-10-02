//
// Created by direnol on 02.10.18.
//

#ifndef PROTECTION_INFORMATION_RSA_H
#define PROTECTION_INFORMATION_RSA_H

#include <Signature.h>

class RSA : public Signature {
private:

public:
    uint64_t Sign();

    uint64_t Unsign();
};

#endif //PROTECTION_INFORMATION_RSA_H
