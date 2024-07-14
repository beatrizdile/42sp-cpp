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

void ScalarConverter::convert(const std::string &str) {
    char *endptr = NULL;
    bool isFloat = false;
    double value;

    if (str.size() == 1 && !std::isdigit(str[0])) {
        if (!std::isprint(str[0])) {
            std::cout << "invalid input" << std::endl;
            return;
        }
        value = static_cast<double>(str[0]);
    } else {
        std::string str_copy = str;
        if (str[str.size() - 1] == 'f' && (str.rfind("inf") != str.size() - 3)) {
            isFloat = true;
            str_copy.erase(str.size() - 1);
        }
        value = std::strtod(str_copy.c_str(), &endptr);
    }

    if ((endptr != NULL && *endptr != '\0') || (isFloat && !std::isinf(value) && !std::isnan(value) && str.find(".") == std::string::npos)) {
        std::cout << "invalid input" << std::endl;
        return;
    }

    if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible" << std::endl;
    } else if (!std::isprint(static_cast<char>(value))) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }

    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }

    std::cout << std::fixed << std::setprecision(1);

    if (!std::isinf(value) && (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }

    std::cout << "double: " << value << std::endl;
}
