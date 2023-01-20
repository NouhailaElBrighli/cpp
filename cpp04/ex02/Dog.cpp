#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
	this->br = new Brain();
}

Dog::~Dog()
{
	delete this->br;
	std::cout << "Dog Desttructor" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignement operator overloading" << std::endl;
	if (this != &obj)
	{
		if (this->br != NULL)
			delete this->br;
		this->br = new Brain();
		for(int i = 0; i < 100; i++)
			this->br->ideas[i] = obj.br->ideas[i];
		this->type = obj.type;
	}
	return(*this);
}

Dog :: Dog(const Dog &obj)
{
	std::cout << "Dog Copy Constructor" << std::endl;
	this->br = NULL;
	*this = obj;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}
