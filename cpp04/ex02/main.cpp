#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();


	// Animal a;
	delete j;//should not create a leak
	delete i;
	// system("leaks Abstrac");
	return 0;
}