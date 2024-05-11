#include "HumanB.hpp"

HumanB::HumanB(std::string humanName) : name(humanName), weapon(NULL) {}

HumanB::~HumanB() {}

const std::string& HumanB::getName(void){
	std::string& getName = this->name;
	return (getName);
}

void HumanB::attack(void){
	if (weapon != NULL)
		std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their " << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
	this->weapon = &weapon;
}