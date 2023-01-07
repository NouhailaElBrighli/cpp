#include <iostream>

int main(int ac, char **av)
{
	if (ac != 1)
	{
		for (int j = 1; j < ac; j++)
		{
			for (unsigned long i = 0; i < strlen(av[j]) ; i++)
				std::cout << char (toupper(av[j][i]));
			std:: cout << " ";
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}