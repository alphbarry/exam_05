#include "vect2.hpp"

vect2::vect2()
{
	this->x = 0;
	this->y = 0;
}

vect2::vect2(int n1, int n2)
{
	this->x = n1;
	this->y = n2;
}

int vect2::operator[](int i) const
{
	if(i == 0)
		return(this->x);
	return(this->y);
}

int& vect2::operator[](int i)
{
	if(i == 0)
		return(this->x);
	return(this->y);
}

vect2 vect2::operator-() const
{
	vect2 temp = *this;
	temp[0] = -temp[0];
	temp[1] = -temp[1];
	return(temp);
}

vect2 vect2::operator-(const vect2& obj) const
{
	vect2 temp = *this;
	temp.x -= obj.x;
	temp.y -= obj.y;
	return(temp);
}

vect2 vect2::operator*(int n) const
{
	vect2 temp;

	temp.x = this->x * n;
	temp.y = this->y * n;
	return(temp);
}

vect2& vect2::operator*=(int n)
{
	this->x *= n;
	this->y *= n;
	return(*this);
}

vect2& vect2::operator+=(const vect2& obj)
{
	this->x += obj.x;
	this->y += obj.y;
	return(*this);
}

vect2& vect2::operator-=(const vect2& obj)
{
	this->x -= obj.x;
	this->y -= obj.y;
	return(*this);
}

vect2& vect2::operator*=(const vect2& obj)
{
	this->x *= obj.x;
	this->y *= obj.y;
	return(*this);
}

vect2 vect2::operator+(const vect2& obj) const
{
	vect2 temp = *this;

	temp.x += obj.x;
	temp.y += obj.y;
	return(temp);
}

vect2 vect2::operator*(const vect2& obj) const
{
	vect2 temp = *this;
	temp.x *= obj.x;
	temp.y *= obj.y;
	return(temp);
}

vect2& vect2::operator++()
{
	this->x += 1;
	this->y += 1;
	return(*this);
}

vect2 vect2::operator++(int)
{
	vect2 temp = *this;

	++(*this);
	return(temp);
}

vect2& vect2::operator--()
{
	this->x -= 1;
	this->y -= 1;
	return(*this);
}

vect2 vect2::operator--(int)
{
	vect2 temp = *this;

	--(*this);
	return(temp);
}

bool vect2::operator==(const vect2& obj) const
{
	if((this->x == obj.x) && (this->y == obj.y))
		return(true);
	return(false);
}

bool vect2::operator!=(const vect2& obj) const
{
	return(!(obj == *this));
}

std::ostream& operator<<(std::ostream& os,const vect2& obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return(os);
}


vect2 operator*(int n, const vect2& obj)
{
	vect2 temp(obj);
	temp *= n;
	return(temp);
}
