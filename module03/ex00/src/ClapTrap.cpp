#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(), hit_points(10), energy_points(10), attack_damage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0){};

ClapTrap::ClapTrap(ClapTrap& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
};

ClapTrap& ClapTrap::operator=(ClapTrap& other){
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &other){
		this->name = other.getName();
		this->hit_points = other.getHitPoints();
		this->energy_points = other.getEnergyPoints();
		this->attack_damage = other.getAttackDamage();
	}
	return *this;
};

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

bool ClapTrap::hasEnergy(void){
	if (getEnergyPoints() == 0){
		std::cout << "ClapTrap " << name << " is out of energy points!" << std::endl;
		return false;
	}
	return true;
};

bool ClapTrap::isDead(void){
	if (getHitPoints() == 0){
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
		return true;
	}
	return false;
};

void ClapTrap::printStatus(void){
	std::cout << "--------------------------" << std::endl;
	std::cout << "ClapTrap " << name << " status:" << std::endl;
	std::cout << "hit points: " << hit_points << std::endl;
	std::cout << "energy points: " << energy_points << std::endl;
	std::cout << "--------------------------" << std::endl;
};

void ClapTrap::attack(const std::string& target){
	if (!hasEnergy() || isDead()){
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	this->energy_points -= 1;
	printStatus();
};

void ClapTrap::takeDamage(unsigned int amount){
	if (isDead()){
		return;
	}
	if (amount > getHitPoints()){
		amount = getHitPoints();
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	setHitPoints(getHitPoints() - amount);
	if (getHitPoints() == 0){
		std::cout << "ClapTrap " << name << " is dead!" << std::endl;
	}
	else{
		printStatus();
	}
};

void ClapTrap::beRepaired(unsigned int amount){
	if (!hasEnergy() || isDead()){
		return;
	}
	std::cout << "ClapTrap " << name << " is repaired for " << amount << " hit points!" << std::endl;
	setHitPoints(getHitPoints() + amount);
	this->energy_points -= 1;
	printStatus();
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
