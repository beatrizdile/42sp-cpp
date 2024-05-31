#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat& copy);
		Cat& operator=(Cat& other);
		~Cat();

		void	makeSound() const;
};
