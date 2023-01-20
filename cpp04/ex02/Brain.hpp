#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <string>


class Brain
{
	// private:
	public :
		std::string ideas[100]; // ask for this 
		Brain();
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		~Brain();
};

#endif