#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <stdlib.h>
#include "Phonebook.hpp"
#include "Contact.hpp"

std::string	print_and_edit(std::string info);
void		print_info(std::string info, std::string var);
void		print_prompt(int type);
bool		check_number(std::string info);
void		print_contact_informations(Contact contact);

#endif