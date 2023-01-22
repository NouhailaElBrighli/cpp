#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat
{
	private :
		const std::string name;// const ??
		int grade;
	public :
		Bureaucrat();
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		void setNameGrade(std::string name, int grade);
		std::string getName();
		int getGrade();
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
};

std::ostream& operator<<(std::ostream  & COUT, Bureaucrat & rhs);

#endif