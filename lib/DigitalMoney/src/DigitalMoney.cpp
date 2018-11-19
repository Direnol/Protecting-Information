//
// Created by direnol on 12.11.18.
//

#include "DigitalMoney.h"

DigitalMoney::DigitalMoney()
{
    auto[p, q] = op.get_simple_pair();
    P = p;
    Q = q;
    N = P * Q;
    auto F = (P - 1) * (Q - 1);
    for (int i = 1, j = 1; i <= 1000; i *= 10, j++) {
        auto[d, c] = op.getCD(1 + op.getRand() % (F - 1), F);
        D[j] = d;
        C[j] = c;
    }
}

int64_t DigitalMoney::hash_calculation(int64_t m)
{
    auto* h = reinterpret_cast<unsigned char*>(&m);
    auto result = MD5(h, sizeof(h), nullptr);
    int64_t hash = 2;
    uint64_t mod = 12341234;
    for (unsigned int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        hash = op.powmod(hash, result[i], mod);
    }
    return static_cast<uint64_t>(hash);
}

// n = amount_customer
// n_home_f - это переменная найденная от f(n) по слепой подпеси (f(n) * r^d) mod N
// s_home_f - это переменная найденная от n_home_f по слепой подпеси n_home_f^c mod N
// s == f(n)^c mod N calculation as (s_home_f * r^(-1)) mod N)
// банкнота определяется как {n, s_home_f}
void DigitalMoney::operation_customer(int64_t n)
{
    std::cout << "n=" << n << std::endl;
    int position_domination = 0;
    for (auto i = n; i > 0; i /= 10) {
        position_domination++;
    }
    //std::cout << "position_domination=%ld\n", position_domination);
    int64_t f_n, r, r_inversion;
    f_n = hash_calculation(n) % N;
    auto[_r, _r_inv] = op.getCD(0, N);
    r = _r;
    r_inversion = _r_inv;

    int64_t n_home_f, s_home_f, s;
    n_home_f = (f_n * op.powmod(r, D[position_domination], N)) % N;

    // s_home_f this code_BANK
    s_home_f = op.powmod(n_home_f, C[position_domination], N);

    //{n, s}
    s = (r_inversion * s_home_f) % N;

    f_n = hash_calculation(n) % N;
    if (op.powmod(s, D[position_domination], N) == f_n) {
        std::cout << "Покупка совершена!" << std::endl;
    } else {
        std::cout << "Купюра не действительна" << std::endl;
    }
}

void DigitalMoney::list_many(int64_t amount_customer)
{
    int64_t begin_domination = 1000;
    do {
        if ((amount_customer / begin_domination) > 0) {
            amount_customer -= begin_domination;
            operation_customer(begin_domination);
        } else {
            begin_domination /= 10;
        }
    } while (amount_customer > 0);
}

