#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
    long long _value;

public:
    // Constructores
    bigint();
    bigint(int value);
    bigint(const char* s);
    bigint(const std::string &s);
    bigint(const bigint &other);
    ~bigint();

    bigint &operator=(const bigint &other);

    // Comparisons
    bool operator>(const bigint &other) const;
    bool operator<(const bigint &other) const;
    bool operator>=(const bigint &other) const;
    bool operator<=(const bigint &other) const;
    bool operator==(const bigint &other) const;
    bool operator!=(const bigint &other) const;

    // Arithmetic
    bigint operator+(const bigint &other) const;
    bigint &operator+=(const bigint &other);
    bigint operator-(const bigint &other) const;
    bigint &operator-=(const bigint &other);

    // Increment
    bigint operator++();    // prefix
    bigint operator++(int); // postfix

    // Shifts (logical arithmetic using powers of two)
    bigint operator<<(int shift) const;
    bigint operator>>(int shift) const;
    bigint &operator<<=(int shift);
    bigint &operator>>=(int shift);

    std::string toString() const;
};

std::ostream &operator<<(std::ostream &os, const bigint &value);

#endif // BIGINT_HPP

