#include <fstream>
#include <iostream> 
#include <string> 


std::string addString(std::string s1, std::string s2, std::string &newSring, int i)
{
	
}

int main (int ac, char **av)
{
	if (ac == 4)
	{
		std::ifstream infile;
		std::ofstream outfile;
		std::string str;
		std::string s;
		std::string s1;
		std::string s2;
		std::string newString;

		str = av[1];
		s1 = av[2];
		s2 = av[3];
		infile.open(av[1]);
		outfile.open(str + ".replace");
		if (infile.fail() || outfile.fail())
		{
			std::cout << "fail to open the file" << std::endl;
			return (1);
		}
		getline(infile, s, '\0');
		// outfile << s;
		if (s.find(s1) != std::string::npos)
		{
			int i = s.find(s1);
			addString(s1, s2, newString, i); 
			std::cout << s.substr(i, s2.length()) << std::endl;

		}
		// i = s.find(av[2]);
		std::cout << s << std::endl;
	}
}