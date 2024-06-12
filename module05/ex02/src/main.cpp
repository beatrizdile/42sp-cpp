#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) 
{	
	// AForm form("form", 1, 1); // Abstract class can't be instantiated

	PresidentialPardonForm form("beatriz");
	Bureaucrat bureaucrat("bureaucrat", 1);
	form.execute(bureaucrat);

	return 0;
}
