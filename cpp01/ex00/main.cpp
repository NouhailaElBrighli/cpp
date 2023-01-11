#include "Zombie.hpp"

int main()
{
	Zombie *nouha = newZombie("nouha");
	
	nouha->announce();
	randomChump("lolo-la");
	delete  nouha;
}
	