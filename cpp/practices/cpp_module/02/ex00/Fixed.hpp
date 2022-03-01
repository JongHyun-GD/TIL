#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed& operator= (const Fixed &source);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int rawBits;
		static const int frac = 8;
};

#endif
