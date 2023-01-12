#include "Zombie.hpp"

int main()
{
	Zombie	*nouhaila = zombieHorde(3, "nouhaila");
	for (int i = 0; i < 3; i++)
		nouhaila[i].announce();
	delete[] nouhaila;
}