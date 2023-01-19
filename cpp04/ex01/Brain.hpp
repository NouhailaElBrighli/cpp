#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <string>


class Brain
{
	std::string ideas[100];
	public :
		Brain();
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		~Brain();
};

#endif