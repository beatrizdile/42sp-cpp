#include "FormAlreadySignedException.hpp"

const char* FormAlreadySignedException::what() const throw(){
	return "form already signed";
};
