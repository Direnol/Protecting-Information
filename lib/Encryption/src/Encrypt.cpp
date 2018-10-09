//
// Created by stanley on 05.09.18.
//

#include <Encrypt.h>

Encrypt::Encrypt(const std::string &in_file, const std::string &out_file, const std::string &key)
        : in_file(in_file), out_file(out_file), key(key)
{}

void Encrypt::setIn_file(const std::string &in_file)
{
    Encrypt::in_file = in_file;
}

void Encrypt::setOut_file(const std::string &out_file)
{
    Encrypt::out_file = out_file;
}

void Encrypt::Swap_files()
{
    std::swap(this->in_file, this->out_file);
}

void Encrypt::_encode(std::ifstream &in, std::ofstream &out)
{
    int8_t m;
    while (in >> m) {
        auto e = Encode(m);
        out.write(reinterpret_cast<const char *>(&e), sizeof(e));
    }
}

void Encrypt::_decode(std::ifstream &in, std::ofstream &out)
{
    int64_t e;
    while (in.read(reinterpret_cast<char *>(&e), sizeof(e))) {
        out << (char) Decode(e);
    }
}

pair<std::ifstream, std::ofstream> Encrypt::open()
{
    std::ifstream in(this->in_file, std::ifstream::binary);
    std::ofstream out(this->out_file, std::ofstream::binary);
    return std::make_pair(std::move(in), std::move(out));
}

void Encrypt::Encode()
{
    auto[in, out] = open();

    write_key();
    _encode(in, out);
}

void Encrypt::Decode()
{
    auto[in, out] = open();

    read_key();
    _decode(in, out);
}
