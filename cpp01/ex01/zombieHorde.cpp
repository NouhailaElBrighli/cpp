#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombie = new Zombie[N];

	Zombie *tmp = zombie;
	for (int i = 0; i < N; i++)
	{
		(*tmp).set_name(name);
		tmp++;
	}
	return(zombie);
}