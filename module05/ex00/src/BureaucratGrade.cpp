#include "BureaucratGrade.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"

BureaucratGrade::BureaucratGrade(){};

BureaucratGrade::BureaucratGrade(BureaucratGrade const &other){
	*this = other;
};

BureaucratGrade& BureaucratGrade::operator=(BureaucratGrade const &other){
	(void)other;
	return *this;
};

BureaucratGrade::~BureaucratGrade(){};

void BureaucratGrade::checkBureaucratGradeException(int grade){
	if (grade < 1)
		throw bureaucratGradeTooHighException();
	else if (grade > 150)
		throw bureaucratGradeTooLowException();
};
