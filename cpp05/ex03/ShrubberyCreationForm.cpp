#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	this->target = "default";
	// std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : Form("ShrubberyCreationForm", 145, 137)
{
	// std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	this->target = rhs.target;
	// std::cout << "Copy Form assignment operator called" << std::endl;
	return(*this);
}

ShrubberyCreationForm ::~ShrubberyCreationForm()
{
	// std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm :: ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	this->target = target;
}

std::string const ShrubberyCreationForm::get_target() const
{
	return(target);
}

void ShrubberyCreationForm ::execute(Bureaucrat const & executor) const
{
	if (getGrade_execute() < executor.getGrade() || getI_sign() == false)
	{
		GradeTooLowException low;
		throw low;
	}
	if (getI_sign() == true)
	{
		std::ofstream outfile;
		outfile.open(get_target() + "_shrubbery");

		outfile <<  "   					 	 ,@@@@@@@,\n";
       	outfile <<	"        ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
    	outfile <<	"    ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o\n";
   		outfile <<	"   ,%&&&&&%&&%,@@@@@@@/@@@88888888/88\n";
   		outfile <<	"  %&&%&%&/%&&%@@@@@/ /@@@88888888888'\n";
   		outfile <<	"   %&&%/ %&%%&&@@@ V /@@' `8888 `/88'\n";
     	outfile <<  "    `&% ` /%&'    |.|          '|8'  \n"; 
		outfile <<  "         |o|      | |           | |  \n"; 
		outfile <<  "         |.|      | |           | |  \n"; 
		outfile <<  "  \\/ ._   /_/  ,  //__\\/.    //_| |\n"; 
		outfile.close();
	}
}

