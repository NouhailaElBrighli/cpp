#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Desttructor" << std::endl;
}

Brain& Brain::operator=(const Brain &obj)
{
	std::cout << "Brain assignement operator overloading" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = obj.ideas[i];
	}
	return(*this);
}

void Brain::setIdeas(std::string ideas, int index)
{
	this->ideas[index] = ideas;
}

std::string Brain::getIdeas(int index)
{
	return(this->ideas[index]);
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	*this = obj;
}
