#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "FormAlreadySignedException.hpp"
#include "FormNotSignedException.hpp"
#include "BureaucratGradeTooLowException.hpp"

int main(void) 
{
	// AForm form("form", 1, 1); // Abstract class can't be instantiated

	// Form --------------------------------------------------------------------
	PresidentialPardonForm form("Target");
	Bureaucrat greatBureaucrat("greatBureaucrat", 1);
	Bureaucrat lowBureaucrat("lowBureaucrat", 150);

	lowBureaucrat.signForm(form); // Bureaucrat grade is too low to sign the form
	try
	{
		form.beSigned(lowBureaucrat); // Bureaucrat grade is too low to sign the form
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	lowBureaucrat.executeForm(form); // Form not signed yet
	try
	{
		form.execute(greatBureaucrat); // Form not signed yet
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	greatBureaucrat.signForm(form);
	lowBureaucrat.executeForm(form);
	try
	{
		form.execute(lowBureaucrat); // Bureaucrat grade is too low to execute the form
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	greatBureaucrat.executeForm(form);
	// -------------------------------------------------------------------------

	return 0;
}
