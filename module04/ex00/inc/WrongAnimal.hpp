#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(WrongAnimal& copy);
		WrongAnimal& operator=(WrongAnimal& other);
		~WrongAnimal();

		void	makeSound() const;

		std::string 	getType() const;
		void			setType(std::string type);
	protected:
		std::string type;
};

#endif