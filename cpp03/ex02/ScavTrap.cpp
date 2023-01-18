#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) 
{
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap " << name << " Default constructor called" << std::endl;
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	if (name.length() == 0)
		std::cout << "ScavTrap Destructor called" << std::endl;
	else
		std::cout << "ScavTrap " << name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoints == 0 || this->HitPoints == 0)
	{
		if (name.length() == 0)
			std::cout << "\033[1;31m" << "he is already died\033[1;30m" << std::endl;
		else
			std::cout << "\033[1;31m" << name << " is already died\033[1;30m" << std::endl;
		return;
	}
	this->EnergyPoints--;
	if (name.length() == 0)
		std::cout << "\033[1;32mScavTrap attacks "  << target << " " << "causing " << AttackDamage << " point of damage\033[1;30m" << std::endl;
	else
	std::cout << "\033[1;32mScavTrap "  << name << " attacks "  << target << " " << "causing " << AttackDamage << " point of damage\033[1;30m" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& obj)
{
	std::cout << "Scavtrap Copy assignement called" << std::endl;
	this->name = obj.name;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	return (*this);
}

ScavTrap::ScavTrap(ScavTrap & obj)
{
	std::cout << "Scavtrap Copy constructor called" << std::endl;
	*this = obj;
}
