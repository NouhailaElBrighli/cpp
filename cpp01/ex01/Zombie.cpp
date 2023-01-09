#include "Zombie.hpp"

Zombie :: ~Zombie()
{
	std::cout << this->name << " : destructor" << std::endl;
}

void Zombie :: announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

