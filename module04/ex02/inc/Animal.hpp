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
		virtual ~Animal();

		virtual void	makeSound() const = 0;

		std::string 	getType() const;
		void			setType(std::string type);
	protected:
		std::string type;
};

#endif