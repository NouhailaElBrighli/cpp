#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain *br;
	public :
		Dog();
		Dog(const Dog &obj);
		Dog &operator=(const Dog &obj);
		virtual ~Dog();
		void makeSound()const;
};


#endif