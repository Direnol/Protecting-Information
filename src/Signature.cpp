//
// Created by stanley on 09.09.18.
//

#include "../inc/Signature.h"

auto Signature::EnRsa(string data) -> Signature::RSA_data
{
    int64_t P = op.getQ(), Q = op.getQ();
    RSA_data rsaData;

    while (P == Q) {
        P = op.getQ();
        Q = op.getQ();
    }
    rsaData.N = P * Q;
    int64_t F = (P - 1) * (Q - 1);

    auto[D, C] = op.getCD(1 + rand() % (F - 1), F + 1);
    rsaData.D = D;

    unsigned char *result = MD5((const unsigned char *) data.c_str(), data.length(), nullptr);
    for (auto i = 0; i < MD5_DIGEST_LENGTH; ++i)
        rsaData.S[i] = op.powmod(result[i], C, rsaData.N);
    rsaData.h = (char *) result;
    return rsaData;
}

bool Signature::DeRsa(Signature::RSA_data data)
{
    int64_t w[MD5_DIGEST_LENGTH];

    for (auto i = 0; i < MD5_DIGEST_LENGTH; i++) {
        w[i] = op.powmod(data.S[i], data.D, data.N);
        if (w[i] != data.h[i])
            return false;
    }
    return true;
}
