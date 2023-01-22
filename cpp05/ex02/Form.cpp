#include "Form.hpp"

Form::Form() : name(), grade_execute(), gradeSign() 
{
	// std::cout << "Form Default constructor called" << std::endl;
	this->Is_sign = false;
}

Form::Form(const Form &rhs) : name(rhs.name), gradeSign(rhs.gradeSign), grade_execute(rhs.grade_execute)
{
	// std::cout << "Form Copy constructor called" << std::endl;
	*this = rhs;
}

Form &Form::operator=(const Form& rhs)
{
	// std::cout << "Copy Form assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->Is_sign = false;
	}
	return(*this);
}

Form::~Form()
{
	// std::cout << "Form Destructor called" << std::endl;
}

Form::Form(std::string name, int gradeSign, int grade_execute) : name(name), gradeSign(gradeSign), grade_execute(grade_execute)
{
	// std::cout << "Form constructor by parametre called" << std::endl;
	this->Is_sign = false;//test it
	if (this->gradeSign < 1 || this->grade_execute < 1)
	{
		GradeTooHighException high;
		throw high;
	}
	if (this->gradeSign > 150 || this->gradeSign >  150)
	{
		GradeTooLowException low;
		throw low;
	}
}

std::string const Form:: getName() const
{
	return (name);
}

int const  Form::getgradeSign() const
{
	return (gradeSign);
}

int const Form::getGrade_execute() const
{
	return (grade_execute);
}

std::ostream& operator<<(std::ostream  & COUT, Form & rhs)
{
	COUT << "name : " << rhs.getName() << " grade required to sign : " << rhs.getgradeSign() << " grade required to execute : " << rhs.getGrade_execute() << std::endl; 
	return(COUT);
}

bool const Form::getI_sign() const
{
	return(Is_sign);
}

void Form::beSigned(Bureaucrat  &br)
{
	if (this->gradeSign >= br.getGrade())
		this->Is_sign = true;
	else
	{
		GradeTooLowException low;
		throw low;
	}
}
