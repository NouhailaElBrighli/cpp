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
	int k;
	count = 0;
	i = 0;
	str = av[1];
	outfile.open(str + ".replace");
	if (outfile.fail())
	{
		std::cout << "fail to open file" << std::endl;
		exit(1);
	}
	while (i != -1)
	{
		k = 0;
		i = s.find(s1);
		if (i == -1)
		{
			if (s.length() != 0)
			{
				while (k != s.length())
				{
					outfile << s[k++];
				}
			}
			break;
		}
		s.erase(i, s1.length());
		s.insert(i, s2);
		while (k < i + s2.length())
			outfile << s[k++];
		s = s.substr(i + s2.length(), s.length());
	}
	outfile.close();
}

int main (int ac, char **av)
{
	if (ac == 4 && *av[1] != '\0' && *av[2] != '\0' && *av[3] != '\0')
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
		infile.close();
	}
	else
		std::cout << "invalid argument" << std::endl;
}