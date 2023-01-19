#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat constructor" << std::endl;
	this->type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat Desttructor" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
	std::cout << "Cat assignement operator overloading" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return(*this);
}

Cat :: Cat(const Cat &obj)
{
	std::cout << "Cat Copy Constructor" << std::endl;
	*this = obj;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}