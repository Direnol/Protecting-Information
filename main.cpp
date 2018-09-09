#include "inc/Encrypt.h"
#include "inc/OperationOnFile.h"
#include "inc/Signature.h"

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
    int64_t m = 20;
    int64_t P = 23;
    auto[Ca, Da] = op.getCD(7, P);
    auto[Cb, Db] = op.getCD(5, P);
    printf("Ca: %ld\t Da: %ld\n"
           "Cb: %ld\t Db: %ld\n", Ca, Da, Cb, Db);

    std::cout << encrypt.shamir(m, {Ca, Da}, {Cb, Db}, P) << std::endl;
    std::cout << encrypt.gamal(m, {13, 21}, 5, P) << std::endl;

    std::cout << encrypt.rsa(m, 3, 11) << std::endl;

    Signature sig;
    Signature::RSA_data d = sig.EnRsa("lol");
    std::cout << std::boolalpha << sig.DeRsa(d) << std::endl;
    return 0;
}