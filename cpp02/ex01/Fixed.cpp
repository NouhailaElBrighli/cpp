#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs; //you can use this to call the assignement operator
}

Fixed &Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->FixedPointValue = rhs.getRawBits();
	}
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Int constructor called" << std::endl;
	this->FixedPointValue = (num << this->Fractional);
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	this->FixedPointValue = roundf((nb) * (1 << this->Fractional));
}

float Fixed:: toFloat( void ) const
{
	return (((float)this->FixedPointValue) / (1 << this->Fractional));
}

int Fixed::toInt( void ) const
{
	return(this->FixedPointValue >> this->Fractional);
}

std::ostream& operator<<(std::ostream  & COUT, const Fixed& rhs)
{
	COUT << rhs.toFloat();
	return(COUT);
}