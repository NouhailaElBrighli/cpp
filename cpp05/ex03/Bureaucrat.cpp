#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	// std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& rhs)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// this->name = rhs.name; // ask for this
		this->grade = rhs.grade;
	}
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	// std::cout << "Destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	// std::cout << "constructor by parametre called" << std::endl;
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
}

/********************************************/

std::string Bureaucrat::getName()
{
	return (name);
}

int const Bureaucrat::getGrade() const
{
	return (grade);
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

std::ostream& operator<<(std::ostream  & COUT, Bureaucrat & rhs)
{
	COUT << rhs.getName() <<  " bureaucrat grade "  << rhs.getGrade() << std::endl;
	return(COUT);
}

void Bureaucrat::signForm(Form  &fr)
{
	try
	{
		fr.beSigned(*this);
		std::cout << this->name << " signed " << fr.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->name <<  " coudn't sign " << fr.getName() << " because " <<  e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{	
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << this->name <<  " can't execute " << form.getName() << std::endl;
	}
}
