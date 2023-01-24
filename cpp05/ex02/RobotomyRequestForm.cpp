#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy", 72, 45)
{
	this->target = "default";
	// std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : Form("Robotomy", 72, 45)
{
	// std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	// std::cout << "Copy Form assignment operator called" << std::endl;
	this->target = rhs.target;
	return(*this);
}

RobotomyRequestForm ::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm :: RobotomyRequestForm(std::string target) : Form("Robotomy", 72, 45)
{
	this->target = target;
	// std::cout << "RobotomyRequestForm constructor by parametre called" << std::endl;
}

std::string const RobotomyRequestForm ::get_target() const
{
	return(target);
}

void RobotomyRequestForm ::execute(Bureaucrat const & executor) const
{
	if (getGrade_execute() < executor.getGrade() || getI_sign() == false)
	{
		GradeTooLowException low;
		throw low;
	}
	if (getI_sign() == true)
	{
		srand(time(0));
		if (rand() % 2 == 1)
		{
			std::cout << get_target() << " has been robotomized successfully " << std::endl;
		}
		else
			std::cout << "the robotomy failed" << std::endl;
	}
}
