//
// Created by stanley on 05.09.18.
//

#include "../inc/Encrypt.h"

// message, {Ca, Da}, {Cb, Db}
uint64_t Encrypt::shamir(uint64_t m, user_key A, user_key B, uint64_t p)
{
    uint64_t x1 = op.powmod(m, A.first, p);
    uint64_t x2 = op.powmod(x1, B.first, p);

    uint64_t x3 = op.powmod(x2, A.second, p);
    uint64_t x4 = op.powmod(x3, B.second, p);

    return m;
}

uint64_t Encrypt::gamal(uint64_t m, user_key B, uint64_t g, uint64_t k, uint64_t p)
{
    uint64_t r = op.powmod(g, k, p);
    uint64_t e = ((m % p) * op.powmod(B.second, k, p)) % p;

    uint64_t ma = ((e % p) * op.powmod(r, p - 1 - B.first, p)) % p;
    return ma;
}
