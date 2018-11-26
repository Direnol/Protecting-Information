#include <ElGamal.h>

Signature::ElGamal::ElGamal(std::string in_f, std::string out_f) : Signature(std::move(in_f), std::move(out_f))
{
    auto[p, q] = op.get_simple_pair();
    P = p;
    Q = q;
    g = op.getG(P, Q);
    x = op.getRand(2, static_cast<uint64_t>(P - 2));
    y = op.powmod(g, x, P);
    std::cout << "Init: P = " << P << "; Q = " << Q << "; g = " << g << "; x = " << x << "; y = " << y << std::endl;
}

void Signature::ElGamal::WriteSign()
{
    try {
        this->sign_stream.open(this->sign_file_name, std::ios::out | std::ios::binary);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    if (this->sign_stream.is_open()) {
        this->sign_stream.write(reinterpret_cast<const char *>(&this->y), sizeof(this->y));
        this->sign_stream.write(reinterpret_cast<const char *>(&this->g), sizeof(this->g));

        this->sign_stream.write(reinterpret_cast<const char *>(&this->r), sizeof(this->r));
        this->sign_stream.write(reinterpret_cast<const char *>(&this->sign), sizeof(this->sign));
    }
    this->sign_stream.flush();
    this->sign_stream.close();
    this->sign_stream.clear();
}

void Signature::ElGamal::InitFromSignFile()
{
    try {
        this->sign_stream.open(this->sign_file_name, std::ios::in | std::ios::binary);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    if (this->sign_stream.is_open()) {
        this->sign_stream.read(reinterpret_cast<char *>(&this->y), sizeof(this->y));
        this->sign_stream.read(reinterpret_cast<char *>(&this->g), sizeof(this->g));

        this->sign_stream.read(reinterpret_cast<char *>(&this->r), sizeof(this->r));
        this->sign_stream.read(reinterpret_cast<char *>(&this->sign), sizeof(this->sign));
    }
    this->sign_stream.close();
    this->sign_stream.clear();
}

void Signature::ElGamal::Sign()
{
    this->ReadText();
    this->hash = 2 + this->TakingHash() % (P);
    k = op.get_simple(static_cast<uint64_t>(P - 1), 2, static_cast<uint64_t>(P - 2));
    k = op.get_simple(1, static_cast<uint64_t>(P - 1));
    auto[K, inverse_K] = op.getCD(k, (P - 1));
    if (K != k)
        std::cerr << "k and p - 1 is not simple" << std::endl;
    inverse_k = inverse_K;
    r = op.powmod(g, k, P);
    int64_t _u = (this->hash - x * r);
    while (_u < 0) _u += (P - 1);
    u = _u % (P - 1);
    this->sign = (inverse_k * u) % (P - 1);
    this->WriteSign();
}

bool Signature::ElGamal::TestSign()
{
    this->InitFromSignFile();
    this->ReadText();
    this->hash = 2 + this->TakingHash() % (P);
    int64_t right = op.powmod(g, hash, P);
    int64_t w = op.powmod(y, r, P);
    int64_t i = op.powmod(r, sign, P);
    int64_t left = (w * i) % P;
    bool res = (left == right);
    std::cout << "Sign: hash = " << hash << "; _right = " << right << "; w = " << w << "; i = " << i << "; _left = "
              << left << "; res = " << res << std::endl;
    return res;
}

void Signature::ElGamal::Print()
{
    std::cout << "Sign: hash = " << hash << "; k = " << k << "; r = " << r << "; u = " << u
              << "; sign = " << sign << std::endl;

}
