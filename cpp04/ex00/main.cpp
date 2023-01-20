#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	

	delete i;
	delete j;
	delete meta;
	// const WrongAnimal *cat = new WrongCat();
	// cat->makeSound();
	// delete cat;
	// system("leaks Polymorphism");
	return 0;
}