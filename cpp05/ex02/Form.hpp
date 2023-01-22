#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		const std::string name;
		bool Is_sign;
		const int gradeSign;
		const int grade_execute;
	public :
		Form();
		Form(const Form &obj);
		Form &operator=(const Form &obj);
		virtual ~Form();
		Form(std::string name, int gradeSign, int grade_execute);
		std::string const getName() const;
		int const getgradeSign() const;
		int const getGrade_execute() const;
		bool const getI_sign() const;
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
		void  beSigned(Bureaucrat &br);
		virtual void execute(Bureaucrat const & executor) const = 0;
};



std::ostream& operator<<(std::ostream  & COUT, Form & rhs);



#endif