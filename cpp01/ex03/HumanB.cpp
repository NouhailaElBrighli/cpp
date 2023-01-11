#include "HumanB.hpp"

void HumanB :: attack()
{
	if (!this->wpn)
		std:: cout << this->name << "   attacks " << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->wpn->getType() << std::endl;;
}

HumanB ::HumanB (std::string name)
{
	this->name = name;
	this->wpn = NULL;
}

void HumanB::setWeapon(Weapon& wpn)
{
	this->wpn = &wpn;
}
