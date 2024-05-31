#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat& copy);
		WrongCat& operator=(WrongCat& other);
		~WrongCat();

		void	makeSound() const;
};
