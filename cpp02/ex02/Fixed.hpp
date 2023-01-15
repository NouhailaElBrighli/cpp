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
		bool operator>(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		bool operator==(const Fixed& rhs) const;
		Fixed operator+(const Fixed& rhs) const;// why we can't return it by reference
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed operator++();
		Fixed operator--();
		static Fixed &min();
};

std::ostream& operator<<(std::ostream& COUT,const Fixed & rhs);

#endif
