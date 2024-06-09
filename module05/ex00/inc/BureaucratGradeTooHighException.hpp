#ifndef BUREAUCRATGRADETOOHIGHEXCEPTION_HPP
#define BUREAUCRATGRADETOOHIGHEXCEPTION_HPP

#include <iostream>

class bureaucratGradeTooHighException: public std::exception
{
	public:
		virtual const char* what() const throw(){
			return "GradeTooHighException";
		};
};

#endif