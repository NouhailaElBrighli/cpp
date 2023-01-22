#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("default", 25, 5)
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "Copy Form assignment operator called" << std::endl;
	if (this != &rhs)
	{
		
	}
	return(*this);
}

RobotomyRequestForm ::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm :: RobotomyRequestForm(std::string target)
{
	
}

void RobotomyRequestForm ::execute(Bureaucrat const & executor) const
{

}