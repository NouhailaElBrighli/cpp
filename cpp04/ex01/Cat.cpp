#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	this->type = "Cat";
	this->br = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat Desttructor" << std::endl;
	delete this->br;
}

Cat& Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignement operator overloading" << std::endl;
	if (this != &obj)
	{
		if (this->br != NULL)
			delete br;
		this->br = new Brain();
		for (int i = 0; i < 100; i++)
			this->br->setIdeas(obj.br->getIdeas(i), i);
		this->type = obj.type;
	}
	return(*this);
}

Cat :: Cat(const Cat &obj)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	this->br = NULL;
	*this = obj;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}