//
// Created by direnol on 12.11.18.
//

#ifndef PROTECTION_INFORMATION_DIGITALMONEY_H
#define PROTECTION_INFORMATION_DIGITALMONEY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdbool.h>
#include <time.h>
#include <Operation.h>
#include <iostream>
#include <openssl/md5.h>

class DigitalMoney {
    int64_t P, Q, C[5];
    int64_t N, D[5];
    Operation op;

    int64_t hash_calculation(int64_t m);

public:
    DigitalMoney();
    void list_many(int64_t amount_customer);
    void operation_customer(int64_t n);

};


#endif //PROTECTION_INFORMATION_DIGITALMONEY_H
