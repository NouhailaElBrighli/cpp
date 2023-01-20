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

Brain :: Brain(const Brain &obj)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	*this = obj;
}
