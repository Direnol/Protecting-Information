//
// Created by stanley on 08.09.18.
//

#include "../inc/OperationOnFile.h"

OperationOnFile::OperationOnFile(std::string in, std::string out) :
        in(in), out(out), cout(false)
{}

void OperationOnFile::Crypto(lambdaCrypt f)
{
    std::ostream *lout = &out;
    if (cout) lout = &std::cout;

    while (in) {
        char b = 0;
        in.read(&b, 1);
        if (!b) throw std::runtime_error("Bad read input file for crypt");
        (*lout) << f(static_cast<int8_t>(b));
    }
}

bool OperationOnFile::ChangeFile(std::string in, std::string out)
{
    this->in.close();
    this->out.close();
    this->in.open(in);
    this->out.open(out);
    cout = false;
    return this->in.is_open() && this->out.is_open();
}
