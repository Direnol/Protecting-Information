#include <Operation.h>
#include <iostream>

int main() {
    Operation op;
    std::cout << "Operation PowMod(5, 7, 23) result: " << op.powmod(5, 7, 23) << std::endl; // 17
    std::cout << "Operation PowMod(5, 13, 23) result: " << op.powmod(5, 13, 23) << std::endl; // 21
    std::cout << "Operation Gcd(100000, 1000230) result: " << op.gcd(100000, 1000230) << std::endl;
    user_key ans = op.diff_hell({7, 13}, {5, 23});
    std::cout << "Diffie-Hellman system ({7, 13}, {5, 23}) return: " << ans.first << ' ' << ans.second << std::endl; // 10 10
    evklid_ret_t evk = op.evklid(28, 19);
    std::cout << "Extended Evklid (28, 19) return: " << evk[0] << " x=" << evk[1] << " y=" << evk[2] << std::endl; // 1 -2 3
    std::cout << "Baby-step giant-step (9, 2, 23, 6, 4) return: " << op.step_bg(9, 2, 23, 6, 4) << std::endl; // 5

    return 0;
}