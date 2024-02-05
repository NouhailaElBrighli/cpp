#include "PmergeMe.hpp"

int	ParseArg(std::string &s)
{
	int num;
	std::stringstream ss(s);

	ss >> num;
	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Invalid input");
	if (num < 0)
		throw std::runtime_error("the number should be positive");
	return (num);
}

int main(int ac, char **av)
{
	try
	{
		int	num;
		PmergeMe nums;
		if (ac < 3)
			throw std::runtime_error("Error : invalid argument");
		for(int i = 1; i < ac; i++)
		{
			std::string s(av[i]);
			num = ParseArg(s);
			nums.PushNumber(num);
		}
		nums.Sort();
		std::cout << "Time to process a range of " << nums.GetSize() << " elements with std::vector " << nums.GetTimeVec() << " us" <<std::endl;
		std::cout << "Time to process a range of " << nums.GetSize() << " elements with std::deque " << nums.GetTimeDeq() << " us" <<std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}