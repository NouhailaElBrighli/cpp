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
		void const beSigned(Bureaucrat const &br)const;
		virtual void execute(Bureaucrat const & executor) const = 0;
		// void initVaribles(std::string name, int gradeSign,int  grade_execute);

};



std::ostream& operator<<(std::ostream  & COUT, Form & rhs);



#endif