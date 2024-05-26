#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "Constructor called" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap& copy){
	std::cout << "Copy constructor called" << std::endl;
	setName(copy.getName());
	setHitPoints(copy.getHitPoints());
	setEnergyPoints(copy.getEnergyPoints());
	setAttackDamage(copy.getAttackDamage());
};

ClapTrap& ClapTrap::operator=(ClapTrap& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other){
		setName(other.getName());
		setHitPoints(other.getHitPoints());
		setEnergyPoints(other.getEnergyPoints());
		setAttackDamage(other.getAttackDamage());
	}
	return *this;
};

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

bool ClapTrap::hasEnergy(void){
	if (getEnergyPoints() == 0){
		std::cout << "ClapTrap " << getName() << " is out of energy points!" << std::endl;
		return false;
	}
	return true;
};

bool ClapTrap::isDead(void){
	if (getHitPoints() == 0){
		std::cout << "ClapTrap " << getName() << " is dead!" << std::endl;
		return true;
	}
	return false;
};

void ClapTrap::printStatus(void){
	std::cout << "--------------------------" << std::endl;
	std::cout << "ClapTrap " << getName() << " status:" << std::endl;
	std::cout << "hit points: " << getHitPoints() << std::endl;
	std::cout << "energy points: " << getEnergyPoints() << std::endl;
	std::cout << "--------------------------" << std::endl;
};

void ClapTrap::attack(const std::string& target){
	if (isDead() || !hasEnergy()){
		return;
	}
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoints(getEnergyPoints() - 1);
};

void ClapTrap::takeDamage(unsigned int amount){
	if (isDead()){
		return;
	}
	if (amount > getHitPoints()){
		amount = getHitPoints();
	}
	std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
	setHitPoints(getHitPoints() - amount);
	isDead();
};

void ClapTrap::beRepaired(unsigned int amount){
	if (isDead() || !hasEnergy()){
		return;
	}
	std::cout << "ClapTrap " << getName() << " is repaired for " << amount << " hit points!" << std::endl;
	setHitPoints(getHitPoints() + amount);
	setEnergyPoints(getEnergyPoints() - 1);
};

// Getters and Setters
std::string ClapTrap::getName(void){
	return name;
};

unsigned int ClapTrap::getHitPoints(void){
	return hit_points;
};

int	ClapTrap::getEnergyPoints(void){
	return energy_points;
};

int	ClapTrap::getAttackDamage(void){
	return attack_damage;
};

void ClapTrap::setName(std::string name){
	this->name = name;
};

void ClapTrap::setHitPoints(int hit_points){
	this->hit_points = hit_points;
};

void ClapTrap::setEnergyPoints(int energy_points){
	this->energy_points = energy_points;
};

void ClapTrap::setAttackDamage(int attack_damage){
	this->attack_damage = attack_damage;
};
