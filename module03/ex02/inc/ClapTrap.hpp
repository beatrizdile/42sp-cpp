#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& copy);
		ClapTrap& operator=(ClapTrap& other);
		~ClapTrap();

		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			printStatus(void);

		// Getters and Setters
		std::string		getName(void);
		unsigned int	getHitPoints(void);
		int				getEnergyPoints(void);
		int				getAttackDamage(void);
		void			setName(std::string name);
		void			setHitPoints(int hit_points);
		void			setEnergyPoints(int energy_points);
		void			setAttackDamage(int attack_damage);

	protected:
		std::string		name;
		unsigned int	hit_points;
		int				energy_points;
		int				attack_damage;

		bool			hasEnergy(void);
		bool			isDead(void);
};

#endif