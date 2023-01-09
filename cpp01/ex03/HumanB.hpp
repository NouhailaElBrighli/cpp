#include <iostream>
#include "HumanA.hpp"

class HumanB
{
	Weapon *wpn;
	std::string name;

	public :
		// HumanB(std::string name, Weapon wpn);
		HumanB(std::string name);
		void setWeapon(Weapon& wpn);
		void attack();
};