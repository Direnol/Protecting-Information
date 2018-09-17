//
// Created by stanley on 13.09.18.
//

#include <Encrypt.h>
#include <iostream>

int main() {
    Operation op;
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

    int64_t evern_ret = encrypt.Evernam(m, 123);
    std::cout << encrypt.Dvernam(evern_ret, 123);

    return 0;
}