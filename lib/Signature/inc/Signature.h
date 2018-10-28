#ifndef CLION_SIGNATURE_H
#define CLION_SIGNATURE_H


#include <cstdint>
#include <Operation.h>
#include <string>
#include <openssl/md5.h>
#include <fstream>
#include <iostream>
#include <utility>


namespace Signature {

    class Signature {
    protected:
        std::string input_file_name;
        std::string sign_file_name;
        std::ifstream input_stream;
        std::fstream sign_stream;
        std::string text;
        Operation op;
        uint64_t hash;
        MD5_CTX md5_ctx;

        int64_t sign;

        void ReadText();
        virtual void WriteSign() = 0;
        virtual void InitFromSignFile() = 0;
        uint64_t TakingHash();
    public:
        Signature(std::string in_f, std::string out_f);

        virtual void Sign() = 0;

        virtual bool TestSign() = 0;

        virtual void Print() = 0;
    };
}

#endif //CLION_SIGNATURE_H
