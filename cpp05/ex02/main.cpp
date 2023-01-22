#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat nouha("nouha", 15);

		// ShrubberyCreationForm khaoula("khaoula");
		// RobotomyRequestForm kawla("kawla");
		PresidentialPardonForm hajar("hajar");
		hajar.beSigned(nouha);
		hajar.execute(nouha);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}
