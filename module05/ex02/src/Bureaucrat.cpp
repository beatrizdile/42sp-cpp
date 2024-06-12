#include "Bureaucrat.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {};

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	Bureaucrat::checkBureaucratGradeException(grade);
	this->_grade = grade;
};

Bureaucrat::Bureaucrat(Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {};

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other){
	if (this != &other){
		this->_grade = other.getGrade();
	}
	return *this;
};

Bureaucrat::~Bureaucrat() {};

void Bureaucrat::checkBureaucratGradeException(int grade){
	if (grade < 1)
		throw BureaucratGradeTooHighException();
	else if (grade > 150)
		throw BureaucratGradeTooLowException();
};

void Bureaucrat::signForm(AForm& form){
	try 
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
};

void Bureaucrat::incrementGrade() {
	Bureaucrat::checkBureaucratGradeException(_grade - 1);
	if (this->_grade > 1)
		this->_grade--;
};

void Bureaucrat::decrementGrade() {
	Bureaucrat::checkBureaucratGradeException(_grade + 1);
	if (this->_grade < 150)
		this->_grade++;
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &bureaucrat){
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return o;
};

std::string const Bureaucrat::getName() const {
	return this->_name;
};

int Bureaucrat::getGrade() const {
	return this->_grade;
};