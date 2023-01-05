#include "Phonebook.hpp"
#include "main.hpp"
#include "Contact.hpp"

int PhoneBook::index;
int PhoneBook::count;

int PhoneBook::get_count()
{
	return (count);
}


bool	check_spaces(std::string info)
{
	for (int i = 0; i < info.length(); i++)
	{
		if (isspace(info[i]))
			return (true);
	}
	return (false);
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
		if (info.length() == 0)
		{
			PRINT("EMPTY : please enter a valid information\n");
			continue;
		}
		check_spaces(info);
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

bool check_index(std::string index, int check, int count)
{
	int idx;

	if (check == 0)
		return(false);
	for (unsigned long i = 0; i < index.length(); i++)
	{
		if (!isdigit(index[i]))
		{
			PRINT("WRONG INDEX : the index should be positive integer\n");
			return (false);
		}
	}
	idx = index[0] - 48;
	if (idx > count - 1 || index.length() != 1)
	{
		PRINT("OUT OF THE RANGE : please enter index from the table\n");
		return(false);
	}
	return (true);
}

void	print_contact_informations(Contact contact)
{
	std::cout << "fisrt name = " << contact.get_str(FIRST_NAME) << std::endl;
	std::cout << "last name = " << contact.get_str(LAST_NAME) << std::endl;
	std::cout << "nickname = " << contact.get_str(NICKNAME) << std::endl;
	std::cout << "phone number = " << contact.get_str(PHONE_NUMBER) << std::endl;
	std::cout << "darkest secret = " << contact.get_str(DARKEST_SECRET) << std::endl;
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

