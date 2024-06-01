#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat& copy);
		Cat& operator=(Cat& other);
		~Cat();

		void	makeSound() const;
		Brain*	getBrain() const;
		void	setBrain(Brain* brain);
	private:
		Brain* brain;
};
