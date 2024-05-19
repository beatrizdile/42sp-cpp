#include "Fixed.hpp"

// Orthodox Canonical Form
// default constructor
Fixed::Fixed() : value(0) {}

// default copy constructor
Fixed::Fixed(const Fixed& copy){
	*this = copy;
};

// int constructor
Fixed::Fixed(const int num) : value(num << fractionalBits){};

// float constructor
Fixed::Fixed(const float num) : value(roundf(num * (1 << fractionalBits))){};

// copy assignment operator
Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other){
		this->value = other.getRawBits();
	}
	return *this;
};

// destructor
Fixed::~Fixed() {}



// Methods
float Fixed::toFloat(void) const{
	return ((float)value / (float)(1 << fractionalBits));
};

float Fixed::toInt(void) const{
	return (value >> fractionalBits);
};

int	Fixed::getRawBits(void) const{
	return this->value;
};

void Fixed::setRawBits(int const raw){
	this->value = raw;
};



// Overloads
std::ostream& operator<<(std::ostream& os, const Fixed& other){
	os << other.toFloat();
	return os;
};

// comparison operators
bool Fixed::operator>(const Fixed& other){
	return (this->toFloat() > other.toFloat());
};

bool Fixed::operator<(const Fixed& other){
	return (this->toFloat() < other.toFloat());
};

bool Fixed::operator>=(const Fixed& other){
	return (this->toFloat() >= other.toFloat());
};

bool Fixed::operator<=(const Fixed& other){
	return (this->toFloat() <= other.toFloat());
};

bool Fixed::operator==(const Fixed& other){
	return (this->toFloat() == other.toFloat());
};

bool Fixed::operator!=(const Fixed& other){
	return (this->toFloat() != other.toFloat());
};

// arithmetic operators
float Fixed::operator+(const Fixed& other){
	return (this->toFloat() + other.toFloat());
};

float Fixed::operator-(const Fixed& other){
	return (this->toFloat() - other.toFloat());
};

float Fixed::operator*(const Fixed& other){
	return (this->toFloat() * other.toFloat());
};

float Fixed::operator/(const Fixed& other){
	return (this->toFloat() / other.toFloat());
};

// increment/decrement operators
Fixed& Fixed::operator++(){
	++this->value;
	return *this;
};

Fixed Fixed::operator++(int dummy){
	(void) dummy;
	Fixed tmp = *this;
	++this->value;
	return tmp;
};

Fixed& Fixed::operator--(){
	--this->value;
	return *this;
};

Fixed Fixed::operator--(int dummy){
	(void) dummy;
	Fixed tmp = *this;
	--this->value;
	return tmp;
};

// min & max
Fixed& Fixed::min(Fixed& first, Fixed& second){
	return first.toFloat() > second.toFloat() ? second : first;
};

Fixed& Fixed::min(const Fixed& first, const Fixed& second){
	return first.toFloat() > second.toFloat() ? (Fixed&)second : (Fixed&)first;
};

Fixed& Fixed::max(Fixed& first, Fixed& second){
	return first.toFloat() < second.toFloat() ? second : first;
};

Fixed& Fixed::max(const Fixed& first, const Fixed& second){
	return first.toFloat() < second.toFloat() ? (Fixed&)second : (Fixed&)first;
};
