//
// Created by stanley on 04.09.18.
//

#ifndef CLION_OPERATION_H
#define CLION_OPERATION_H

#include <vector>
#include <cstdint>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <chrono>
#include <random>

template<class T>
using vector = std::vector<T>;

template<class T, class K>
using map = std::map<T, K>;

template<class T, class K>
using pair = std::pair<T, K>;

using user_key = pair<int64_t, int64_t>;

template<class T>
using set = std::set<T>;

class Operation {
private:
public:
    Operation();

    ~Operation();

    int64_t powmod(int64_t a, int64_t b, int64_t c);

    int64_t gcd(int64_t a, int64_t b);

    user_key diff_hell(user_key A, user_key B);

    vector<int64_t> evklid(int64_t a, int64_t b);

    int64_t step_bg(int64_t y, int64_t a, int64_t p, int64_t m, int64_t k);

    int64_t getG(int64_t P, int64_t Q);

    bool simpleNum(int64_t P);

    void simNum(int64_t &P, int64_t &Q);

    int64_t getQ();

    pair<int64_t, int64_t> getCD(int64_t C, int64_t P);

    uint64_t getRand();
    uint64_t getRand(uint64_t a, uint64_t b);
};


#endif //CLION_OPERATION_H
