#include <RSA.h>
#include <ElGamal.h>

int main() {
    std::string input_file = "input";
    std::string output_file = "RSA_sign";
    Signature::RSA* signature = new Signature::RSA(input_file, output_file);
    signature->Sign();
    if (signature->TestSign()) {
        std::cout << "Test pass" << std::endl;
    }
    else {
        std::cout << "Test fail" << std::endl;
    }

    std::string output_file_ElGamal = "ElGamal_sign";
    Signature::ElGamal* signatureElGamal = new Signature::ElGamal(input_file, output_file_ElGamal);
    signatureElGamal->Sign();
    if (signatureElGamal->TestSign()) {
        std::cout << "Test pass" << std::endl;
    }
    else {
        std::cout << "Test fail" << std::endl;
    }
    return 0;
}
