#ifndef BUREAUCRATGRADETOOLOWEXCEPTION_HPP
#define BUREAUCRATGRADETOOLOWEXCEPTION_HPP

#include <iostream>

class bureaucratGradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw(){
			return "GradeTooLowException";
		};
};

#endif