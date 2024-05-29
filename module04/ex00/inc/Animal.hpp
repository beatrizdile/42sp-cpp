#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(std::string name);
		Animal(Animal& copy);
		Animal& operator=(Animal& other);
		~Animal();

		virtual void	makeSound() = 0;

		std::string 	getType();
		void			setType(std::string type);
	protected:
		std::string type;
};

#endif