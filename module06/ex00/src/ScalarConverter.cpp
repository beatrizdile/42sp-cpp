#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter& copy)
{
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& other)
{
	if (this != &other){
		;
	}
	return *this;
}

void ScalarConverter::convert(const std::string &str)
{
	std::cout << "char: ";
	try
	{
		char c = static_cast<char>(std::stoi(str));
		if (c < 32 || c > 126)
			throw std::exception();
		std::cout << "'" << c << "'" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	try
	{
		int i = std::stoi(str);
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	try
	{
		float f = std::stof(str);
		std::cout << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "double: ";
	try
	{
		double d = std::stod(str);
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}
