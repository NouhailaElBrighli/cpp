#include <iostream>

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
		// std::string get_first_name();
		// void	set_first_name();
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
		Contact get_contact();
		int get_count();
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

// std::string Contact::get_first_name()
// {
// 	return(this->first_name);
// }

// void	Contact::set_first_name()
// {
// 	std::string s;
// 	getline(std::cin, s);
// 	this->first_name = s;
// }

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
		// print_info("first name == " , first_name);
	}
	else if (type == LAST_NAME)
	{
		last_name = info;
		// print_info("last_name == ", last_name);
	}
	else if (type == NICKNAME)
	{
		nickname = info;
		// print_info("nickname == ", nickname);
	}
	else if (type == PHONE_NUMBER)
	{
		phone_number = info;
		// print_info("phone_number == ", phone_number);
	}
	else
	{
		darkest_secret = info;
		// print_info("darkest_secret == ", darkest_secret);
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



void PhoneBook::add_contact()
{
	int type;
	int n;
	std::string info;

	type = 0;
	n = 0;
	while (type != 5)
	{
		print_prompt(type);
		getline(std::cin, info);
		if (info.length() == 0)
		{
			PRINT("EMPTY CONTACT");
			n = 1;
			break;
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
	PRINT("index |");
	PRINT("firs_name |");
	PRINT("last_name |");
	PRINT("nickname |");
	// PRINT(count);
	// PRINT(index);
	PRINT("\n");	
	for(int i = 0; i < count; i++)
	{
		PRINT(i);
		PRINT(contact[i].get_str(FIRST_NAME));
		PRINT(contact[i].get_str(LAST_NAME));
		PRINT(contact[i].get_str(NICKNAME));
		PRINT("\n");
	}
}

Contact	PhoneBook::get_contact()
{
	return(contact[0]);
}

// void execute_cmd(PhoneBook Ph, std::string cmd)
// {
// 	int i;
// 	i = 0;
// 	// Contact cnt;
// 	if (cmd == "ADD")
// 	{
// 		Ph.add_contact();
// 	}
// 	//printf("address ph == %p", &Ph);
// 	// std::cout <<  Ph.get_contact().get_str(FIRST_NAME) << std::endl;
// 	// cnt = PhoneBook.get_contact();
// 	else if (cmd == "SEARCH")
// 	{
// 		if (Ph.get_count() == 0;
// 		Ph.search();
// 	}
// }


int main()
{
	PhoneBook Ph;
	std::string cmd;

	print_header();
	while (1)
	{
		PRINT("Enter command : ");
		getline(std::cin >> std:ws, cmd);
		if (std::cin.eof() || cmd == "EXIT")
		{		 
			break;
		}
		else if (is_cmd(cmd))
		{
			int i = 0;
			// Contact cnt;
			if (cmd == "ADD")
			{
				Ph.add_contact();
			}
			//printf("address ph == %p", &Ph);
			// std::cout <<  Ph.get_contact().get_str(FIRST_NAME) << std::endl;
			// cnt = PhoneBook.get_contact();
			else if (cmd == "SEARCH")
			{
				if(Ph.get_count() != 0)
					Ph.search();
			}
		}
				// Ph.print_something();
  			// PRINT("INVALID COMMAND\n");
			// if (PhoneBook.contact->first_name == NULL)
			// 	std::cout << "Yes" << std::endl;
			// std::cout << "|" <<PhoneBook.contact->first_name << "|" << std::endl;
	}
	PRINT("FINISH\n");
	return (0);
}