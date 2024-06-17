#ifndef FORMNOTFOUNDEXCEPTION_HPP
#define FORMNOTFOUNDEXCEPTION_HPP

#include <iostream>

class FormNotFoundException: public std::exception
{
	public:
		virtual const char* what() const throw();
};


#endif