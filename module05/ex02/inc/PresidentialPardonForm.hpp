#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"
class PresidentialPardonForm: public AForm
{
	private:
		static const unsigned char gradeToSign = 25;
		static const unsigned char gradeToExecute = 5;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;
		void action() const;
};

#endif