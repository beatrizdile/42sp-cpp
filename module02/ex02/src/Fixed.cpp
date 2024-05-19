#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : value(0) {}

// Default copy constructor
Fixed::Fixed(const Fixed& copy){
	*this = copy;
};

// Int constructor
Fixed::Fixed(const int num) : value(num << fractionalBits){};

// Float constructor
Fixed::Fixed(const float num) : value(roundf(num * (1 << fractionalBits))){};

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other){
		this->value = other.getRawBits();
	}
	return *this;
};

// Destructor
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
