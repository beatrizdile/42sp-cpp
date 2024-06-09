#include "Bureaucrat.hpp"
#include "BureaucratGrade.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	try
	{
		BureaucratGrade::checkBureaucratGradeException(grade);
		this->_grade = grade;
	} 
	catch (bureaucratGradeTooHighException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
	catch (bureaucratGradeTooLowException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
};

Bureaucrat::Bureaucrat(Bureaucrat& copy) : _name(copy.getName()), _grade(copy.getGrade()) {};

Bureaucrat& Bureaucrat::operator=(Bureaucrat& other){
	if (this != &other){
		this->_grade = other.getGrade();
	}
	return *this;
};

Bureaucrat::~Bureaucrat() {};

std::string const Bureaucrat::getName() const {
	return this->_name;
};

int Bureaucrat::getGrade() const {
	return this->_grade;
};

void Bureaucrat::incrementGrade() {
	try
	{
		BureaucratGrade::checkBureaucratGradeException(_grade - 1);
		if (this->_grade > 1)
			this->_grade--;
	}
	catch (bureaucratGradeTooHighException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
	catch (bureaucratGradeTooLowException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
};

void Bureaucrat::decrementGrade() {
	try
	{
		BureaucratGrade::checkBureaucratGradeException(_grade + 1);
		if (this->_grade < 150)
			this->_grade++;
	}
	catch (bureaucratGradeTooHighException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
	catch (bureaucratGradeTooLowException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &bureaucrat){
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return o;
};
