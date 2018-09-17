//
// Created by stanley on 05.09.18.
//
#include <Encrypt.h>

// message, {Ca, Da}, {Cb, Db}
int64_t Encrypt::shamir(int64_t m, user_key A, user_key B, int64_t p)
{
    int64_t x1 = op.powmod(m, A.first, p);
    int64_t x2 = op.powmod(x1, B.first, p);

    int64_t x3 = op.powmod(x2, A.second, p);
    int64_t x4 = op.powmod(x3, B.second, p);

    return x4;
}

Encrypt::gamal_data Encrypt::Egamal(data m, int64_t C, int64_t g, int64_t p)
{
    int64_t k = 1 + op.getRand() % (p - 2);
    int64_t r = op.powmod(g, k, p);
    int64_t D = op.powmod(g, C, p);
    data e;
    for (auto d : m) {
        e.push_back(((d % p) * op.powmod(D, k, p)) % p);
    }
    return {e, r};
}

data Encrypt::Dgamal(gamal_data e, int64_t C, int64_t p)
{
    data m;
    for (auto ma : e.e) {
        m.push_back(((ma % p) * op.powmod(e.r, p - 1 - C, p)) % p);
    }
    return m;
}

int64_t Encrypt::Evernam(int64_t m, int64_t k)
{
    return k ^ m;

}

int64_t Encrypt::Dvernam(int64_t e, int64_t k)
{
    return e ^ k;
}

Encrypt::rsa_data Encrypt::Ersa(data m, int64_t P, int64_t Q)
{
    int64_t Nb = P * Q;
    int64_t F = (P - 1) * (Q - 1);
    auto[Db, Cb] = op.getCD(1 + op.getRand() % (F - 1), F + 1);
    data e;
    for (auto d : m) {
        e.push_back(op.powmod(d, Db, Nb));
    }
    return {e, Cb, Nb};
}

data Encrypt::Drsa(rsa_data e)
{
    data m;
    for (auto d : e.e) {
        m.push_back(op.powmod(d, e.C, e.N));
    }
    return m;
}

void Encrypt::printData(data m, std::ostream &out)
{
    std::cout << "[";
    for (auto a : m) {
        out << a << ' ';
    }
    std::cout << "]";
}

bool Encrypt::equal(data m, data e)
{
    for (auto i = 0; i < m.size(); ++i) {
        if (m[i] != e[i]) return false;
    }
    return true;
}

