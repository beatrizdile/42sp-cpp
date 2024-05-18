#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy){
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
};

Fixed::Fixed(const int num) : value(num << fractionalBits){
	std::cout << "Int constructor called" << std::endl;
};

Fixed::Fixed(const float num) : value(roundf(num * (1 << fractionalBits))){
	std::cout << "Float constructor called" << std::endl;
};

std::ostream& operator<<(std::ostream& os, const Fixed& other){
	os << other.toFloat();
	return os;
};

float Fixed::toFloat(void) const{
	return ((float)value / (float)(1 << fractionalBits));
};

float Fixed::toInt(void) const{
	return (value >> fractionalBits);
};

Fixed& Fixed::operator=(const Fixed& other){
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
	return this->value;
};

void Fixed::setRawBits(int const raw){
	this->value = raw;
};
