//
// Created by stanley on 06.09.18.
//

#include "../inc/BigInteger.h"

bool BigInteger::operator==(const BigInteger &rhs) const
{
    return bit == rhs.bit &&
           positive == rhs.positive &&
           zero == rhs.zero;
}

bool BigInteger::operator<(const BigInteger &rhs) const
{
    if (bit < rhs.bit)
        return true;
    if (rhs.bit < bit)
        return false;
    if (positive < rhs.positive)
        return true;
    if (rhs.positive < positive)
        return false;
    return zero < rhs.zero;
}

bool BigInteger::operator>(const BigInteger &rhs) const
{
    return rhs < *this;
}

bool BigInteger::operator<=(const BigInteger &rhs) const
{
    return !(rhs < *this);
}

bool BigInteger::operator>=(const BigInteger &rhs) const
{
    return !(*this < rhs);
}

bool BigInteger::operator!=(const BigInteger &rhs) const
{
    return !(rhs == *this);
}
