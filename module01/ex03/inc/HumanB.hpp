#ifndef HUMANB_CPP
#define HUMANB_CPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		HumanB(std::string humanName);
		~HumanB();
		const std::string& getName(void);
		void attack(void);
		void setWeapon(Weapon& weapon);
};

#endif