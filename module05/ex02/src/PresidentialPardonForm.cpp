#include "PresidentialPardonForm.hpp"
#include "BureaucratGradeTooLowException.hpp"
#include "FormNotSignedException.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5){};

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("Presidential Pardon", 25, 5), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& copy) {
	this->_target = copy._target;
};

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
};

PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::action() const {
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};
