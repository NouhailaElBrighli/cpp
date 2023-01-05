#include "Phonebook.hpp"
#include "main.hpp"
#include "Contact.hpp"



int PhoneBook::index;
int PhoneBook::count;

int PhoneBook::get_count()
{
	return (count);
}

void PhoneBook::add_contact()
{
	int	type;
	std::string	info;

	type = 0;
	while (type != 5)
	{
		print_prompt(type);
		if (!getline(std::cin, info))
			exit(0);
		if (type == PHONE_NUMBER && !check_number(info))
		{
			PRINT("invalid phone number\n");
			continue;
		}
		if (info.length() == 0 || check_spaces(info))
		{
			PRINT("EMPTY : please enter a valid information\n");
			continue;
		}
		contact[index].set_contact(info, type);
		type++;
	}
	if (index == 7)
		index = 0;
	else
		index++;
	if (count <= 7)
		count++;
	PRINT("\n");
}

void PhoneBook::search()
{
	std::string index;
	int check;

	check = 0;
	std::cout << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname" << "|";
	PRINT("\n");
	for(int i = 0; i < count; i++)
	{
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << print_and_edit(contact[i].get_str(FIRST_NAME)) << "|";
		std::cout << std::right << std::setw(10) << print_and_edit(contact[i].get_str(LAST_NAME)) << "|";
		std::cout << std::right << std::setw(10) << print_and_edit(contact[i].get_str(NICKNAME)) << "|";
		PRINT("\n");
	}
	while (!check_index(index, check, count))
	{
		check = 1;
		PRINT("WHICH INDEX : ");
		if (!getline(std::cin, index))
			exit(EXIT_SUCCESS);
	}
	print_contact_informations(contact[int(index[0] - 48)]);
}

