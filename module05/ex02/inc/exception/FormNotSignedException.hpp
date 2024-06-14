#ifndef FORMNOTSIGNEDEXCEPTION_HPP
#define FORMNOTSIGNEDEXCEPTION_HPP

#include <iostream>

class FormNotSignedException: public std::exception
{
	public:
		virtual const char* what() const throw();
};


#endif