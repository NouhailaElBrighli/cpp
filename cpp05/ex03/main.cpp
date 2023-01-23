#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;

		Bureaucrat br("nouha", 137);
		Form* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		rrf->beSigned(br);
		br.executeForm(*rrf);
	}
	catch(std::exception &e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
}
