//
// Created by stanley on 06.09.18.
//

#ifndef CLION_BIGINTEGER_H
#define CLION_BIGINTEGER_H


#include <cstdint>
#include <vector>
#include <string>

class BigInteger {
    std::vector<uint8_t> bit;
    bool positive;
    bool zero;
public:
    BigInteger() : positive(true), zero(true)
    {};

    BigInteger(const std::string num);

    BigInteger(const int64_t num);

    BigInteger(const uint64_t num);

    BigInteger(const long double num);

    ~BigInteger() = default;

    BigInteger &operator+(const BigInteger &rhs) const;

    BigInteger &operator-(const BigInteger &rhs) const;

    BigInteger &operator*(const BigInteger &rhs) const;

    BigInteger &operator/(const BigInteger &rhs) const;

    BigInteger &operator%(const BigInteger &rhs) const;

    BigInteger &operator&(const BigInteger &rhs) const;

    BigInteger &operator|(const BigInteger &rhs) const;

    BigInteger &operator^(const BigInteger &rhs) const;

    BigInteger &operator~() const;

    BigInteger &operator!() const;

    BigInteger &operator-() const;

    BigInteger &operator+() const;

    BigInteger &operator&&(const BigInteger &rhs) const;

    BigInteger &operator||(const BigInteger &rhs) const;

    BigInteger &operator+=(const BigInteger &rhs) const;

    BigInteger &operator-=(const BigInteger &rhs) const;

    BigInteger &operator*=(const BigInteger &rhs) const;

    BigInteger &operator/=(const BigInteger &rhs) const;

    BigInteger &operator%=(const BigInteger &rhs) const;

    BigInteger &operator&=(const BigInteger &rhs) const;

    BigInteger &operator|=(const BigInteger &rhs) const;

    BigInteger &operator^=(const BigInteger &rhs) const;

    BigInteger &operator<<(const BigInteger &rhs) const;

    BigInteger &operator>>(const BigInteger &rhs) const;

    BigInteger &operator>>=(const BigInteger &rhs) const;

    BigInteger &operator<<=(const BigInteger &rhs) const;

    BigInteger &operator=(const BigInteger &rhs) = default;

    bool operator==(const BigInteger &rhs) const;

    bool operator<(const BigInteger &rhs) const;

    bool operator>(const BigInteger &rhs) const;

    bool operator<=(const BigInteger &rhs) const;

    bool operator>=(const BigInteger &rhs) const;

    bool operator!=(const BigInteger &rhs) const;
};


#endif //CLION_BIGINTEGER_H
