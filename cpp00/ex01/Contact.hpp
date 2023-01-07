#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "main.hpp"
#include "Phonebook.hpp"

class Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	
	public :
		std::string get_str(int type);
		void	set_contact(std::string info, int type);
};


#endif
