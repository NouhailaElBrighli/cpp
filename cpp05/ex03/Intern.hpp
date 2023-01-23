#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"

class Form;

class Intern
{
	public :
		Intern();
		Intern(const Intern &obj);
		Intern &operator=(const Intern &obj);
		~Intern();
		Form *makeForm(std::string name, std::string target);
		class NoParametre : public std::exception
		{
			virtual const char *what() const throw()
			{
				return("name passed as paramtre doesn't match");
			}
		};
};

#endif