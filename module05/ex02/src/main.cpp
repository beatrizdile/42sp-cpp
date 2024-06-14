#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "FormAlreadySignedException.hpp"
#include "FormNotSignedException.hpp"
#include "BureaucratGradeTooLowException.hpp"

int main(void) 
{
	// AForm form("form", 1, 1); // Abstract class can't be instantiated

	PresidentialPardonForm form("Target");
	Bureaucrat great("bureaucrat", 1);
	Bureaucrat low("bureaucrat", 26);

	low.signForm(form);
	try
	{
		form.beSigned(low); // Bureaucrat grade is too low to sign the form
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	form.beSigned(great);
	try
	{
		form.execute(low); // Bureaucrat grade is too low to execute the form
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	form.execute(great);

	return 0;
}
