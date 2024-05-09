#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(3, "bilokah");

	horde[0].announce();
	horde[1].announce();
	horde[2].announce();

	delete[] horde;

	return (0);
}
