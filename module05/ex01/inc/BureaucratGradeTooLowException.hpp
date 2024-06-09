#ifndef BUREAUCRATGRADETOOLOWEXCEPTION_HPP
#define BUREAUCRATGRADETOOLOWEXCEPTION_HPP

#include <iostream>

class BureaucratGradeTooLowException: public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif