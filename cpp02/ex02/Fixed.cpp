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
	this->FixedPointValue = (num << this->Fractional);
}

Fixed::Fixed(const float nb)
{
	this->FixedPointValue = roundf((nb) * (1 << this->Fractional)); //nb * 2 ^8 || *256
}

float Fixed:: toFloat( void ) const
{
	//typecasting
	return ((float)(this->FixedPointValue) / (1 << this->Fractional)); //nb / 2 ^8
}

int Fixed::toInt( void ) const
{
	return (this->FixedPointValue >> this->Fractional);
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
	Fixed a;

	a.setRawBits(this->FixedPointValue + rhs.FixedPointValue);
	return (a);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed a;

	a.setRawBits(this->FixedPointValue - rhs.getRawBits());
	return (a);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed a;

	a.setRawBits((this->FixedPointValue * rhs.getRawBits()) >> this->Fractional);
	return (a);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed a;

	a.setRawBits((this->FixedPointValue / rhs.getRawBits()) << this->Fractional);
	return (a);
}

Fixed Fixed::operator++()
{
	this->FixedPointValue++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp (*this);

	FixedPointValue++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	this->FixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp (*this);

	FixedPointValue--;
	return(tmp);
}

Fixed const & Fixed::min(const Fixed &a,const Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed& Fixed::min(Fixed &a,Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed const &  Fixed::max(const Fixed &a,const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed & Fixed::max(Fixed &a,Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}