#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;
	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form& copy);
		Form& operator=(Form& other);
		~Form();

		void			beSigned(class Bureaucrat& bureaucrat);
		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		bool			getIsSigned() const;
};

std::ostream& operator<<(std::ostream &o, Form const& form);

#endif