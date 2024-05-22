#include "ClapTrap.hpp"
#include <iostream>

int main(void) 
{
	ClapTrap bea("Beatriz");

	bea.takeDamage(1);
	bea.attack("the dummy");
	bea.takeDamage(5);
	bea.beRepaired(3); 
	// test energy points
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	// bea.attack("the dummy");
	bea.takeDamage(10);
	bea.attack("the dummy");
	bea.beRepaired(3);
}