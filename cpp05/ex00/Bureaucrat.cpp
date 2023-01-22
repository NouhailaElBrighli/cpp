#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// this->name = rhs.name; // ask for this
		this->grade = rhs.grade;
	}
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	std::cout << "constructor by parametre called" << std::endl;
	if (grade > 150)
	{
		GradeTooLowException low;
		throw low;
	}
	if (grade < 1)
	{
		GradeTooHighException high;
		throw high;
	}
	// this->name = name;
	// this->grade = grade;
}

/********************************************/

std::string Bureaucrat::getName()
{
	return(name);
}

int	Bureaucrat::getGrade()
{
	return(grade);
}

void Bureaucrat::increaseGrade(void)
{
	if (grade - 1 < 1)
	{
		GradeTooHighException high;
		throw high;
	}
	grade--;

}

void Bureaucrat::decreaseGrade(void)
{
	if (grade + 1 > 150)
	{
		GradeTooLowException low;
		throw low;
	}
	grade++;
}

void Bureaucrat::setNameGrade(std::string name, int grade)
{
	// this->name = name;
	this->grade = grade;
}


std::ostream& operator<<(std::ostream  & COUT, Bureaucrat & rhs)
{
	COUT << rhs.getName() <<  " bureaucrat grade "  << rhs.getGrade() << std::endl;
	return(COUT);
}