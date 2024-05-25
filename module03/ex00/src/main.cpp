#include "ClapTrap.hpp"
#include <iostream>

int main(void) 
{
	ClapTrap bea("Beatriz");

	bea.takeDamage(1);
	bea.printStatus();
	bea.attack("the dummy");
	bea.takeDamage(5);
	bea.printStatus();
	bea.beRepaired(3); 
	bea.printStatus();

	// test energy points
	// bea.attack("the dummy");

	bea.takeDamage(10);
	bea.attack("the dummy");
	bea.beRepaired(3);
}