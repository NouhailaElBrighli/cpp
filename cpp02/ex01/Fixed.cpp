#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	this->FixedPointValue = rhs.getRawBits();
	// *this = obj; you can use this to call the assignement operator
	// this->FixedPointValue = getRawBits();
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
	std::cout << "getRawBits member function called" << std::endl;
	return(this->FixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->FixedPointValue = raw;
}

std::ostream& operator<<(std::ostream& COUT, Fixed& rhs)
{
	COUT << rhs.getRawBits();
	return(COUT);
}





