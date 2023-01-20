#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;
	return 0;
}