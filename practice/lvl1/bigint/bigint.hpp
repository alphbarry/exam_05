#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint {
private:
  long long _value;

public:
  bigint();
  bigint(int value);
  bigint(const char *s);
  bigint(const std::string &s);
  bigint(const bigint &other);
  ~bigint();

  bigint &operator=(const bigint &other);

  //comparaison
  bool operator==(const bigint &other) const;
  bool operator!=(const bigint &other) const;
  bool operator>(const bigint &other) const;
  bool operator>=(const bigint &other) const;
  bool operator<(const bigint &other) const;
  bool operator<=(const bigint &other) const;

  //arithmetic operators
  bigint operator+(const bigint &other) const;
  bigint &operator+=(const bigint &other);
  bigint operator-(const bigint &other) const;
  bigint &operator-=(const bigint &other);

  //increment
  bigint operator++();
  bigint operator++(int);

  //shifts
  bigint operator>>(int shift) const;
  bigint operator<<(int shift) const;
  bigint &operator>>=(int shift);
  bigint &operator<<=(int shift);

  //util
  std::string toString() const;
};

std::ostream &operator<<(std::ostream &os, const bigint &value);
#endif 
