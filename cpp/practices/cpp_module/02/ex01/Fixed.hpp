#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& operator= (const Fixed &source);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int rawBits;
		static const int frac = 8;
		void print_float_bit(float f);
};

std::ostream& operator <<(std::ostream&, const Fixed&);

#endif
