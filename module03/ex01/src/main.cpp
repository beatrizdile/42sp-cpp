#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void) 
{
	ScavTrap bea("Bea");

	bea.printStatus();
	bea.takeDamage(1);
	bea.attack("the dummy");
	bea.takeDamage(5);
	bea.printStatus();
	bea.beRepaired(3); 
	bea.printStatus();

	// test energy points
	bea.attack("the dummy");

	bea.takeDamage(10);
	bea.attack("the dummy");
	bea.beRepaired(3);
}