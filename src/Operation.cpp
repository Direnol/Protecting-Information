//
// Created by stanley on 04.09.18.
//

#include <cstring>
#include "../inc/Operation.h"

Operation::Operation() = default;

Operation::~Operation() = default;

// (a ** b) % c
uint64_t Operation::powmod(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t res = 1;
    for (; b != 0; b >>= 1) {
        if (b & 0x1) res = (res * a) % c;
        a = (a * a) % c;
    }
    return res;
}

uint64_t Operation::gcd(uint64_t a, uint64_t b)
{
    if (a == b) return a;
    if (a < b) std::swap(a, b);
    while (b) {
        uint64_t tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// {Xa, Xb}, {g, p}
user_key Operation::diff_hell(user_key A, user_key B)
{

    uint64_t Ya = powmod(B.first, A.first, B.second);
    uint64_t Yb = powmod(B.first, A.second, B.second);
    return {powmod(Yb, A.first, B.second),
            powmod(Ya, A.second, B.second)};
}

// ax + by = gcd(a, b)
// return {gcd(a, b), x, y}
vector<int64_t> Operation::evklid(int64_t a, int64_t b)
{
    if (a < b) std::swap(a, b);
    vector<int64_t> u = {a, 1, 0}, v = {b, 0, 1};
    while (v[0] != 0) {
        int64_t q = u[0] / v[0];
        vector<int64_t> t = {u[0] % v[0], u[1] - (q * v[1]), u[2] - (q * v[2])};
        u = v;
        v = t;
    }
    return u;
}

// y = (a ** x) mod p
// return x
uint64_t Operation::step_bg(uint64_t y, uint64_t a, uint64_t p, uint64_t m, uint64_t k)
{
    if ((m * k) <= p) throw std::runtime_error("Bad arguments: m and k");
    set<pair<uint64_t, uint64_t>> row;
    y %= p;
    uint64_t am = a % p;
    row.insert(std::make_pair(y, 0));
    for (uint64_t i = 1; i < m; ++i) {
        row.insert(std::make_pair((y * a) % p, i));
        a = (a * am) % p;
    }
    auto max = row.end();
    uint64_t maxi = 1;
    for (uint64_t i = 1; i <= k; ++i) {
        max = std::lower_bound(row.begin(), row.end(), static_cast<pair<uint64_t, uint64_t>>(std::make_pair(a, 0)));
        if (max->first == a) {
            maxi = i;
            break;
        } else {
            max = row.end();
        }
        a = (a * am) % p;
    }
    if (max == row.end()) throw std::runtime_error("Bad rows");
    return (maxi * m) - max->second;
}

user_key Operation::gen_cd(uint64_t c)
{
    return user_key();
}
