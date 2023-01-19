#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap nouha("nouha");

	nouha.attack("khoula");
	nouha.beRepaired(10);
	nouha.attack("khaoula");
	nouha.highFivesGuys();
	nouha.takeDamage(1550);
	nouha.attack("khaoula");
}
