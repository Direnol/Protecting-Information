#include <RSA.h>
#include <ElGamal.h>
#include <Gost.h>

int main()
{
    std::string input_file = "input";
    std::string output_file = "RSA_sign";
    Signature::RSA *signature = new Signature::RSA(input_file, output_file);
    signature->Sign();
    if (signature->TestSign()) {
        std::cout << "Test pass" << std::endl;
    } else {
        std::cout << "Test fail" << std::endl;
    }

    std::string output_file_ElGamal = "ElGamal_sign";
    Signature::ElGamal *signatureElGamal = new Signature::ElGamal(input_file, output_file_ElGamal);
    signatureElGamal->Sign();
    if (signatureElGamal->TestSign()) {
        std::cout << "Test pass" << std::endl;
    } else {
        std::cout << "Test fail" << std::endl;
    }

    std::string output_file_Gost = "Gost_sign";
    auto signatureGost = new Signature::Gost(input_file, output_file_Gost);
    signatureGost->Sign();
    if (signatureGost->TestSign()) {
        std::cout << "Test pass" << std::endl;
    } else {
        std::cout << "Test fail" << std::endl;
    }

    delete signature;
    delete signatureElGamal;
    delete signatureGost;

    return 0;
}
