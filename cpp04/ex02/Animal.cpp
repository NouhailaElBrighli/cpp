#include "Animal.hpp"

Animal::~Animal()
{
	std::cout << "Animal Desttructor" << std::endl;
}

std::string const& Animal::getType() const
{
	return (type);
}
