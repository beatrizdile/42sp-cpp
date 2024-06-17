#include "ShrubberyCreationForm.hpp"
#include "BureaucratGradeTooLowException.hpp"
#include "FormNotSignedException.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", SHRUBBERYCREATION_GRADE_TO_SIGN, SHRUBBERYCREATION_GRADE_TO_EXEC){};

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("Shrubbery Creation", SHRUBBERYCREATION_GRADE_TO_SIGN, SHRUBBERYCREATION_GRADE_TO_EXEC), _target(target) {};

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& copy) {
	this->_target = copy._target;
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
};

ShrubberyCreationForm::~ShrubberyCreationForm() {};

void ShrubberyCreationForm::action() const {

	std::string filename = _target + "_shrubbery";
	std::ofstream outFile;
    outFile.open(filename.c_str());

    if (!outFile) {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return ;
    }

    outFile << "       _-_\n";
    outFile << "    /~~   ~~\\\n";
    outFile << " /~~         ~~\\\n";
    outFile << "{               }\n";
    outFile << " \\  _-     -_  /\n";
    outFile << "   ~  \\\\ //  ~\n";
    outFile << "_- -   | | _- _\n";
    outFile << "  _ -  | |   -_\n";
    outFile << "      // \\\\\n";

    outFile.close();
};
