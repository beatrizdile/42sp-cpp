#include "BureaucratGradeTooLowException.hpp"

const char* BureaucratGradeTooLowException::what() const throw(){
	return "GradeTooLowException";
};
