#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap: Constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap& copy) : ClapTrap(copy){
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& other){
	std::cout << "ScavTrap: Copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap: Destructor called" << std::endl;
}

void ScavTrap::guardGate(void){
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
};

void ScavTrap::attack(const std::string& target){
	if (isDead() || !hasEnergy()){
		return;
	}
	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing a walloping amount of " << getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
};
