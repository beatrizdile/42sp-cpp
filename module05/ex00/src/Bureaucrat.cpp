#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat() {};

std::string const Bureaucrat::getName() const {
	return this->_name;
};

int Bureaucrat::getGrade() const {
	return this->_grade;
};

void Bureaucrat::incrementGrade() {
	if (this->_grade > 1)
		this->_grade--;
};

void Bureaucrat::decrementGrade() {
	if (this->_grade < 150)
		this->_grade++;
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &bureaucrat){
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return o;
};
