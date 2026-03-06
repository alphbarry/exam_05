#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
    std::string _value;

    static std::string normalize(const std::string &raw);
    static int compareValues(const std::string &lhs, const std::string &rhs);
    static std::string addValues(const std::string &lhs, const std::string &rhs);
    static std::string subValues(const std::string &lhs, const std::string &rhs);
    static int shiftFromBigint(const bigint &shift);

public:
    bigint();
    bigint(int value);
    bigint(const char* s);
    bigint(const std::string &s);
    bigint(const bigint &other);
    ~bigint();

    bigint &operator=(const bigint &other);

    bool operator>(const bigint &other) const;
    bool operator<(const bigint &other) const;
    bool operator>=(const bigint &other) const;
    bool operator<=(const bigint &other) const;
    bool operator==(const bigint &other) const;
    bool operator!=(const bigint &other) const;

    bigint operator+(const bigint &other) const;
    bigint &operator+=(const bigint &other);
    bigint operator-(const bigint &other) const;
    bigint &operator-=(const bigint &other);

    bigint operator++();
    bigint operator++(int);

    bigint operator<<(int shift) const;
    bigint operator>>(int shift) const;
    bigint operator<<(const bigint &shift) const;
    bigint operator>>(const bigint &shift) const;
    bigint &operator<<=(int shift);
    bigint &operator>>=(int shift);
    bigint &operator<<=(const bigint &shift);
    bigint &operator>>=(const bigint &shift);

    std::string toString() const;
};

std::ostream &operator<<(std::ostream &os, const bigint &value);

#endif // BIGINT_HPP
