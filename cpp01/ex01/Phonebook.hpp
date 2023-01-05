#ifndef PHONBOOK_HPP
#define PHONBOOK_HPP

#include "main.hpp"
#include "Contact.hpp"

#define PRINT(x) std::cout << x;

enum info
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};

class PhoneBook
{
	Contact contact [8];
	static int index;
	static int count;
	public :
		void	add_contact();
		void	search();
		int get_count();
};

#endif
