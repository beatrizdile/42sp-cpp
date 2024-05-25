#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "FragTrap: Default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap: Constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap& copy) : ClapTrap(copy){
	std::cout << "FragTrap: Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap& other){
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap: Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << getName() << " requests a high five!" << std::endl;
};
