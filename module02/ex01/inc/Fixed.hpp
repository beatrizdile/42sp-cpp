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
		float toFloat(void) const;
		float toInt(void) const;
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& os, const Fixed& other);

#endif