#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type){
	std::cout << "Animal constructor called" << std::endl;
};

Animal::Animal(Animal& copy){
	std::cout << "Animal copy constructor called" << std::endl;
	setType(copy.getType());
};

Animal& Animal::operator=(Animal& other){
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other){
		setType(other.getType());
	}
	return *this;
};

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType(){
	return type;
};

void Animal::setType(std::string type){
	this->type = type;
};
