#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) 
{
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

void FragTrap::highFivesGuys()
{
	if (name.length() == 0)
		std::cout << "FragTrap request positive high fives" << std::endl;
	else
		std::cout << "FragTrap " << name << " request positive high fives" << std::endl;
}

FragTrap::FragTrap()
{
	if (name.length() == 0)
		std::cout << "FragTrap Default constructor called" << std::endl;
	else
		std::cout << "FragTrap " << name << " Default constructor called" << std::endl;
	this->name = name;
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

FragTrap::~FragTrap()
{
	if (name.length() == 0)
		std::cout << "FragTrap Destructor called" << std::endl;
	else
		std::cout << "FragTrap " << name << " Destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& obj)
{
	std::cout << "FragTrap Copy assignement called" << std::endl;
	this->name = obj.name;
	this->HitPoints = obj.HitPoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	return (*this);
}

FragTrap::FragTrap(FragTrap & obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = obj;
}
