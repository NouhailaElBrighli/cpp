#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat nouha("nouha", 40);

		// ShrubberyCreationForm khaoula("khaoula");
		RobotomyRequestForm kawla("k");
		// PresidentialPardonForm hajar("awlahajar");
		// khaoula.execute(nouha);
		kawla.beSigned(nouha);
		nouha.executeForm(kawla);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}
