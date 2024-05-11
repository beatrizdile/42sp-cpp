#ifndef HUMANA_CPP
#define HUMANA_CPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;
	public:
		HumanA(std::string humanName, Weapon& weapon);
		~HumanA();
		const std::string& getName(void);
		void attack(void);

};

#endif