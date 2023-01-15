#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	int FixedPointValue;
	int static const Fractional = 8;
	public :
		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		Fixed(const int num);
		Fixed(const float nb);
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& COUT,const Fixed & rhs);
// std::ostream& operator<<(std::ostream& COUT,Fixed& rhs(const int num));



#endif