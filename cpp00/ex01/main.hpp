#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <stdlib.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

enum info
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET

};

std::string	print_and_edit(std::string info);
void		print_info(std::string info, std::string var);
void		print_prompt(int type);
bool		check_number(std::string info);
void		print_contact_informations(Contact contact);
bool 		check_index(std::string index, int check, int count);
bool		check_spaces(std::string info);
std::string	print_and_edit(std::string info);



#endif