#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat default constructor called" << std::endl;
	setType("Cat");
}

Cat::Cat(std::string type) : Animal(type){
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(Cat& copy) : Animal(copy){
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(Cat& other){
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other){
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(){
	std::cout << "Meow Meow" << std::endl;
}
