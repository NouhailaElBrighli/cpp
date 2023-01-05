#include "main.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"

std::string Contact::get_str(int type)
{
	
	if(type == FIRST_NAME)
	{
		return(first_name);
	}
	else if (type == LAST_NAME)
	{
		return(last_name);
	}
	else if (type == NICKNAME)
	{
		return(nickname);
	}
	else if (type == PHONE_NUMBER)
	{
		return(phone_number);
	}
	return(darkest_secret);
}

void	Contact::set_contact(std::string info, int type)
{
	if(type == FIRST_NAME)
	{
		first_name = info;
	}
	else if (type == LAST_NAME)
	{
		last_name = info;
	}
	else if (type == NICKNAME)
	{
		nickname = info;
	}
	else if (type == PHONE_NUMBER)
	{
		phone_number = info;
	}
	else
	{
		darkest_secret = info;
	}
}