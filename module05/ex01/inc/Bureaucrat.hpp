#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const 	_name;
		int 				_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat& copy);
		Bureaucrat& operator=(Bureaucrat& other);
		~Bureaucrat();

		static void 		checkBureaucratGradeException(int grade);
		void 				signForm(class Form& form);
	
		std::string const 	getName() const;
		int 				getGrade() const;
		void 				incrementGrade();
		void 				decrementGrade();
};

std::ostream& operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif