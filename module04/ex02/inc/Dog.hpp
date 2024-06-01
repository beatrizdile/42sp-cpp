#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog& copy);
		Dog& operator=(Dog& other);
		~Dog();

		void	makeSound() const;
		Brain*	getBrain() const;
		void	setBrain(Brain* brain);
	private:
		Brain* brain;
};
