#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <limits>

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