#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form( "default" , 25, 5)
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form( "default" , 25, 5)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "Copy Form assignment operator called" << std::endl;
	return(*this);
}

PresidentialPardonForm :: PresidentialPardonForm(std::string target) :  Form(target , 25, 5)
{
	std::cout << "PresidentialPardonForm constructor by parametre called" << std::endl;
}
PresidentialPardonForm :: ~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm constructor by parametre called" << std::endl;
}


void PresidentialPardonForm :: execute(Bureaucrat const & executor) const
{
	executor.signForm(*this);
}