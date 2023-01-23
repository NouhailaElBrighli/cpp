#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	// std::cout << "Default constructor called" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Intern &Intern::operator=(const Intern& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	return(*this);
}

Intern::~Intern()
{
	// std::cout << "Destructor called" << std::endl;
}

Form *Intern:: makeForm(std::string name, std::string target)
{
	int i = 0;
	Form *form;
	std::string tab[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	while (i < 3)
	{
		if (tab[i] == name)
			break;
		i++;
	}
	switch(i)
	{
		case 0:
		{
			form = new ShrubberyCreationForm(target);
			break;
		}
		case 1:
		{
			form = new RobotomyRequestForm(target);
			// std::cout << "here" << std::endl;
			break;
		}
		case 2:
		{
			form = new PresidentialPardonForm(target);
			break;
		}
		default :
		{
			NoParametre param;
			throw param;
		}
	}
	std::cout << "intern create "  << name << std::endl;
	return (form);
}
