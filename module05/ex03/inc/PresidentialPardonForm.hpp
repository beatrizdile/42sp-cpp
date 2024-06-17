#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

#define PRESIDENTIALPARDON_GRADE_TO_SIGN 25
#define PRESIDENTIALPARDON_GRADE_TO_EXEC 5

class PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(PresidentialPardonForm& other);
		~PresidentialPardonForm();

	protected:
		void action() const;
};

#endif