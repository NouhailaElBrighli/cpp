#include <fstream>
#include <iostream> 
#include <string>

void	AddToFile(std::string& s, char **av)
{
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s.find(s1) == -1)
	{
		//earse
	}
}

int main (int ac, char **av)
{
	if (ac == 4)
	{
		std::ifstream infile;
		std::ofstream outfile;
		std::string str;
		std::string s;

		str = av[1];
		infile.open(av[1]);
		outfile.open(str + ".replace");
		if (infile.fail() || outfile.fail())
		{
			std::cout << "fail to open the file" << std::endl;
			return (1);
		}
		getline(infile, s, '\0');
		// outfile << s;
		AddToFile(s, av);
		// i = s.find(av[2]);
		std::cout << s << std::endl;
	}
}