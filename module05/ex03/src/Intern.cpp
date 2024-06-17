#include <iostream>
#include "Intern.hpp"
#include "FormNotFoundException.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() : _name("default"), _target("default") {};

Intern::Intern(std::string name, std::string target) : _name(name), _target(target) {};

Intern::Intern(Intern& copy) : _name(copy._name), _target(copy._target) {};

Intern& Intern::operator=(Intern& other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	_target = other._target;
	return *this;
};

Intern::~Intern() {}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	std::string	arrayForms[4] = {"unknown", "shrubbery creation", "robotomy request", "presidential pardon"};
	size_t		index = 0;

	for (size_t i = 0; i < formName.length(); i++) {
        formName[i] = std::tolower(static_cast<unsigned char>(formName[i]));
    }

	for (size_t i = 0; i < formName.length(); i++){
		if (formName == arrayForms[i]) {
			index = i;
			break;
		}
	}

	switch(index)
	{
		case 0:
			std::cout << "Intern couldn't create " << formName << std::endl;
			throw FormNotFoundException();
			return NULL;
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 3:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
	}

	return NULL;
};
