#include "Phonebook.hpp"

void	print_header()
{
	std::cout << "\033[1;32m";
	PRINT("**************************************************************************************\n");
	PRINT("*                        MY AWESOME PHONEBOOK                                        *\n");
	PRINT("*                                                                                    *\n");
	PRINT("* VALID COMMANDS :                                                                   *\n");
	PRINT("*                                                                                    *\n");
	PRINT("* ADD : to save a new contact                                                        *\n");
	PRINT("*                                                                                    *\n");
	PRINT("* SEARCH: to display a specific contact                                              *\n");
	PRINT("*                                                                                    *\n");
	PRINT("* EXIT : to kill the program                                                         *\n");
	PRINT("*                                                                                    *\n");
	PRINT("**************************************************************************************\n");
	std::cout << "\033[1;00m";
}

void	print_prompt(int type)
{
	if(type == FIRST_NAME)
	{
		PRINT("enter first name : ");
	}
	else if (type == LAST_NAME)
	{
		PRINT("enter second name : ");
	}
	else if (type == NICKNAME)
	{
		PRINT("enter nickname : ");
	}
	else if (type == PHONE_NUMBER)
	{
		PRINT("enter phone number : ");
	}
	else
	{
		PRINT("enter darkest secret : ")
	}
}

bool	check_number(std::string info)
{
	for (int i = 0; i < int (info.length()); i++)
	{
		if (isdigit(info[i]) == 0)
			return (false);
	}
	return(true);
}

void	print_info(std::string info, std::string var)
{
	PRINT(info );
	PRINT(var);
	PRINT("\n");
}

std::string	print_and_edit(std::string info)
{
	if (info.length() > 10)
		return (info.replace(9,info.length(), "."));
	return (info);
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

int main()
{
	PhoneBook Ph;
	std::string cmd;

	print_header();
	while (1)
	{
		PRINT("Enter command : ");
		if (!getline(std::cin, cmd)|| cmd == "EXIT")
		{		 
			break;
		}
		if (cmd == "ADD")
		{
			Ph.add_contact();
		}
		else if (cmd == "SEARCH")
		{
			if(Ph.get_count() != 0)
				Ph.search();
			else
				PRINT("there is no contact yet\n");
		}
		else
			PRINT("invalid command\n");
	}
	return (0);
}