#include "bigint.hpp"

#include <cctype>
#include <climits>
#include <sstream>
#include <stdexcept>

std::string bigint::normalize(const std::string &raw)
{
    if (raw.empty())
        throw std::invalid_argument("bigint: empty input");

    std::size_t i = 0;
    while (i < raw.size() && raw[i] == '0')
        ++i;
    if (i == raw.size())
        return "0";

    std::string out;
    out.reserve(raw.size() - i);
    for (; i < raw.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(raw[i])))
            throw std::invalid_argument("bigint: invalid character");
        out.push_back(raw[i]);
    }
    return out;
}

int bigint::compareValues(const std::string &lhs, const std::string &rhs)
{
    if (lhs.size() < rhs.size())
        return -1;
    if (lhs.size() > rhs.size())
        return 1;
    if (lhs < rhs)
        return -1;
    if (lhs > rhs)
        return 1;
    return 0;
}

std::string bigint::addValues(const std::string &lhs, const std::string &rhs)
{
    std::string out;
    int i = static_cast<int>(lhs.size()) - 1;
    int j = static_cast<int>(rhs.size()) - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry != 0)
    {
        int a = (i >= 0) ? (lhs[static_cast<std::size_t>(i)] - '0') : 0;
        int b = (j >= 0) ? (rhs[static_cast<std::size_t>(j)] - '0') : 0;
        int sum = a + b + carry;
        out.push_back(static_cast<char>('0' + (sum % 10)));
        carry = sum / 10;
        --i;
        --j;
    }

    std::string result;
    result.reserve(out.size());
    for (int k = static_cast<int>(out.size()) - 1; k >= 0; --k)
        result.push_back(out[static_cast<std::size_t>(k)]);
    return result;
}

std::string bigint::subValues(const std::string &lhs, const std::string &rhs)
{
    std::string out;
    int i = static_cast<int>(lhs.size()) - 1;
    int j = static_cast<int>(rhs.size()) - 1;
    int borrow = 0;

    while (i >= 0)
    {
        int a = lhs[static_cast<std::size_t>(i)] - '0' - borrow;
        int b = (j >= 0) ? (rhs[static_cast<std::size_t>(j)] - '0') : 0;
        if (a < b)
        {
            a += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        out.push_back(static_cast<char>('0' + (a - b)));
        --i;
        --j;
    }

    while (out.size() > 1 && out[out.size() - 1] == '0')
        out.erase(out.size() - 1);

    std::string result;
    result.reserve(out.size());
    for (int k = static_cast<int>(out.size()) - 1; k >= 0; --k)
        result.push_back(out[static_cast<std::size_t>(k)]);
    return result;
}

int bigint::shiftFromBigint(const bigint &shift)
{
    int out = 0;
    const std::string s = shift.toString();

    for (std::size_t i = 0; i < s.size(); ++i)
    {
        int d = s[i] - '0';
        if (out > (INT_MAX - d) / 10)
            return INT_MAX;
        out = out * 10 + d;
    }
    return out;
}

bigint::bigint() : _value("0") {}

bigint::bigint(int value)
{
    if (value < 0)
        throw std::invalid_argument("bigint: negative input");
    std::ostringstream oss;
    oss << value;
    _value = normalize(oss.str());
}

bigint::bigint(const char *s) : _value("0")
{
    if (!s)
        return;
    _value = normalize(std::string(s));
}

bigint::bigint(const std::string &s) : _value(normalize(s)) {}

bigint::bigint(const bigint &other) : _value(other._value) {}

bigint::~bigint() {}

bigint &bigint::operator=(const bigint &other)
{
    if (this != &other)
        _value = other._value;
    return *this;
}

bool bigint::operator>(const bigint &other) const { return compareValues(_value, other._value) > 0; }
bool bigint::operator<(const bigint &other) const { return compareValues(_value, other._value) < 0; }
bool bigint::operator>=(const bigint &other) const { return compareValues(_value, other._value) >= 0; }
bool bigint::operator<=(const bigint &other) const { return compareValues(_value, other._value) <= 0; }
bool bigint::operator==(const bigint &other) const { return compareValues(_value, other._value) == 0; }
bool bigint::operator!=(const bigint &other) const { return compareValues(_value, other._value) != 0; }

bigint bigint::operator+(const bigint &other) const
{
    return bigint(addValues(_value, other._value));
}

bigint &bigint::operator+=(const bigint &other)
{
    _value = addValues(_value, other._value);
    return *this;
}

bigint bigint::operator-(const bigint &other) const
{
    if (*this < other)
        return bigint(0);
    return bigint(subValues(_value, other._value));
}

bigint &bigint::operator-=(const bigint &other)
{
    if (*this < other)
        _value = "0";
    else
        _value = subValues(_value, other._value);
    return *this;
}

bigint bigint::operator++()
{
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint tmp(*this);
    *this += bigint(1);
    return tmp;
}

bigint bigint::operator<<(int shift) const
{
    if (shift <= 0 || _value == "0")
        return *this;
    std::string out = _value;
    out.append(static_cast<std::size_t>(shift), '0');
    return bigint(out);
}

bigint bigint::operator>>(int shift) const
{
    if (shift <= 0)
        return *this;
    if (static_cast<std::size_t>(shift) >= _value.size())
        return bigint(0);
    return bigint(_value.substr(0, _value.size() - static_cast<std::size_t>(shift)));
}

bigint bigint::operator<<(const bigint &shift) const
{
    return *this << shiftFromBigint(shift);
}

bigint bigint::operator>>(const bigint &shift) const
{
    return *this >> shiftFromBigint(shift);
}

bigint &bigint::operator<<=(int shift)
{
    *this = *this << shift;
    return *this;
}

bigint &bigint::operator>>=(int shift)
{
    *this = *this >> shift;
    return *this;
}

bigint &bigint::operator<<=(const bigint &shift)
{
    *this = *this << shift;
    return *this;
}

bigint &bigint::operator>>=(const bigint &shift)
{
    *this = *this >> shift;
    return *this;
}

std::string bigint::toString() const { return _value; }

std::ostream &operator<<(std::ostream &os, const bigint &value)
{
    os << value.toString();
    return os;
}
