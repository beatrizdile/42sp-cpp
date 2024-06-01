#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain& copy);
		Brain& operator=(Brain& other);
		~Brain();

		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
	private:
		std::string	ideas[100];
};

#endif