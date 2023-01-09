#include "HumanB.hpp"

void HumanB :: attack()
{
	if (!this->wpn)
		std:: cout << this->name << "   attacks \n";
	else
		std::cout << this->name << " attacks with their " << this->wpn->getType() << std::endl;;
}

// HumanB :: HumanB(std::string name, Weapon wpn)
// {
// 	this->name = name;
// 	this->wpn = wpn;
// }

HumanB ::HumanB (std::string name)
{
	this->name = name;
}

void HumanB::setWeapon(Weapon& wpn)
{
	this->wpn = &wpn;
}
