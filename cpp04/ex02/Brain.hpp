#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public :
		void setIdeas(std::string indeas, int index);
		std::string getIdeas(int index);
		Brain();
		Brain(const Brain &obj);
		Brain &operator=(const Brain &obj);
		~Brain();
};

#endif