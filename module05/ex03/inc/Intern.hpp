#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern
{
	private:
		std::string _name;
		std::string _target;
	public:
		Intern();
		Intern(std::string name, std::string target);
		Intern(Intern& copy);
		Intern& operator=(Intern& other);
		~Intern();

		AForm* makeForm(std::string formName, std::string target);
};

#endif