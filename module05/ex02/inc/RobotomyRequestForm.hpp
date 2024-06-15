#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"

#define ROBOTOMYREQUEST_GRADE_TO_SIGN 72
#define ROBOTOMYREQUEST_GRADE_TO_EXEC 45

class RobotomyRequestForm : public AForm
{
	private:
		std::string		_target;
		bool			robotomySuccess() const;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(RobotomyRequestForm& other);
		~RobotomyRequestForm();

	protected:
		void action() const;
};

#endif