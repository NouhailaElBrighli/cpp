#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	std::string target;
	public :
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		std::string const get_target() const;
		void execute(Bureaucrat const & executor) const;
};

#endif