#include "BureaucratGrade.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"

BureaucratGrade::BureaucratGrade(){};

BureaucratGrade::~BureaucratGrade(){};

void BureaucratGrade::checkBureaucratGradeException(int grade){
	if (grade < 1)
		throw bureaucratGradeTooHighException();
	else if (grade > 150)
		throw bureaucratGradeTooLowException();
};
