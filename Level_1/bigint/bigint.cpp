#include "bigint.hpp"

bigint::bigint() : _value("0"){}

bigint::bigint(int value){
  _value = toString(value);
}

bigint::bigint(const bigint &other) : _value(other._value){}

bigint &bigint::operator=(const bigint &other){
  if (this != &other)
    _value = other._value;
  return *this;
}

bigint::~bigint(){}


bool  &bigint::operator>(const bigint &value){
  if(_value.size() != value._value.size())
    return (_value.size() > value._value.size());
  return _value > value._value;
}

bool  &bigint::operator<(const bigint &value){
  if(_value.size() != value._value.size())
    return (_value.size() < value._value.size());
  return _value < value._value;
} 

bool  &bigint::operator>(const bigint &value){
  if(_value.size() != value._value.size())
    return (_value.size() >= value._value.size());
  return _value >= value._value;
}

bool  &bigint::operator>(const bigint &value){
  if(_value.size() != value._value.size())
    return (_value.size() <= value._value.size());
  return _value <= value._value;
}

bool  &bigint::operator>(const bigint &value){
  return _value == value._value;
}

bool  &bigint::operator>(const bigint &value){
  return _value != value._value;
} 
