#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat nouha("nouha", 6);

		ShrubberyCreationForm khaoula("khaoula");
		khaoula.beSigned(nouha);
		// khadija.beSigned(nouha);
		// hajar.beSigned(nouha);
		nouha.executeForm(khaoula);
		// nouha.executeForm(khadija);
		// nouha.executeForm(hajar);

	}
	catch(std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}
