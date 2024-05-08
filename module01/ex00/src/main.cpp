#include "Zombie.hpp"

int main()
{
	Zombie bea("bea");
	bea.announce();

	Zombie* rodrigo = newZombie("rodrigo");
	rodrigo->announce();
	delete rodrigo;

	randomChump("rods");

	return (0);
}
