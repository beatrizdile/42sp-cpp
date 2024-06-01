#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type){
	std::cout << "WrongAnimal constructor called" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal& copy){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	setType(copy.getType());
};

WrongAnimal& WrongAnimal::operator=(WrongAnimal& other){
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other){
		setType(other.getType());
	}
	return *this;
};

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal sound" << std::endl;
};

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
	return type;
};

void WrongAnimal::setType(std::string type){
	this->type = type;
};
