//
// Created by stanley on 05.09.18.
//

#include "../inc/Encrypt.h"

// message, {Ca, Da}, {Cb, Db}
int64_t Encrypt::shamir(int64_t m, user_key A, user_key B, int64_t p)
{
    int64_t x1 = op.powmod(m, A.first, p);
    int64_t x2 = op.powmod(x1, B.first, p);

    int64_t x3 = op.powmod(x2, A.second, p);
    int64_t x4 = op.powmod(x3, B.second, p);

    return x4;
}

int64_t Encrypt::gamal(int64_t m, user_key B, int64_t g, int64_t p)
{
    int64_t k = 1 + rand() % (p - 1);
    int64_t r = op.powmod(g, k, p);
    int64_t e = ((m % p) * op.powmod(B.second, k, p)) % p;

    int64_t ma = ((e % p) * op.powmod(r, p - 1 - B.first, p)) % p;
    return ma;
}

int64_t Encrypt::vernam(int64_t m, int64_t k)
{
    int64_t e = k ^m;

    int64_t m1 = e ^k;
    return m1;
}

int64_t Encrypt::rsa(int64_t m, int64_t P, int64_t Q)
{
    int64_t Nb = P * Q;
    int64_t F = (P - 1) * (Q - 1);
    auto[Db, Cb] = op.getCD(1 + rand() % (F - 1), F + 1);

    int64_t e = op.powmod(m, Db, Nb);

    return op.powmod(e, Cb, Nb);
}

