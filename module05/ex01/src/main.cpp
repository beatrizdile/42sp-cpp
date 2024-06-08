#include "Bureaucrat.hpp"

int main(void) 
{
	Bureaucrat rods("Rodrigo", 1);
	std::cout << rods << std::endl;

	Bureaucrat bea("Beatriz", 150);
	std::cout << bea << std::endl;

	Bureaucrat gi("Giovana", 151);
	Bureaucrat paulo("Paulo", 0);

	rods.incrementGrade();
	bea.decrementGrade();

	return 0;
}
