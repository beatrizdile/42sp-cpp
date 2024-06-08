#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const 	_name;
		int 				_grade;
	public:
		Bureaucrat(std::string const name, int grade);
		~Bureaucrat();
		std::string const 	getName() const;
		int 				getGrade() const;
		void 				incrementGrade();
		void 				decrementGrade();
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif