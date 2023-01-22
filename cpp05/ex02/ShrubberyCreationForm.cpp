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

ShrubberyCreationForm :: ShrubberyCreationForm(std::string target) : Form(target, 145, 137)
{
	std::ofstream outfile;
	
	outfile.open(target + "_shrubbery");
	//write ascii trees
}


void ShrubberyCreationForm ::execute(Bureaucrat const & executor) const
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
	if (getI_sign())
	{
		std::ofstream outfile;
		outfile.open(getName() + "_shrubbery");

		outfile <<  "   					 	 ,@@@@@@@,\n";
       	outfile <<	"        ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    	outfile <<	"    ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o\n";
   		outfile <<	"   ,%&&&&&%&&%,@@@@@@@/@@@88888888/88\n";
   		outfile <<	"  %&&%&%&/%&&%@@@@@/ /@@@88888888888'\n";
   		outfile <<	"   %&&%/ %&%%&&@@@ V /@@' `8888 `/88'\n";
     	outfile <<  "    `&% ` /%&'    |.|          '|8' \n"; 
		outfile <<  "         |o|       | |          | |  \n"; 
		outfile <<  "         |.|       | |          | |  \n"; 
		outfile <<  "\\/ ._   /_/  ,  //__\\/.    //__ /  \n"; 
		// outfile.close();
	}
}
