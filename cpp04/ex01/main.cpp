#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();
	// delete j;//should not create a leak
	// delete i;

	// const Animal *animal[4];
	// int	count = 0;
	// for (int i = 0; i < 2; i++)
	// 	animal[i] = new Dog();
	// for (int i = 2; i < 4; i++)
	// 	animal[i] = new Cat();
	// // std::cout << "*************************************"<< std::endl;
	// while (count < 4)
	// {
	// 	delete animal[count++];
	// }
	// std::cout << "*************************************"<< std::endl;
	// Dog basic;
	// std::cout << "*************************************"<< std::endl;
	// Dog tmp;
	// tmp = basic;
	// // basic = tmp;
	// // tmp = basic;
	// std::cout << "*************************************"<< std::endl;
	// std::cout << "*************************************"<< std::endl;
	system("leaks WorldOnFire");
	return 0;
}