#include "RobotomyRequestForm.hpp"
#include "BureaucratGradeTooLowException.hpp"
#include "FormNotSignedException.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime> 

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", ROBOTOMYREQUEST_GRADE_TO_SIGN, ROBOTOMYREQUEST_GRADE_TO_EXEC){};

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("Robotomy Request", ROBOTOMYREQUEST_GRADE_TO_SIGN, ROBOTOMYREQUEST_GRADE_TO_EXEC), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& copy) {
	this->_target = copy._target;
};

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
};

RobotomyRequestForm::~RobotomyRequestForm() {};

bool RobotomyRequestForm::robotomySuccess() const {
	 srand(static_cast<unsigned int>(time(0)));
    return rand() % 2 == 0;
};

void RobotomyRequestForm::action() const {
	std::cout << "Bzzzzzz..." << std::endl;
	if (robotomySuccess()) {
		std::cout << this->_target << " robotomization failed" << std::endl;
	}
	else{
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	}
};
