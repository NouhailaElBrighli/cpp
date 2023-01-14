#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a; // Default constructor
	Fixed b(a); // Copy constructor ==> getRawBits
	Fixed c; // Default constructor
	c = b; //assignement operator ==> getRawBits
	std::cout << a << std::endl;
	// std::cout << a.getRawBits() << std::endl; //getrawbits
	// std::cout << b.getRawBits() << std::endl;//getrawbits 
	// std::cout << c.getRawBits() << std::endl;//getrabits
	//destructor called
	//destructor called
	//destructor called
	return 0;
}