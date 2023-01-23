#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;


class Bureaucrat
{
	private :
		const std::string name;
		int grade;
	public :
		Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		std::string getName();
		int const getGrade() const;
		void increaseGrade(void);
		void decreaseGrade(void);
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return("Grade Too High Exception");		
			} 
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return("Grade Too Low Exception");
			}
		};
		void signForm(Form  &fr);
		void executeForm(Form const & form);
};

std::ostream& operator<<(std::ostream  & COUT, Bureaucrat & rhs);
#endif
