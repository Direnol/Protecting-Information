//
// Created by direnol on 02.10.18.
//

#include <RSA.h>

Signature::RSA::RSA(std::string in_f, std::string out_f) : Signature(std::move(in_f), std::move(out_f)) {
    auto[p, q] = op.get_simple_pair();
    this->P = p;
    this->Q = q;
    this->N = P * Q;
    this->F = (P - 1) * (Q - 1);
    auto[d, c] = op.getCD(0, F);
    this->c = c;
    this->d = d;
}

void Signature::RSA::Sign() {
    this->ReadText();
    this->hash = this->TakingHash();
    this->sign = this->op.powmod(this->hash, this->c, this->N);
    this->WriteSign();
}

bool Signature::RSA::TestSign() {
    this->InitFromSignFile();
    this->ReadText();
    this->hash = this->TakingHash();
    int64_t w = this->op.powmod(this->sign, this->d, this->N);
    bool res = this->hash == w;
    return res;
}

void Signature::RSA::Print() {

}

void Signature::RSA::WriteSign() {
    try {
        this->sign_stream.open(this->sign_file_name, std::ios::out | std::ios::binary);
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    if (this->sign_stream.is_open()) {
        this->sign_stream.write(reinterpret_cast<const char *>(&this->sign), sizeof(this->sign));
        this->sign_stream.write(reinterpret_cast<const char *>(&this->N), sizeof(this->N));
        this->sign_stream.write(reinterpret_cast<const char *>(&this->d), sizeof(this->d));
    }
    this->sign_stream.flush();
    this->sign_stream.close();
    this->sign_stream.clear();
}

void Signature::RSA::InitFromSignFile() {
    try {
        this->sign_stream.open(this->sign_file_name, std::ios::in | std::ios::binary);
    } catch (std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    if (this->sign_stream.is_open()) {
        this->sign_stream.read(reinterpret_cast<char *>(&this->sign), sizeof(this->sign));
        this->sign_stream.read(reinterpret_cast<char *>(&this->N), sizeof(this->N));
        this->sign_stream.read(reinterpret_cast<char *>(&this->d), sizeof(this->d));
    }
    this->sign_stream.close();
    this->sign_stream.clear();
}
