#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(Dog& copy) : Animal(copy){
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*copy.brain);
}

Dog& Dog::operator=(Dog& other){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
	if (brain)
		delete brain;
}

void Dog::makeSound() const{
	std::cout << "Woof Woof" << std::endl;
}

Brain*	Dog::getBrain() const{
	return brain;
}

void Dog::setBrain(Brain* brain){
	if (brain != this->brain)
	{
		if (this->brain)
			delete this->brain;
		this->brain = brain;
	}
}
