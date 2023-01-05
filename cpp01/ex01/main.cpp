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

std::string print_and_edit(std::string info)
{
	if (info.length() > 10)
		return (info.replace(9,info.length(), "."));
	return (info);
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