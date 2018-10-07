#include <RSA.h>

int main() {
    std::string input_file = "input";
    std::string output_file = "RSA_sign_output";
    Signature::RSA* signature = new Signature::RSA(input_file, output_file);
//    Operation op;
//    int64_t m = 123;
    return 0;
}
