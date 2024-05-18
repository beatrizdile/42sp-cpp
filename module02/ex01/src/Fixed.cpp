#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
};

Fixed& Fixed::operator=(Fixed& other){
	std::cout << "Copy assignment operator called " << std::endl;
	if (this != &other){
		this->value = other.getRawBits();
	}
	return *this;
};

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
};

void Fixed::setRawBits(int const raw){
	this->value = raw;
};
