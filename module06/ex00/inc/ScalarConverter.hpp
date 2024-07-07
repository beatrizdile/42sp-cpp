#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(ScalarConverter& copy);
		ScalarConverter& operator=(ScalarConverter& other);

	public:
		static void convert(const std::string &str);
};

#endif