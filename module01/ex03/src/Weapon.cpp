#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) : type(weaponType) {}

Weapon::~Weapon() {}

const std::string& Weapon::getType(void){
	std::string& getType = this->type;
	return (getType);
}

void Weapon::setType(std::string newType){
	this->type = newType;
}
