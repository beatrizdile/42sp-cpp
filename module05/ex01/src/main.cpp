#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"

int main(void) 
{
	std::cout << "----Bureaucrat with valid grades----" << std::endl;
	Bureaucrat rods("Rodrigo", 1);
	std::cout << rods << std::endl;
	Bureaucrat bea("Beatriz", 150);
	std::cout << bea << std::endl;


	std::cout << std::endl << "----Bureaucrat with grades too high or too low----" << std::endl;
	try
	{
		// Bureaucrat gi("Giovana", 151);
		// Bureaucrat paulo("Paulo", 0);
	}
	catch(BureaucratGradeTooHighException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
	catch(BureaucratGradeTooLowException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}

	std::cout << std::endl << "----Copy constructor & assignment operator----" << std::endl;
	Bureaucrat copyBea(bea);
	std::cout << "Bureaucrat bea copy: " << std::endl << copyBea << std::endl;
	Bureaucrat copyRods("CopyRodrigo", 100);
	copyRods = rods;
	std::cout << "Bureaucrat rods assignment operator: " << std::endl << copyRods << std::endl;


	std::cout << std::endl << "----Invalid increment & decrement----" << std::endl;
	try
	{
		// rods.incrementGrade();
		// bea.decrementGrade();
	}
	catch(BureaucratGradeTooHighException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}
	catch(BureaucratGradeTooLowException &e)
	{
		std::cerr << "Bureaucrat::" << e.what() << std::endl;
	}

	std::cout << std::endl << "-------Valid increments & decrements-------" << std::endl;
	bea.incrementGrade();
	rods.decrementGrade();
	std::cout << bea << std::endl;
	std::cout << rods << std::endl;


	std::cout << std::endl << "----Form with valid grades----" << std::endl;
	Form formBea("Form Bea", 1, 1);
	std::cout << formBea << std::endl;
	Form formRods("Form Rods", 149, 1);
	std::cout << formRods;

	std::cout << std::endl << "----Form with invalid grades----" << std::endl;
	try
	{
		// Form formGio("Form Gio", 151, 1);
		// Form formPaulo("Form Paulo", 0, 1);
	}
	catch (BureaucratGradeTooHighException &e)
	{
		std::cerr << "Form::" << e.what() << std::endl;
	}
	catch (BureaucratGradeTooLowException &e)
	{
		std::cerr << "Form::" << e.what() << std::endl;
	}



	std::cout << std::endl << "----Invalid signing form----" << std::endl;
	try
	{
		formBea.beSigned(bea);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	bea.signForm(formBea);



	std::cout << std::endl << "----Valid signing form----" << std::endl;
	rods.signForm(formBea);
	try
	{
		formRods.beSigned(rods);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	rods.incrementGrade();
	rods.signForm(formBea);
	rods.signForm(formBea);


	return 0;
}
