#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat default constructor called" << std::endl;
	brain = new Brain();
}

Cat::Cat(Cat& copy) : Animal(copy){
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

Cat& Cat::operator=(Cat& other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
	if (brain)
		delete brain;
}

void Cat::makeSound() const{
	std::cout << "Meow Meow" << std::endl;
}

Brain*	Cat::getBrain() const{
	return brain;
}

void Cat::setBrain(Brain* brain){
	if (brain != this->brain)
	{
		if (this->brain)
			delete this->brain;
		this->brain = brain;
	}
}
