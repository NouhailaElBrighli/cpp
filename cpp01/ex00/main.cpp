#include "Zombie.hpp"

int main()
{
	Zombie *nouha = newZombie("nouha");
	nouha->announce();
	delete  nouha;

	randomChump("lolo-la");
}
	