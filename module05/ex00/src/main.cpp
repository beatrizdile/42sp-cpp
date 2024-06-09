#include "Bureaucrat.hpp"
#include "BureaucratGradeTooHighException.hpp"
#include "BureaucratGradeTooLowException.hpp"

int main(void) 
{
	std::cout << "----Bureaucrat with valid grades----" << std::endl;
	Bureaucrat rods("Rodrigo", 1);
	std::cout << rods << std::endl;
	Bureaucrat bea("Beatriz", 150);
	std::cout << bea << std::endl;


	std::cout << std::endl << "----Bureaucrat with grades too high & too low----" << std::endl;
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
	std::cout << "Bureaucrat bea copy constructor: " << std::endl << copyBea << std::endl;
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

	return 0;
}
