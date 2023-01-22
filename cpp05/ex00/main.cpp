#include "Bureaucrat.hpp"

int main()
{
	try 
	{
		Bureaucrat first("nouha", 151);
		
		first.decreaseGrade();
		std::cout << first;
		first.increaseGrade();
		std::cout << first;
	}
	catch(std::exception &e)
	{
		std::cout << "Catch exception " << e.what() << std::endl;
	}
}

