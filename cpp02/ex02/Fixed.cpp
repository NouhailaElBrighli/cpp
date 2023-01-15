#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
	*this = rhs;
}

Fixed &Fixed::operator=(const Fixed& rhs)
{
	if (this != &rhs)
	{
		this->FixedPointValue = rhs.getRawBits();
	}
	return(*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return(this->FixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->FixedPointValue = raw;
}

Fixed::Fixed(const int num)
{
	this->FixedPointValue = (num << 8);
}

Fixed::Fixed(const float nb)
{
	this->FixedPointValue = roundf((nb) * (1 << 8)); //nb * 2 ^8 || *256
}

float Fixed:: toFloat( void ) const
{
	//typecasting
	return ((float)(this->FixedPointValue) / (1 << 8)); //nb / 2 ^8
}

int Fixed::toInt( void ) const
{
	return(this->FixedPointValue >> 8);
}

std::ostream& operator<<(std::ostream  & COUT, const Fixed& rhs)
{
	COUT << rhs.toFloat();
	return(COUT);
}

bool Fixed::operator>(const Fixed &rhs) const
{
	if (this->FixedPointValue > rhs.FixedPointValue)
		return(true);
	return(false);
}

bool Fixed::operator<(const Fixed &rhs) const
{
	if (this->FixedPointValue < rhs.FixedPointValue)
		return(true);
	return(false);
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	if (this->FixedPointValue >= rhs.FixedPointValue)
		return(true);
	return(false);
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	if (this->FixedPointValue <= rhs.FixedPointValue)
		return(true);
	return(false);
}

bool Fixed::operator==(const Fixed &rhs) const
{
	if (this->FixedPointValue == rhs.FixedPointValue)
		return(true);
	return(false);
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	if (this->FixedPointValue != rhs.FixedPointValue)
		return(true);
	return(false);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	return(Fixed((this->FixedPointValue + rhs.FixedPointValue)));// << 16 should >> 8
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	return(Fixed((this->FixedPointValue - rhs.FixedPointValue)));// << 16 should >> 8
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	return(Fixed((this->FixedPointValue * rhs.getRawBits())));
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	return(Fixed((this->FixedPointValue / rhs.getRawBits())));
}

Fixed Fixed::operator++()
{
	this->FixedPointValue++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp (*this);// 10 + 1 ==> 11 { 1010.0000001}

	FixedPointValue++;
	return(tmp);
}

Fixed Fixed::operator--()
{
	this->FixedPointValue--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp (*this);// 10 + 1 ==> 10 { 1010.00000001 }

	FixedPointValue--;
	return(tmp);
}

