#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public :
		FragTrap();
		FragTrap(FragTrap& obj);
		FragTrap& operator=(FragTrap& obj);
		FragTrap(std::string name);
		~FragTrap();
		void highFivesGuys(void);
};

#endif