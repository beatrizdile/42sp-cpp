#ifndef BUREAUCRATGRADETOOHIGHEXCEPTION_HPP
#define BUREAUCRATGRADETOOHIGHEXCEPTION_HPP

#include <iostream>

class BureaucratGradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif