#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	// ScavTrap nouha("nouha");
	ScavTrap nouha("nouha");

	nouha.attack("koo");
	nouha.beRepaired(10);
	nouha.attack("koo");
	nouha.guardGate();
	nouha.takeDamage(1550);
	nouha.attack("koo");
}