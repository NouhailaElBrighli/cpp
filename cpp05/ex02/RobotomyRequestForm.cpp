#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("default", 72, 45)
{
	// std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form("default", 72, 45)
{
	// std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	// std::cout << "Copy Form assignment operator called" << std::endl;
	return(*this);
}

RobotomyRequestForm ::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm :: RobotomyRequestForm(std::string target) : Form(target, 72, 45)
{
	// std::cout << "RobotomyRequestForm constructor by parametre called" << std::endl;
}

void RobotomyRequestForm ::execute(Bureaucrat const & executor) const
{
	if (getGrade_execute() < 1)
	{
		GradeTooLowException high;
		throw high;
	}
	if (getGrade_execute() > 150)
	{
		GradeTooLowException low;
		throw low;
	}
	if (getI_sign() == true)
	{
		srand(time(0));
		if (rand() % 2 == 1)
		{
			std::cout << getName() << " has been robotomized successfully 50% of the time." << std::endl;
		}
		else
			std::cout << "the robotomy failed" << std::endl;
	}
}
