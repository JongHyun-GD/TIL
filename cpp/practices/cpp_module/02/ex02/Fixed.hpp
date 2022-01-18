#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed(const int value);
		Fixed(const float value);
		bool operator< (Fixed const &other);
		bool operator<= (Fixed const &other);
		bool operator> (Fixed const &other);
		bool operator>= (Fixed const &other);
		bool operator== (Fixed const &other);
		bool operator!= (Fixed const &other);
		Fixed& operator= (const Fixed &source);
		Fixed operator+ (Fixed const &other);
		Fixed operator- (Fixed const &other);
		Fixed operator* (Fixed const &other);
		Fixed operator/ (Fixed const &other);
		Fixed operator++ ();
		Fixed operator++ (int);
		Fixed operator-- ();
		Fixed operator-- (int);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);

	private:
		int rawBits;
		static const int frac = 8;
};

std::ostream& operator <<(std::ostream&, const Fixed&);

#endif
