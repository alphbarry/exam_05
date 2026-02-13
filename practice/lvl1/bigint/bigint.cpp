#include "bigint.hpp"

#include <stdexcept>
#include <cstdlib>

bigint::bigint() : _value(0) {}

bigint::bigint(int value) : _value(value) {}

bigint::bigint(const char *s){
  if (!s)
    _value = 0;
  else
    _value = std::stoll(std::string(s));
}

bigint::bigint(const std::string &s){
  _value = std::stoll(s);
}

bigint::bigint(const bigint &other) : _value(other._value) {}

bigint::~bigint() {}

bigint& bigint::operator=(const bigint &other){
  if (this != &other)
    _value = other._value;
  return *this;
}

//Increment
bigint bigint::operator++(){
  ++_value;
  return *this;
}

bigint bigint::operator++(int){
  bigint tmp(*this);
  _value++;
  return tmp;
}

//Arithmetic operator
bigint  bigint::operator+(const bigint &other) const{
  return bigint(static_cast<int>(_value + other._value));
}
bigint  bigint::operator-(const bigint &other) const{
  return bigint(static_cast<int>(_value - other._value));
}

bigint  bigint::operator+=(const bigint &other){
  _value += other._value;
  return *this;
}
bigint  bigint::operator-=(const bigint &other){
  _value -= other._value;
  return *this;
}

//shift
bigint  bigint::operator>>(int shift) const{
  return bigint(static_cast<int>(_value >> shift));
}
bigint  bigint::operator<<(int shift) const{
  return bigint(static_cast<int>(_value << shift));
}

bigint  bigint::operator>>=(int shift){
  _value >>= shift;
  return *this;
}
bigint  bigint::operator<<=(int shift){
  _value <<= shift;
  return *this;
}


bool bigint::operator==(const bigint &other) const{
  return _value == other._value;
}
bool bigint::operator!=(const bigint &other) const{
  return _value != other._value;
}
bool bigint::operator>(const bigint &other) const{
  return _value > other._value;
}
bool bigint::operator>=(const bigint &other) const{
  return _value >= other._value;
}
bool bigint::operator<(const bigint &other) const{
  return _value < other._value;
}
bool bigint::operator<=(const bigint &other) const{
  return _value <= other._value;
}

//util
std::string bigint::toString() const {
  return std::to_string(_value);
}

std::ostream &operator<<(std::ostream &os, const bigint &value){
  os << value.toString();
  return os;
}
