#include <iostream>
#include "Megaphone.hpp"
// class Megaphone
// {

// };

int var = 10;


class share
{
	public :
		share()
		{
			std::cout << "hello" << std::endl;
		}
};

extern void function ()
{
	std::cout << "megaphone file" << std::endl;
}

int main(int ac, char **av)
{
	// (void)ac;
	// (void)av;
	std::string	arg;
	
	if (ac != 1)
	{
		var = 5;
		for (int j = 1; j < ac; j++)
		{
			arg = av[j];//iter = arg.begin() i++
			for (unsigned long i = 0; i < arg.length() ; i++)
				std::cout << char (toupper(arg[i]));
			std:: cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}