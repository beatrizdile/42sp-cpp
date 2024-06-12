#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"
#include "FormAlreadySignedException.hpp"
#include "FormNotSignedException.hpp"

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false) {};

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	Bureaucrat::checkBureaucratGradeException(gradeToSign);
	Bureaucrat::checkBureaucratGradeException(gradeToExecute);
};

AForm::AForm(AForm& copy) : _name(copy.getName()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()), _isSigned(copy.getIsSigned()) {};

AForm& AForm::operator=(AForm& other){
	this->_isSigned = other.getIsSigned();
	return *this;
};

AForm::~AForm() {};

std::ostream& operator<<(std::ostream &o, AForm const &form){
	o << "AForm: " << form.getName() << std::endl;
	o << "Grade to sign: " << form.getGradeToSign() << std::endl;
	o << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	o << "Is signed: " << form.getIsSigned() << std::endl;
	return o;
};

void AForm::execute(Bureaucrat const & executor) const{
	if (!this->getIsSigned()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->getGradeToExecute()) {
		throw BureaucratGradeTooLowException();
	}
	this->action();
};

void AForm::beSigned(Bureaucrat& bureaucrat){
	if (this->_isSigned) 
	{
        throw FormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw BureaucratGradeTooLowException();
    }
    _isSigned = true;
};

std::string AForm::getName() const{
	return this->_name;
};

int AForm::getGradeToSign() const{
	return this->_gradeToSign;
};

int AForm::getGradeToExecute() const{
	return this->_gradeToExecute;
};

bool AForm::getIsSigned() const{
	return this->_isSigned;
};
