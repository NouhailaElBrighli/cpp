#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor" << std::endl;
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Desttructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal assignement operator overloading" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return(*this);
}

WrongAnimal :: WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
	*this = obj;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string const& WrongAnimal::getType() const
{
	return (type);
}
