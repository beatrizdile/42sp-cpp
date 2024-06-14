#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "FormAlreadySignedException.hpp"
#include "FormNotSignedException.hpp"
#include "BureaucratGradeTooLowException.hpp"

int main(void) 
{	
	// AForm form("form", 1, 1); // Abstract class can't be instantiated

	PresidentialPardonForm form("beatriz");
	Bureaucrat bureaucrat("bureaucrat", 1);
	try{
		form.execute(bureaucrat);
	} catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
