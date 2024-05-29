#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog& copy) : Animal(copy){
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(Dog& other){
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(){
	std::cout << "Woof Woof" << std::endl;
}
