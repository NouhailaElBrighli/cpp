#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form( "Presidential Pardon" , 25, 5)
{
	this->target = "default";
	// std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : Form( "Presidential Pardon" , 25, 5)
{
	// std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = rhs;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	// std::cout << "Copy Form assignment operator called" << std::endl;
	this->target = rhs.target;
	return(*this);
}

PresidentialPardonForm :: PresidentialPardonForm(std::string target) :  Form("Presidential Pardon" , 25, 5)
{
	this->target = target;
	// std::cout << "PresidentialPardonForm constructor by parametre called" << std::endl;
}
PresidentialPardonForm :: ~PresidentialPardonForm()
{
	// std::cout << "PresidentialPardonForm constructor by parametre called" << std::endl;
}

std::string const PresidentialPardonForm::get_target() const
{
	return(target);
}


void PresidentialPardonForm :: execute(Bureaucrat const & executor) const
{
	if (getGrade_execute() < executor.getGrade() || getI_sign() == false)
	{
		GradeTooLowException low;
		throw low;
	}
	if (getI_sign() == true)
		std::cout << get_target() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
