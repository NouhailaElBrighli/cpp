#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	// FragTrap nouha("nouha");
	FragTrap nouha("nouha");

	nouha.attack("koo");
	nouha.beRepaired(10);
	nouha.attack("koo");
	nouha.highFivesGuys();
	nouha.takeDamage(1550);
	nouha.attack("koo");
}