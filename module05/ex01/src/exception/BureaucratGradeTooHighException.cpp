#include "BureaucratGradeTooHighException.hpp"

const char* BureaucratGradeTooHighException::what() const throw(){
	return "GradeTooHighException";
};
