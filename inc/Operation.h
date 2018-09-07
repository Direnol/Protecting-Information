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

template<class T>
using vector = std::vector<T>;

template<class T, class K>
using map = std::map<T, K>;

template<class T, class K>
using pair = std::pair<T, K>;

using user_key = pair<uint64_t, uint64_t>;

template<class T>
using set = std::set<T>;

class Operation {
private:
public:
    Operation();

    ~Operation();

    uint64_t powmod(uint64_t a, uint64_t b, uint64_t c);

    uint64_t gcd(uint64_t a, uint64_t b);

    user_key diff_hell(user_key A, user_key B);

    vector<int64_t> evklid(int64_t a, int64_t b);

    uint64_t step_bg(uint64_t y, uint64_t a, uint64_t p, uint64_t m, uint64_t k);

    user_key gen_cd(uint64_t c);
};


#endif //CLION_OPERATION_H
