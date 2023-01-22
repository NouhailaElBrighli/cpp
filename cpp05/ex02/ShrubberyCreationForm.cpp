#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "Copy Form assignment operator called" << std::endl;
	if (this != &rhs)
	{
	}
	return(*this);
}

ShrubberyCreationForm ::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm :: ShrubberyCreationForm(std::string target)
{
	std::ofstream outfile;
	
	outfile.open(target + "_shrubbery");
	//write ascii trees
}


void ShrubberyCreationForm ::execute(Bureaucrat const & executor) const
{
	
}
