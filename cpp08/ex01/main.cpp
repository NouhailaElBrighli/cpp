#include "Span.hpp"
// one number throw wxception
int main()
{
	Span sp(5);
	try
	{
		std::vector<int> vec;
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(3);
		sp.addNumber(-5);
		vec.push_back(2);
		// sp.addNumber(-5);

		std::vector<int>::iterator it = vec.begin();
		std::vector<int>::iterator it1 = vec.end();
		sp.AddRange(it, it1);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try 
	{
		sp.addNumber(-13);
		std::cout << sp.shortestSpan() << std::endl;
		sp.addNumber(1);
		sp.addNumber(22);
		// sp.addNumber(15);
		// sp.addNumber(15);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	// sp.fillSpan();
}