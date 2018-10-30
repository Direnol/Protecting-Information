#include <utility>

#include <Gost.h>

void Signature::Gost::Sign()
{
    this->ReadText();
    this->hash = 1 + this->TakingHash() % (this->Q - 1);
    int64_t k;
    do {
        do {
            k = 1 + op.getRand() % (Q - 1);
            r = op.powmod(a, k, P) % Q;
        } while (r == 0);
        this->sign = (k * this->hash + X * r) % Q;
    } while (this->sign == 0);

    this->WriteSign();
}

bool Signature::Gost::TestSign()
{
    this->InitFromSignFile();
    this->ReadText();
    this->hash = 1 + this->TakingHash() % (this->Q - 1);
    if (r == 0 || r >= Q || this->sign == 0 || this->sign >= Q)
        return false;


    auto inverse_hash = op.evklid(this->hash, this->Q);
    auto u1 = (this->sign * inverse_hash[2]) % Q;
    auto u2 = ((-r) * inverse_hash[2]) % Q;
    while (u2 < 0) u2 += Q;
    auto v = ((op.powmod(a, u1, P) * (op.powmod(Y, u2, P))) % P) % Q;
    return v == r;
}

void Signature::Gost::Print()
{

}

void Signature::Gost::WriteSign()
{
    try {
        this->sign_stream.open(this->sign_file_name, std::ios::out | std::ios::binary);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    if (this->sign_stream.is_open()) {
        this->sign_stream.write(reinterpret_cast<const char *>(&this->sign), sizeof(this->sign));
        this->sign_stream.write(reinterpret_cast<const char *>(&this->r), sizeof(this->r));
    }
    this->sign_stream.flush();
    this->sign_stream.close();
    this->sign_stream.clear();
}

void Signature::Gost::InitFromSignFile()
{
    try {
        this->sign_stream.open(this->sign_file_name, std::ios::in | std::ios::binary);
    } catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    if (this->sign_stream.is_open()) {
        this->sign_stream.read(reinterpret_cast<char *>(&this->sign), sizeof(this->sign));
        this->sign_stream.read(reinterpret_cast<char *>(&this->r), sizeof(this->r));
    }
    this->sign_stream.close();
    this->sign_stream.clear();
}

Signature::Gost::Gost(std::string in_f, std::string out_f) : Signature(std::move(in_f), std::move(out_f))
{

    Q = op.get_simple(16384, 32767);

    b = op.getRand(16384, 32767);
    P = (b * Q) + 1;
    while (!op.is_simple(P)) {
        b = op.getRand(16384, 32767);
        P = (b * Q) + 1;
    }
//    std::cout << "Q = " << Q << " b = " << b << " P = " << P << std::endl;
    int64_t g;
    do {
        g = 2 + op.getRand() % P;
        a = op.powmod(g, b, P);
//        std::cout << "a: " << a << "; g: " << g << std::endl;
    } while (a == 1);
    X = 1 + op.getRand() % (Q - 1);
    Y = op.powmod(a, X, P);
//    std::cout << "Init" << std::endl;
}

Signature::Gost::~Gost() = default;
