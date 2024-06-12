#ifndef BUREAUCRATALREADYSIGNEXCEPTION_HPP
#define BUREAUCRATALREADYSIGNEXCEPTION_HPP

#include <iostream>

class FormAlreadySignedException: public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif