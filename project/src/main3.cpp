#include <RSA.h>

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
    return 0;
}
