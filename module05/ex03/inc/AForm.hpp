#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;

	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm& copy);
		AForm& operator=(AForm& other);
		~AForm();

		void			execute(Bureaucrat const & executor) const;
		void			beSigned(class Bureaucrat& bureaucrat);

		std::string		getName() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		bool			getIsSigned() const;

	protected:
		virtual void	action() const = 0;
};

std::ostream& operator<<(std::ostream &o, AForm const& form);

#endif