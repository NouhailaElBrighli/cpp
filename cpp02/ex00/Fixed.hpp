#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	int FixedPointValue;
	int static const Fractional = 8;
	public :
		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};




#endif