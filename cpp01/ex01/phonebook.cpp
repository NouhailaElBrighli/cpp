#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#define PRINT(x) std::cout << x;

enum info
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET
};

/**********************CLASSES************************/
class Contact
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	public :
		Contact();
		~Contact();
		
		std::string get_str(int type);
		void	set_contact(std::string info, int type);
};

class PhoneBook
{
	Contact contact [8];
	static int index;
	static int count;
	public :
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	search();
		void print_something();
		int get_count();

		std::string edit_info(std::string info);
};

/*****************************************************/

int PhoneBook::index;
int PhoneBook::count;

/*********************CONSTRUCTORS && DESTRUCTORS********************************/

Contact::Contact()
{
	PRINT("Contact Contructor\n");
}

Contact::~Contact()
{
	PRINT("Contact Destructor\n");
}

PhoneBook::PhoneBook()
{
	PRINT("Phonbook Constructor\n");
}

PhoneBook::~PhoneBook()
{
	PRINT("Phonbook Destructor\n");
}

/*******************************************************************************/

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
	return(nickname);
}

void	PhoneBook:: print_something()
{
	PRINT("SOMETHING\n");
}

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

bool	is_cmd(std::string cmd)
{
	if (cmd == "SEARCH" || cmd == "ADD")
		return(true);
	return(false);
}

int PhoneBook::get_count()
{
	return(count);
}

void	print_info(std::string info, std::string var)
{
	PRINT(info );
	PRINT(var);
	PRINT("  \n");
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

void	print_prompt(int type)
{
	if(type == FIRST_NAME)
	{
		PRINT("ENTER FIRST NAME : ");
	}
	else if (type == LAST_NAME)
	{
		PRINT("ENTER LAST NAME : ");
	}
	else if (type == NICKNAME)
	{
		PRINT("ENTER NICKNAME : ");
	}
	else if (type == PHONE_NUMBER)
	{
		PRINT("ENTER PHONE NUMBER : ");
	}
	else
	{
		PRINT("ENTER DARKEST SCRET: ")
	}
}

std::string	PhoneBook::edit_info(std::string info)
{
	return(info.replace(9,info.length(), "."));
}

bool	check_number(std::string info)
{
	for (int i = 0; i < int (info.length()); i++)
	{
		if (isdigit(info[i]) == 0)
			return (false);
	}
	// if (info.length() != 10)
	// 	return (false);
	return(true);
}

void PhoneBook::add_contact()
{
	int	type;
	int	n;
	std::string	info;

	type = 0;
	n = 0;
	while (type != 5)
	{
		print_prompt(type);
		getline(std::cin, info);
		if (type == PHONE_NUMBER && !check_number(info))
		{
			PRINT("INVALID PHONE NUMBER\n");
			continue;
		}
		if (info.length() > 10)
			info = edit_info(info);
		if (info.length() == 0)
		{
			PRINT("EMPTY ");
			n = 1;
		}
		contact[index].set_contact(info, type);
		type++;
	}
	if (n == 0)
	{
		if (index == 7)
			index = 0;
		else
			index++;
		if (count < 7)
			count++;
	}
	PRINT("\n");
}


void PhoneBook::search()
{
	// std::string index;

	std::cout << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST NAME" << "|";
	std::cout << std::setw(10) << "LAST NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|";
	PRINT("\n");
	for(int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contact[i].get_str(FIRST_NAME) << "|";
		std::cout << std::setw(10) << contact[i].get_str(LAST_NAME) << "|";
		std::cout << std::setw(10) << contact[i].get_str(NICKNAME) << "|";
		PRINT("\n");
	}
	// if (!getline(std::cin, index))
	// 	exit(EXIT_SUCCESS);
	// getline(std::cin, index);
	// // if (index.length())
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
		}
		else
			PRINT("INVALID COMMAND\n");
	}
	PRINT("FINISH\n");
	return (0);
}