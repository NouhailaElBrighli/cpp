#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat first("nouha", 16);
		Form fr("khoaula", 15, 5);
		
		std::cout << first;
		std::cout << fr;
		first.signForm(fr);
	}
	catch(std::exception &e)
	{
		std::cout << "Catch exception " << e.what() << std::endl;
	}
}

