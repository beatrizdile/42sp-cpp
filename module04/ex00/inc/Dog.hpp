#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string name);
		Dog(Dog& copy);
		Dog& operator=(Dog& other);
		~Dog();

		void	makeSound();
};
