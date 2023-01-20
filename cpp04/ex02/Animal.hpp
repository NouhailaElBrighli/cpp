#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	protected :
		std::string type;
	public :
		virtual ~Animal();
		virtual void makeSound() const = 0;
		std::string const & getType()const;
};


#endif