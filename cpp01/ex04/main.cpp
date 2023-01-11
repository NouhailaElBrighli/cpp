#include <fstream>
#include <iostream> 
#include <string>

void	AddToFile(std::string& s, char **av)
{
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string str;
	std::ofstream outfile;
	int i;
	int count;

	count = 0;
	i = 0;
	str = av[1];
	outfile.open(str + ".replace");
	if (outfile.fail())
	{
		std::cout << "fail to open file" << std::endl;
		exit(1);
	}
	while (i != -1 && count < s.length())
	{

		i = s.find(s1);
		if (i == -1)
			break;
		s.erase(i, s1.length());
		s.insert(i, s2);
		count = i + s2.length();
	}
	outfile << s;
}

int main (int ac, char **av)
{
	if (ac == 4)
	{
		std::ifstream infile;
		std::string s;

		infile.open(av[1]);
		if (infile.fail())
		{
			std::cout << "fail to open the file" << std::endl;
			return (1);
		}
		getline(infile, s, '\0');
		AddToFile(s, av);
	}
}