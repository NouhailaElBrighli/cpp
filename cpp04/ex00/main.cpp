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

	std::cout << meta->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	return 0;
}

// int main()
// {
// 	const WrongAnimal *anl = new WrongAnimal();
// 	const WrongAnimal *cat = new WrongCat();

// 	anl->makeSound();
// 	cat->makeSound();
// 	delete anl;
// 	delete cat;
// }