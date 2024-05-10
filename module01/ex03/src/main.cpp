#include "Weapon.hpp"

int main()
{
	Weapon sword("espadinha");
	std::cout << sword.getType() << std::endl;

	sword.setType("espanDONA");
	std::cout << sword.getType() << std::endl;
}
