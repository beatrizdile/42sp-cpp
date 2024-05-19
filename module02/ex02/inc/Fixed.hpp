#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int num);
		Fixed(const float num);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		// comparison operators
		bool operator>(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);

		// arithmetic operators
		float operator+(const Fixed& other);
		float operator-(const Fixed& other);
		float operator*(const Fixed& other);
		float operator/(const Fixed& other);

		// increment/decrement
		Fixed& operator++();
		Fixed operator++(int dummy);
		Fixed& operator--();
		Fixed operator--(int dummy);

		// methods
		float toFloat(void) const;
		float toInt(void) const;

		// getters & setters
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

// ostream cout
std::ostream& operator<<(std::ostream& os, const Fixed& other);


#endif