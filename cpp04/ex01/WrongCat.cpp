#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat constructor" << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Desttructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "WrongCat assignement operator overloading" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return(*this);
}

WrongCat :: WrongCat(const WrongCat &obj)
{
	std::cout << "WrongCat Copy Constructor" << std::endl;
	*this = obj;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}
