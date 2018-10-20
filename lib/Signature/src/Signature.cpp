#include <Signature.h>

uint64_t Signature::Signature::TakingHash() {
    auto result = MD5((const unsigned char *)this->text.c_str(), this->text.size(), nullptr);
    int64_t hash = 2;
    uint64_t mod = 12341234;
    for (unsigned int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        hash = this->op.powmod(hash, result[i], mod);
    }
    return static_cast<uint64_t>(hash);
}

Signature::Signature::Signature(std::string in_f, std::string out_f) {
    this->input_file_name = std::move(in_f);
    this->sign_file_name = std::move(out_f);
}

void Signature::Signature::ReadText() {
    this->text.clear();
    try {
        this->input_stream.open(this->input_file_name, std::ios_base::binary);
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    if (this->input_stream.is_open()) {
        char m;
        while (input_stream.read(&m, sizeof m)) {
            this->text += m;
        }
    }
    this->input_stream.close();
    this->input_stream.clear();
}
