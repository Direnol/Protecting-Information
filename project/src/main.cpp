#include <Encrypt.h>
#include <OperationOnFile.h>
#include <Signature.h>
#include <Operation.h>
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
    int64_t m = 10;
    int64_t P = 23;
    int64_t g = 5; //1 + (rand() % P);
    auto[Ca, Da] = op.getCD(7, P);
    auto[Cb, Db] = op.getCD(5, P);
    printf("Ca: %ld\t Da: %ld\n"
           "Cb: %ld\t Db: %ld\n", Ca, Da, Cb, Db);

    data info = {1, 2, 3};
    Encrypt::gamal_data gd = encrypt.Egamal(info, Ca, g, P);
    data res = encrypt.Dgamal(gd, Ca, P);
    std::cout << "Gamal: " << std::boolalpha << encrypt.equal(info, res) << std::endl;
    encrypt.printData(res);
    std::cout << std::endl;


    Encrypt::rsa_data rd = encrypt.Ersa(info, 3, 11);
    res = encrypt.Drsa(rd);
    std::cout << "Rsa: " << std::boolalpha << encrypt.equal(info, res) << std::endl;
    encrypt.printData(res);
    std::cout << std::endl;

    std::cout << encrypt.shamir(m, {Ca, Da}, {Cb, Db}, P) << std::endl;

    return 0;
}