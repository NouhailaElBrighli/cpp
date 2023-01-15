#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;//Dfault 
	Fixed const b(10);// int constructor
	Fixed const c(42.42f);// float constructor
	Fixed const d(b);//copy constructor // copy assinemnt 
	a = Fixed(1234.4321f);// float constructor // copy assignment 
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	
	return 0;
}