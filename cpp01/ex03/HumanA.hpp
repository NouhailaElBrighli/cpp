#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	Weapon *wpn;
	std::string name;

	public :
		HumanA(std::string name, Weapon& wpn);
		void attack();
};