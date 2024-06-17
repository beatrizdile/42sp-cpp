#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "FormAlreadySignedException.hpp"
#include "FormNotSignedException.hpp"
#include "BureaucratGradeTooLowException.hpp"

int main(void) 
{
	// AForm form("form", 1, 1); // Abstract class can't be instantiated

	Bureaucrat greatBureaucrat("greatBureaucrat", 1);
	Bureaucrat lowBureaucrat("lowBureaucrat", 150);

	Intern		intern;

	AForm* shrubbery 	= intern.makeForm("shrubbery creation", "target");
	AForm* robotomy 	= intern.makeForm("robotomy request", "target");
	AForm* presidential = intern.makeForm("presidential pardon", "target");

	try{
		AForm* unknown = intern.makeForm("unknown form", "target");
		(void) unknown;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	lowBureaucrat.signForm(*shrubbery);
	lowBureaucrat.signForm(*robotomy);
	lowBureaucrat.signForm(*presidential);

	greatBureaucrat.signForm(*shrubbery);
	greatBureaucrat.signForm(*robotomy);
	greatBureaucrat.signForm(*presidential);

	lowBureaucrat.executeForm(*shrubbery);
	lowBureaucrat.executeForm(*robotomy);
	lowBureaucrat.executeForm(*presidential);

	greatBureaucrat.executeForm(*shrubbery);
	greatBureaucrat.executeForm(*robotomy);
	greatBureaucrat.executeForm(*presidential);

	return 0;
}
