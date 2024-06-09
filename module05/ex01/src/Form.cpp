#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"
#include "FormAlreadySignedException.hpp"

Form::Form() : _name("default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false) {};

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	Bureaucrat::checkBureaucratGradeException(gradeToSign);
	Bureaucrat::checkBureaucratGradeException(gradeToExecute);
};

Form::Form(Form& copy) : _name(copy.getName()), _gradeToSign(copy.getGradeToSign()), _gradeToExecute(copy.getGradeToExecute()), _isSigned(copy.getIsSigned()) {};

Form& Form::operator=(Form& other){
	this->_isSigned = other.getIsSigned();
	return *this;
};

Form::~Form() {};

std::ostream& operator<<(std::ostream &o, Form const &form){
	o << "Form: " << form.getName() << std::endl;
	o << "Grade to sign: " << form.getGradeToSign() << std::endl;
	o << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	o << "Is signed: " << form.getIsSigned() << std::endl;
	return o;
};

void Form::beSigned(Bureaucrat& bureaucrat){
	if (this->_isSigned) 
	{
        throw FormAlreadySignedException();
    }
    if (bureaucrat.getGrade() > this->_gradeToSign) {
        throw BureaucratGradeTooLowException();
    }
    _isSigned = true;
};

std::string Form::getName() const{
	return this->_name;
};

int Form::getGradeToSign() const{
	return this->_gradeToSign;
};

int Form::getGradeToExecute() const{
	return this->_gradeToExecute;
};

bool Form::getIsSigned() const{
	return this->_isSigned;
};
