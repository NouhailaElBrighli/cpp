#include "Animal.hpp"

// Animal::Animal()
// {
// 	std::cout << "Animal constructor" << std::endl;
// 	type = "Animal";
// }

Animal::~Animal()
{
	std::cout << "Animal Desttructor" << std::endl;
}

// Animal& Animal::operator=(const Animal &obj)
// {
// 	std::cout << "Animal assignement operator overloading" << std::endl;
// 	if (this != &obj)
// 		this->type = obj.type;
// 	return(*this);
// }

// Animal :: Animal(const Animal &obj)
// {
// 	std::cout << "Animal Copy Constructor" << std::endl;
// 	*this = obj;
// }

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string const& Animal::getType() const
{
	return (type);
}
