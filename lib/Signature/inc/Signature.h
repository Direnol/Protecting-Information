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
        std::string output_file_name;
        std::ifstream input_stream;
        std::ofstream output_stream;
        std::string text;
        Operation op;
        uint64_t hash;
        MD5_CTX md5_ctx;

        void ReadText();
        uint64_t TakingHash();
    public:
        Signature(std::string in_f, std::string out_f);

        virtual uint64_t Sign() = 0;

        virtual uint64_t Unsign() = 0;

        virtual void Print() = 0;
    };
}

#endif //CLION_SIGNATURE_H
