#include "inc/Encrypt.h"
#include <iostream>

int main() {
    Operation op;
    std::cout << op.powmod(5, 7, 23) << std::endl; // 17
    std::cout << op.powmod(5, 13, 23) << std::endl; // 21
    std::cout << op.gcd(100000, 1000230) << std::endl;
    user_key ans = op.diff_hell({7, 13}, {5, 23});
    std::cout << ans.first << ' ' << ans.second << std::endl; // 10 10
    vector<int64_t> evk = op.evklid(28, 19);
    std::cout << evk[0] << ' ' << evk[1] << ' ' << evk[2] << std::endl; // 1 -2 3
    std::cout << op.step_bg(9, 2, 23, 6, 4) << std::endl; // 5

    Encrypt encrypt;
    std::cout << encrypt.shamir(10, {7, 19}, {5, 9}, 23) << std::endl;
    std::cout << encrypt.gamal(17, {13, 21}, 5, 7, 23) << std::endl;
    return 0;
}