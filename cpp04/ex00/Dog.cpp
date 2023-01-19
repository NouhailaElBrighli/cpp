#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
}
Dog::~Dog()
{
	std::cout << "Dog Desttructor" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
	std::cout << "Dog assignement operator overloading" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return(*this);
}

Dog :: Dog(const Dog &obj)
{
	std::cout << "Dog Copy Constructor" << std::endl;
	*this = obj;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}
