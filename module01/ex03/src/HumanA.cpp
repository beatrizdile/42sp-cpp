#include "HumanA.hpp"

HumanA::HumanA(std::string humanName, Weapon& weapon) : name(humanName), weapon(weapon) {}

HumanA::~HumanA() {}

const std::string& HumanA::getName(void){
	std::string& getName = this->name;
	return (getName);
}

void HumanA::attack(void){
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}