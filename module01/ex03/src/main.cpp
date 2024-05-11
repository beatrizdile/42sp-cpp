#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	Weapon sword("espadinha");

	HumanA bilokah("beatriz", sword);
	bilokah.attack();
	sword.setType("espanDONA");
	bilokah.attack();

	std::cout << "---------------------------" << std::endl;

	HumanB rodrigo("rods");
	rodrigo.attack();
	rodrigo.setWeapon(sword);
	rodrigo.attack();
	sword.setType("machado");
	rodrigo.attack();


}
