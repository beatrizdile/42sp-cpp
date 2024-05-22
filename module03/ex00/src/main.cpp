#include "ClapTrap.hpp"
#include <iostream>

int main(void) 
{
	ClapTrap bea("Beatriz");
	ClapTrap rods("Rodrigo");

	bea.attack("the dummy");
	bea.takeDamage(5);
	bea.beRepaired(3);

	rods.attack("the dummy");
	rods.takeDamage(5);
	rods.beRepaired(3);
}