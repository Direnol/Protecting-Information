//
// Created by stanley on 04.09.18.
//

#include <cstring>
#include "../inc/Operation.h"

Operation::Operation() = default;

Operation::~Operation() = default;

// (a ** b) % c
int64_t Operation::powmod(int64_t a, int64_t b, int64_t c)
{
    int64_t res = 1;
    a %= c;
    for (; b != 0; b >>= 1) {
        if (b & 0x1) res = (res * a) % c;
        a = (a * a) % c;
    }
    return res;
}

int64_t Operation::gcd(int64_t a, int64_t b)
{
    if (a == b) return a;
    if (a < b) std::swap(a, b);
    while (b) {
        int64_t tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// {Xa, Xb}, {g, p}
user_key Operation::diff_hell(user_key A, user_key B)
{

    int64_t Ya = powmod(B.first, A.first, B.second);
    int64_t Yb = powmod(B.first, A.second, B.second);
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
    if (u[2] <= 0) u[2] += a;
    return u;
}

// y = (a ** x) mod p
// return x
int64_t Operation::step_bg(int64_t y, int64_t a, int64_t p, int64_t m, int64_t k)
{
    if ((m * k) <= p) throw std::runtime_error("Bad arguments: m and k");
    set<pair<int64_t, int64_t>> row;
    y %= p;
    int64_t am = a % p;
    row.insert(std::make_pair(y, 0));
    for (int64_t i = 1; i < m; ++i) {
        row.insert(std::make_pair((y * a) % p, i));
        a = (a * am) % p;
    }
    auto max = row.end();
    int64_t maxi = 1;
    for (int64_t i = 1; i <= k; ++i) {
        max = std::lower_bound(row.begin(), row.end(), static_cast<pair<int64_t, int64_t>>(std::make_pair(a, 0)));
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

int64_t Operation::getG(int64_t P, int64_t Q)
{
    int64_t g = 2 + rand() % P;
    while (true) {
        if (powmod(g, Q, P) == 1 && (1 < g) && (g < (P - 1)))
            break;
        g = 2 + rand() % P;
    }
    return g;
}

bool Operation::simpleNum(int64_t P)
{
    auto p = static_cast<int64_t>(sqrtl(P));
    for (int64_t i = 2; i <= p; i++) {
        if ((P % i) == 0) return false;
    }
    return true;
}

void Operation::simNum(int64_t &P, int64_t &Q)
{
    while (true) {
        Q = getQ();
        P = 2 * Q + 1;
        if (simpleNum(P))
            break;
    }
}

int64_t Operation::getQ()
{
    int64_t Q = 0;
    while (true) {
        Q = static_cast<int64_t>(5000 + rand() % 5000);
        if (simpleNum(Q)) return Q;
    }
}

pair<int64_t, int64_t> Operation::getCD(int64_t C, int64_t P)
{
    auto ans = evklid(C, (P - 1));
    while (ans[0] != 1) {
        C = 1 + rand() % (P - 1);
        ans = evklid(C, (P - 1));
    }
    return std::make_pair(C, ans[2]);
}


