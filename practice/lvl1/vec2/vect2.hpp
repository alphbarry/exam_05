#ifndef VECT2_HPP
#define VECT2_HPP


#include <iostream>

class vect2{
	private:
		int x;
		int y;

	public:
		vect2();
		vect2(int n1, int n2);

		int operator[](int i) const;
		int& operator[](int i);

		vect2& operator*=(int n);

		vect2 operator-() const;

		vect2& operator+=(const vect2 &obj);
		vect2& operator-=(const vect2 &obj);
		vect2& operator*=(const vect2 &obj);

		vect2 operator+(const vect2 &obj) const;
		vect2 operator-(const vect2 &obj) const;
		vect2 operator*(const vect2 &obj) const;
		vect2 operator*(int n) const;

		//increment and decrement operators
		vect2& operator++();
		vect2 operator++(int);
		vect2& operator--();
		vect2 operator--(int);

		//comparison operators
		bool operator==(const vect2 &obj) const;
		bool operator!=(const vect2 &obj) const;
};

vect2 operator*(int n, const vect2 &obj);
std::ostream& operator<<(std::ostream& os, const vect2 &obj);

#endif // VECT2_HPP
